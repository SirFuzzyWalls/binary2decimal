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
        bool invalidEntry = 0;
        do
        {
            for (int i = 0; i < inBinary.length(); i++) {
                if (inBinary[i] != '1' && inBinary[i] != '0') {
                    invalidEntry = 1;
                }
            }
            if (invalidEntry == 1) {
                std::cout << "Error: Invalid digit found in string of binary digits, \nplease re-enter up to 8 binary digits: ";
                std::cin.clear();
                std::cin.ignore(200, '\n');
                std::cin >> inBinary;
            }
            
        } while (invalidEntry != 0);

        decimal = convertToDecimal(inBinary); 

        std::cout << "\nYou entered: " << inBinary << std::endl;
        std::cout << "In decimal form that is: " << decimal << std::endl;
        std::cout << "Would you like to enter another binary number? (y for yes, n for no): ";
        std::cin >> choice;
        
    }

}
/*
Takes the incomming string and converts it to a decimal value, stored as an int, then returns said value.
Pre: Incomming string has already been validated and does not confirm any digits other than a 1 or a 0, IE 
     it's actually a binary number. 
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
