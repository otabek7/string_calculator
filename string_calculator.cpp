#include <iostream>
#include <string>
#include "./string_calculator.h"
#include<sstream>


using std::cout, std::endl;
using std::string;
using std::stringstream;

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
    if(decimal >9){
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
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);
    string temp;
    string str1;
    string str2;
    bool negTrigger = false;
    if(lhs[0] == '-' && rhs[0] == '-'){
        negTrigger = true;
        lhs = lhs.substr(1,lhs.length());
        rhs = rhs.substr(1,rhs.length());
    }
    for (int i = lhs.length()-1; i >=0; i--)
    {
        str1.push_back(lhs.at(i));
    }
    
    for (int i = rhs.length()-1; i >=0; i--)
    {
        str2.push_back(rhs.at(i));
    }

    
    
    if (str1.length() > str2.length())
    {
        temp = str1;
        str1 = str2;
        str2 = temp;
    }
 
    string result = ""; 
    int carry = 0;
    for (unsigned int i=0; i < str1.length(); i++)
    {
        int sum = ((str1[i]-'0') + (str2[i]-'0') + carry);
        carry = sum/10;
        result.push_back(sum%10 + '0');
    }
 
    for (unsigned int i = str1.length(); i < str2.length(); i++)
    {
        int sum = ((str2[i]-'0') + carry);
        result.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry>0)
        result.push_back(carry+'0');
 

    string temp2;
    for (int i = result.length()-1; i >=0; i--)
    {
        temp2.push_back(result.at(i));
    }
    if(negTrigger == true)
        temp2.insert(0, "-");
    return temp2;
}

string multiply(string lhs, string rhs) {
    string str2 = lhs;
    string str1 = rhs;
    bool prodSign = false;
    string str;
    
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);
            //put a counter to add the zeros on to the next row of digits depending on how many digits have been added
            //put a plus after each inside for loop has been done, remove the last plus when the whole thing finishes
            //make a loop that reverses the whole string
            //make a loop that adds each number everytime a '+' is hit
    int rightLen = rhs.length()-1;
    int leftLen = lhs.length()-1;

    /*
    for (int i = str1.length()-1; i >= 0; i--)
    {
        for (int j = str2.length()-1; j >= 0; j--)
        {
            int product = (((str1[i]-'0') * (str2[j]-'0'))%10 + carry);
            carry = ((str1[i]-'0') * (str2[j]-'0'))/10;
            temp2.push_back(product + '0');
            
        }
        counter++;
        if(str1.length() != 1){
            temp2.push_back('+');
            for (int i = 0; i < counter; i++)
            {            
                temp2.push_back('0');
            }
        }
    */
    if(rhs.find(char(45)) == 0 && lhs.find(char(45)) == 0){
        str1 = rhs.substr(1, rightLen);
        str2 = lhs.substr(1, leftLen);
    }
    if(rhs.find(char(45)) == 0){
        prodSign = true;
        str1 = rhs.substr(1, rightLen);
    
    }
    if(lhs.find(char(45)) == 0){
        prodSign = true;
        str2 = lhs.substr(1, leftLen);
    }
    string tempString;
    string tempString2;
    int carry = 0;
    unsigned int temp;
    unsigned int multOut = str1.length();
    unsigned int multIn = str2.length();
    if(str2.length() < str1.length()){
        temp = str1.length();
        multOut = str2.length();
        multIn = temp;
    }
    
    if(str2.length() > 3 && str1.length() > 3)
    {
        for(unsigned int i = 0; i < multIn; i++)
        {
            unsigned int left = 0;
            unsigned int rite = 0;
            int multier = multIn-i;
            
            if(multOut == str1.length())
            {

                rite = digit_to_decimal(str1.at(multOut-1)); 
                left = digit_to_decimal(str2.at(multier-1));
            }
            if(multOut == str2.length())
            {
                rite = digit_to_decimal(str1.at(multier-1));
                left = digit_to_decimal(str2.at(multOut-1));

            }
            unsigned int product = (left*rite) + carry;
            if(product > 9)
            {
                carry = product/10;
                str += decimal_to_digit(product%10);
            }
            else
            {
                carry = 0;
                str += decimal_to_digit(product) ;
            }
        }
        if(carry > 0)
        {
            str += decimal_to_digit(carry) ;
        }
        for(unsigned int n = 0; n < str.length(); n++)
        {
            int strN = str.length() -n;
            tempString += str.at(strN-1);
        }
        carry = 0;
        for(unsigned int i = 1; i < multOut; i++)
        {
            string str;
            string tempString2;
            for(unsigned int j = 0; j < multIn; j++)
            {
                unsigned int multi = multIn -j;
                unsigned int multo = multOut -i;

                unsigned int left = 0;
                unsigned int rite = 0;
                if(multOut == str2.length())
                {
                    left = digit_to_decimal(str2.at(multo-1));
                    rite = digit_to_decimal(str1.at(multi-1));
                }
                else if(multOut == str1.length())
                {
                    left = digit_to_decimal(str2.at(multi-1));
                    rite = digit_to_decimal(str1.at(multo-1)); 
                }

                int product = (left*rite) + carry;
                if(product > 9)
                {
                    str +=decimal_to_digit (product%10) ;

                    carry = product/10;
                }
                if(product <= 9)
                {
                    carry = 0;
                    str += decimal_to_digit(product) ;
                }
            }
            if(carry > 0){
                str += decimal_to_digit(carry);
                carry = 0;
            }
            for(unsigned int inner = 0; inner < i; inner++)
            {
                str.insert(0, "0");
            }
            for(unsigned int outer = 0; outer < str.length(); outer++)
            {
                int strN = str.length()-outer;
                tempString2 += str.at(strN-1);
            }
            tempString = add(tempString, tempString2);
        }
        if(prodSign == true)
        {
            tempString.insert(0, "-");
        }
        return tempString;
    }
    else
    {
     stringstream stringstr;

     int left = stoi(lhs);
     int rite = stoi(rhs);
     int product = left*rite;

     stringstr << product;
     str = stringstr.str();
    }
    return str;
}




/*
    if (str1.length() > str2.length())
    {
        temp = str1;
        str1 = str2;
        str2 = temp;
    }

    int carry = 0;
    string temp2;
    int productRes;
    int counter = 0;

    
        

    }*/
