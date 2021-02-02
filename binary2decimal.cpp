/*
A simple console app started by Simon McGraw on 2/1/21.
The goal of this program is to allow a user to enter a value in binary, and have it 
converted and output to the console as a decimal value. 
*/

#include <iostream>
#include <string>
#include <cmath>

int convertToDecimal(const std::string inString);

int main()
{
    char choice = 'y'; 

    while (choice != 'n') {
        int decimal = 0; 
        std::string inBinary;
        std::cout << "Please enter up to 8 binary digits now: ";
        std::cin >> inBinary;

        //very basic input validation
        std::cin.ignore(200, '\n'); 
        decimal = convertToDecimal(inBinary); 
        std::cout << "\nYou entered: " << inBinary << std::endl;
        std::cout << "In decimal form that is: " << decimal << std::endl;
        std::cout << "Would you like to enter another binary number? (y for yes, n for no): ";
        std::cin >> choice;
    }

}
/*
Takes the incomming string and converts it to a decimal value, stored as an int, then returns said value.
*/
int convertToDecimal(const std::string inString)
{
    int bLength = inString.length();
    int decimal = 0;
    for (int i = 0; i < bLength; i++) {
        if (inString[bLength - (i + 1)] != '0') {
            decimal += pow(2, i);
        }
    }
    return decimal;
}
