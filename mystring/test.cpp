#include "String.h"
#include <iostream>
#define string String

using namespace std;

int main()
{
    string str("abcdfeg");                 //substring initializes
    string str1("lliam Sm");
    String mystring("William Smith");        //string initializes
    string temp(mystring);                  //initializes temporary string to hold the original value of string object
    int x;          //position in the string
    int n;          //number of copies
    char x1;        //single character from string

    cout << "----------------Testing 'swap' function---------------" << endl;
    cout << "-> Swaps the contents of mystring with str" << endl;
    cout << "Your string is : " << mystring << endl;
    cout << "Your str is : " << str << endl;
    mystring.swap(str);
    cout << "After swap" << endl;
    cout << "Your string is : " << mystring << endl;
    cout << "Your str is : " << str << endl;
    mystring = temp;        //reset mystring
    return 0;
}