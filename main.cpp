#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    
    cout << ">> ";
    string messyInput;
    string userInput1;
    string userInput2;
    

    getline(cin, messyInput);
    cout << endl;
    while(messyInput != "q" || messyInput != "quit"){
    int firstSpace = 0;
    int secondSpace = 0;
        
    for (unsigned int i = 0; i < messyInput.length(); i++)
    {
        if(messyInput[i] == ' ' && firstSpace == secondSpace)
            firstSpace = i;
        else if(messyInput[i] == ' ' && firstSpace>secondSpace)
            secondSpace = i;
    }

    userInput1 = messyInput.substr(0, firstSpace);
    userInput2 = messyInput.substr(secondSpace+1, messyInput.length());
    cout << "ans =" << endl;
    cout << endl;
    if(messyInput.at((secondSpace-1)) == '+')
        cout << "    " << add(userInput1, userInput2) << endl;
    if(messyInput.at((secondSpace-1)) == '*')
        cout << "    " << multiply(userInput1, userInput2) << endl;
    cout << endl;
    cout << ">> ";

    getline(cin, messyInput);

    cout << endl;

    if(cin.eof() || messyInput == "q" || messyInput == "quit")
        break;
    }
    
    cout << "farvel!";

    // TODO(student): implement the UI
    
}

