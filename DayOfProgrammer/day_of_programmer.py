"""
// Level : Easy
// Exercise : Day of programmer
// Topic  : Algorithms-Implementation
// Author : RaulSosa
// Status : Solved
"""
def process_julian(year_from_julian):
    # Leap year
    if(year_from_julian % 4 == 0):
        return f"12.09.{year_from_julian}"
    # No leap year
    else:
        return f"13.09.{year_from_julian}"    

def process_gregorian(year_from_gregorian):
    # Leap year
    if((year_from_gregorian % 400 == 0) or ((year_from_gregorian % 4 == 0) and (year_from_gregorian % 100 != 0))):
        return f"12.09.{year_from_gregorian}"
    else:
        return f"13.09.{year_from_gregorian}"

def day_of_progammer(year):
    
    day = ""
    
    # Year from Julian Calendar
    if(year in [*range(1700,1918)]):
        day = process_julian(year)
    # Year from Gregorian Calendar
    elif(year in [*range(1919,2701)]):
        day = process_gregorian(year)
    # Year 1918 (years provided from [1700-2700] - constraint)
    else:
        day = f"26.09.1918"
    return day        

print(day_of_progammer(1800))