
//=============================================
// Anish Banswada
// Program - Takes a decimal number between 1 and
// 2022, converts it to a roman numeral and outputs to screen
//==============================================
#include <iostream>
#include <cstring>
using namespace std;
string convert(int year);
int main(void)
{
string result;
int num;
do 
{
cout << "Enter year 1 to 2022 (0 to quit): ";
cin >> num;
if (num > 0 & num <= 2022) //Checks if the input is valid
{
result = convert(num);
cout << result << endl;
}
else if (num != 0) // Executes if input isn’t 0 or between 0 & 
2022
{
    cout << "Invalid entry: Try again" << endl;
}
}
while (num); //Ends program if input is zero
return 0;
}
string convert(int year)
//================
// Function - convert()
// Description - converts the given decimal number to a roman numeral
// Parameters - ‘year’ as a valid decimal number between 0 & 2022
// Return value - a string named ‘roman_text’ that contains the decimal value
// in roman numerals
//==================
{
string roman_text;
int division[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
// list containing decimal numbers that have special symbols in Roman 
numerals
string roman_numerals[] = 
{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"}; //roman numeral 
characters corresponding to the decimal numbers above
int SIZE = 13;
for (int i = 0; i < SIZE; i ++) //loops through every character in list 
for the input number
{
if (year >= division[i])
{
int num = year/division[i];
for (int j = 0; j < num; j++)
{
roman_text = roman_text + roman_numerals[i]; //Adds the 
roman character/s to string depending on the quotient of year/division[i] 
}
year %= division[i]; //assigns remainder value to ‘year’ 
variable
}
}
return roman_text;
}
//===============================
// Values tested : -1, 
// 1,2,3,4,5,6,7,8,9,10,20,25,37,49,50,77,99,100,149,253,381,440,500,780, 
// 934, 1200, 1578,1786, 1989, 2022, 2021
// Values involving special cases (ex. 49, 50, 440, etc) and invalid cases (2022, -
// 1) and common // cases were tested
//================================
