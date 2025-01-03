# Level : Easy
# Author : RickySosa
# Status : Solved

def picking_numbers(array_numbers)
  subarray = []
  for i in 0..array_numbers.length-2 do
    for j in (i+1)..array_numbers.length-2 do
      if (array_numbers[i]-array_numbers[j]).abs <= 1
        unless subarray.include?(array_numbers[j])
          subarray.push(array_numbers[j])
        end
        unless subarray.include?(array_numbers[i])
          subarray.push(array_numbers[i])
        end
      end
    end
  end
  subarray
end

pp picking_numbers([4,6,5,3,3,1])
