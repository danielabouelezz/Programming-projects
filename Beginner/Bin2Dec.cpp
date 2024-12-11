#include <bits/stdc++.h> 

/*
    Bin2Dec allows the user to enter strings of up to 8 binary digits,
    0's and 1's, in any sequence and then displays its decimal equivalent.
 */


bool binaryDigitValidation(const char &binaryDigit)
{
    return (binaryDigit == '0') || (binaryDigit == '1');
}

void enterBinaryNumber(std::string& binaryNumber)
{ 
    std::cout << "Enter binary digits (up to 8): "; 
    std::string input; 
    std::getline(std::cin, input);  

    for(char digit : input)
    {
        if(binaryDigitValidation(digit))
        {
            binaryNumber += digit; 
        }

        if(binaryNumber.size() == 8)
            break; 
    }
}

int transformFromBinaryToDecimal(std::string &binarNumber)
{
    int decimalNumber{0}; 

    for(char digit : binarNumber)
    {
        decimalNumber = (decimalNumber << 1) | (digit - '0'); 
    }

    return decimalNumber; 
}

bool anotherConversion()
{
    char option; 
    std::cout<< "Do you want to do another converstion y/n: ";
    std::cin>> option; 
    while(option != 'y' && option != 'n' && option != 'Y' && option != 'N')
    {
        std::cout<< "The choice: " << option << " is invalid. Enter a valid choice:\n";
        std::cin >> option; 
    }

    return option == 'y' || option == 'Y';
}
int main()
{
    do
    {
        std::string binarNumber = ""; 

        enterBinaryNumber(binarNumber);
         
        int decimalNumber = transformFromBinaryToDecimal(binarNumber); 
        std::cout<< "Binary: " << binarNumber << " -> Decimal: " << decimalNumber << "\n"; 
        
    }while(anotherConversion());

    std::cout<< "Exiting program. Goodbye!\n"; 
}