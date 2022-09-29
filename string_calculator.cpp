#include <iostream>
#include <string>
#include "./string_calculator.h"
#include<sstream>

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    
    if(digit < '0' || digit > '9')
        throw std::invalid_argument("Invalid argument");

    else{
        int charInt = digit-'0';
        return charInt;
    }

}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    char charDec;
    if(decimal <0 || decimal >9){
        throw std::invalid_argument("Invalid Argument");
    }
    else{
        charDec = decimal + '0';
    }
    return charDec;
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    string target = "0";
    int counter = 0;
    bool trigger = false;
    if(num[0] == '-')
    {
        trigger = true;
        num.erase((num.find("-", 0)), 1);
    }
    int length = num.length();


    while(num[0] == '0' || num[0] == '-'){
        
        if(num[0] != '0')
            break;
        if(num[0] == '0' && counter == length-1)
            break;
        else
            num.erase((num.find(target, 0)), 1);
        counter++;
    }

    if(num[0] == '0' && counter == length-1){
        num = "0";
        return num;
    }

    if(trigger)
        num.insert(0, "-");

    return num;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    bool leftTrigger = false;
    bool rightTrigger = false;

    long long right = stol(rhs);
    long long left = stol(lhs);

    long long sum = right+left;

    string sumStr = std::to_string(sum); 

    return sumStr;
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
    // string left;
    // string right;
    // bool trigger = false;

    //  for (int i = 0; i < lhs.length(); i++)
    // {
    //     if(lhs[i] == '-'){
    //         trigger = true;
    //     }
    //     else
    //         left = lhs[i];
    // }

    
    // for (int i = 0; i < rhs.length(); i++)
    // {
    //     if(rhs[i] == '-'){
            
    //         trigger = true;
    //     }
    //     else{
    //         right = rhs[i];
    //     }
            
    // }
    // long intProd;

    // if(!trigger)
    // {
    //     intProd = (left - '0') * (right - '0');
    // }
    // else
    //     intProd = (left - '0') * (right - '0') * -1;
    
    // string product; 
    // product.push_back(intProd + '0'); 
    return "";
}
