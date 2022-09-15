// Level : Easy
// Exercise : TimeConversion.cpp
// Topic  : Algorithms
// Author : RaulSosa

#include <iostream>
#include <string>
using namespace std;

string timeConversion(string);

int main(void){

	string time1 = "07:50:40PM";
	string time2 = "12:40:00AM";

	cout << "time1 12-hour format : "<< time1 << endl;
	cout << "time1 24-hour format : "<< timeConversion(time1) << endl;
	cout << "time2 12-hour format : "<< time2 << endl;
	cout << "time2 24-hour format : "<< timeConversion(time2) << endl;


	return 0;

}

/* AM/PM format have 10 characters.
   s[8] tell us if is AM or PM
   s[0] and s[1] => hh hours
*/
string timeConversion(string s) {
    string timeConverted = s;

    // Case : 12:00:00AM
    if(s[8] == 'A' && s[0] == '1' && s[1] == '2'){
    	timeConverted[0] = '0';
    	timeConverted[1] = '0';
    	timeConverted.erase(8,9);
    }
    // Case : 12:00:00:PM
    else if(s[8] == 'P' && s[0] == '1' && s[1] == '2'){
    	timeConverted[0] = '1';
    	timeConverted[1] = '2';
    	timeConverted.erase(8,9);

    	// Case : XX:XX:XXAM
    }else if(s[8] == 'A'){
    	timeConverted = s.erase(8,9);
    }
    else if(s[8] == 'P'){
    	char h1 = s[0];
		char h2 = s[1];
		string h1s = to_string(h1-48);
		string h2s = to_string(h2-48);
		int h1h2Integer = stoi(h1s+h2s);
		string h1h2MilitaryFormat = to_string(h1h2Integer+12);
		timeConverted[0] = h1h2MilitaryFormat[0];
		timeConverted[1] = h1h2MilitaryFormat[1];
		timeConverted.erase(8,9);

    }
    return timeConverted;
}
