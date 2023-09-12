#include "String.h"
#include <iostream>

using namespace std;

/****************************************************************
* Default constructor.											*
* Assign null terminator to the String.							*
****************************************************************/
String::String()
{
	value = new char;
	*value = '\0';
}

/****************************************************************
* Constructor #2.												*
* Assign a constant array of character to the string.			*
*																*
* @param ch: pointer to the array of character.					*
****************************************************************/
String::String(const char *ch)
{
	int size = 0; //Size of the constant character array

	//get size of array ch
	while (*(ch + size) != '\0')
		size++;

	value = new char[size + 1];	//pointer to new String
	
	//Copy the array of character to the String.
	for (int i = 0; i < size; i++)
		*(value + i) = *(ch + i);
	//Add null terminator at the end of the String
	value[size] = '\0';
}

/****************************************************************
* Constructor #3.												*
* Assign a String to the original String.						*
*																*
* @param ch: other String.										*
****************************************************************/
String::String(const String& ch)
{
//	String temp(ch.value);
	value = new char[ch.length() + 1];	//pointer to new String

	//Copy the array of character to the String.
	for (int i = 0; i <= ch.length(); i++)
		*(value + i) = ch.value[i];
}

/****************************************************************
* Assign the character ch to the original String SIZE times.	*
*																*
* Perform bound check for SIZE.									*
*																*
* @param SIZE: number of times to copy the character to String.	*
* @param ch: a constant character.								*
****************************************************************/
String::String(const char ch, const int SIZE)
{
	//Input validation
	if (SIZE < 0)
	{
		cout << "Invalid amount of times!" << endl;
		exit(EXIT_FAILURE);
	}

	value = new char[SIZE + 1];	//Pointer to new char array

	//Assign ch to original String n times.
	for (int i = 0; i < SIZE; i++)
		value[i] = ch;
	value[SIZE] = '\0';
}

/****************************************************************
* Assign copies of a substring from str to the original String.	*
*																*
* Perform bound check for x and n.								*
*																*
* @param str: A String.											*
* @param x: beginning position of the sub string of str.		*
* @param n: number of characters of the sub string of str.		*
****************************************************************/
String::String(const String& str, const int START, const int SIZE)
{
	//Input validation
	if (SIZE > str.length() + 1 || START < 0 || SIZE + START > str.length())
	{
		if (SIZE > str.length() + 1)
			cout << "Substring's length is greater than the string's length.\n";
		if (START < 0)
			cout << "Invalid integer for possition.\n";
		if (SIZE + START > str.length())
			cout << "Substring exceed the string's length.\n";
		exit(EXIT_FAILURE);
	}

	value = new char[SIZE + 1]; //Pointer to new char array

	//Add n characters from position x of str to the original String
	for (int i = 0; i < SIZE; i++)
		value[i] = str.value[START + i];
	//Add null terminator at the end of the String
	value[SIZE] = '\0';
}


/****************************************************************
* @param x: postition of the returned character.				*
* @return The character at position x in the string.			*
****************************************************************/
char String::at(int x) const
{
	return value[x];
}

/****************************************************************
* @return The first character in the string.					*
****************************************************************/
char String::front() const
{
	char firstchar;
	firstchar = value[0];
	return firstchar;
}

/****************************************************************
* @return The last character in the string.						*
****************************************************************/
char String::back() const
{
	String myString = this->value;

	int lastchar;
	char* v = this->value;
	int len = 0;
	char ch;
	ch = v[0];

	while (ch != '\0')
	{
		ch = v[++len];
	}
	myString = value[len - 1];
	lastchar = value[len - 1];

	return lastchar;
}

/****************************************************************
* Converts the contents of mystring to a C - string.			*
*																*
* Add the '\0' at the end of the C - string.					*
* @return A pointer to the C - string.							*
****************************************************************/
char* String::c_str() const
{
	// myString is an object
	int len = length();
	String myString = this->value;

	char* newvalue = new char[length() + 1];

	//Copy 
	for (int i = 0; i < length(); i++)
		newvalue[i] = value[i];

	//Add null 
	newvalue[length()] = '\0';

	return newvalue;
}

/****************************************************************
* @return true if mystring is empty.							*
****************************************************************/
bool String::empty() const
{
	return false;
}

/****************************************************************
* @return The size of the storage allocated for the string.		*
****************************************************************/
int String::capacity() const
{
	if (value == nullptr) return 0;
	return sizeof(char) * (length() + 1);
}

/****************************************************************
* @return the size of the String.								*
****************************************************************/
int String::length() const
{
	int i = 0;
	//get size
	while (value[i] != '\0')
		i++;
	return i;
}

/****************************************************************
* @return the size of the String.								*
****************************************************************/
int String::size() const
{
	int i = 0;
	//get size
	while (*(value + i) != '\0')
		i++;
	return i;
}

/****************************************************************
* Swaps the contents of the String with str.					*
*																*
* @param str: the other String to swap							*
****************************************************************/
void String::swap(String str)
{
	char* c(str.value);

	str = value;
	value = c;
}

/****************************************************************
* Copies the character array str to String.						*
*																*
* Perform bound check for x and n.								*
*																*
* @param str: the copy string.									*
* @param x: beginning position to copy.							*
* @param n: number of characters to copy to str.				*
****************************************************************/
void String::copy(String str, int x, int n)
{
}

/****************************************************************
* Returns a copy of a substring.								*
*																*
* Perform bound check for x and n.								*
*																*
* @param x: beginning position to copy.							*
* @param n: number of characters to copy to new char array.		*
* @return Pointer to the copy char array of String.				*
****************************************************************/
String String::substr(int x, int n) const
{
	return String();
}

/****************************************************************
* Erases n characters from String.								*
*																*
* Perform bound check for x and n.								*
*																*
* @param x: beginning position to erase.						*
* @param n: number of characters to earase from String.			*
****************************************************************/
void String::erase(int x, int n)
{
}

/****************************************************************
* Check if String is palindromic.								*
*																*
* @return true if the string is palindromic, and false otherwise*
****************************************************************/
bool String::palindrome() const
{
	return false;
}

/****************************************************************
* Check if a sub String of String is palindromic.				*
*																*
* Perform bound check for x and n.								*
*																*
* @param x: beginning position of the sub String.				*
* @param n: number of characters in the sub String.				*
* @return true if the sub String is palindromic, and false		*
* otherwise.													*
****************************************************************/
bool String::palindrome(int x, int n) const
{
	return false;
}

/****************************************************************
*Reverses the String.											*
*																*
* Flip the string backward and the order of which character is	*
* uppercase and which character is lowercase letters stay the	*
* same.															*
****************************************************************/
String String::reverse()
{
	// myString is an object
	int len = myLength();
	String myString = this->value;
	//delete[]value;
	char ch;

	myString.value[0] = tolower(myString.value[0]); // tolower function is char not string so it is allowed to be used 

	for (int i = 0; i < len / 2; i++)
	{
		if (myString.value[i] == '\0')
			break;

		ch = myString.value[i];
		myString.value[i] = myString.value[len - 1 - i];
		myString.value[len - 1 - i] = ch;
	}
	myString.value[0] = toupper(myString.value[0]);


	// after reversing the string, get the length, check the first letter (if first letter is upper then turn it to lower and 
	// or if first letter is lower is turn it to upper) so there will be two implemented functions
	return myString;
}


/****************************************************************
* Removes all character x from the original String.				*
*																*
* @param x: the character to be removed from the String.		*
****************************************************************/
void String::projection(char x)
{
	String temp = value;

	String str;
	str.value[0] = c;

	if (isSubstr(temp, str))
	{
		String test;
		char* result = new char[temp.myLength() + 1];
		int index = 0;

		for (int i = 0; i < temp.myLength(); i++)
		{
			if (i < temp.myLength() - str.myLength() + 1)
			{
				test.assign(temp, i, str.myLength()); // copy part of from the begining with the length of the str to test 
				if (test == str) //check if the test = the passed str
					i = i + str.myLength() - 1; // if found, change i to the end of the found test in the temp
				else result[index++] = temp.value[i];
			}
			else result[index++] = temp.value[i];
		}
		//add null terminater at the end of result
		result[index] = '\0';

		//Reset and return
		delete[] value;
		value = result;
		result = nullptr;
		return value;
	}

	//if not sub string return original value
	return value;
}

/****************************************************************
* This function gets the length of string and it                *
*  returns the length value.			                     	*
****************************************************************/
int String::myLength()
{
	char* v = this->value;
	int len = 0;
	char ch;
	ch = v[0];

	while (ch != '\0')
	{
		ch = v[++len];
	}
	return len;
}

/****************************************************************
* Removes all String str from the original String.				*
*																*
* @param str: the String to be removed from the original String.*
****************************************************************/
String String::projection(String str)
{
	String temp = value;

	if (isSubstr(temp, str))
	{
		String test;
		char* result = new char[temp.length() + 1];
		int index = 0;

		for (int i = 0; i < temp.length(); i++)
		{
			if (i < temp.length() - str.length() + 1)
			{
				test.assign(temp, i, str.length());
				if (test == str) i = i + str.length() - 1;
				else result[index++] = temp.value[i];
			}
			else result[index++] = temp.value[i];
		}
		//add null terminater at the end of result
		result[index] = '\0';

		//Reset and return
		delete[] value;
		value = result;
		result = nullptr;
		return value;
	}

	//if not sub string return original value
	return value;
}

void String::print() const
{
	cout << value;
}

/****************************************************************
* Appends n copies of a constant character to the String.		*
*																*
* @param n: number of time the constant characters copied.		*
* @param ch: pointer to the constant character to copy.			*
****************************************************************/
void String::append(int n, const char* ch)
{
	//Input validation
	if (n < 0)
	{
		cout << "First parameter cannot be negative.\n";
		exit(EXIT_FAILURE);
	}

	char* newVal = new char[length()+ n + 1];	//Pointer to new string

	//Copy data of value to newVal
	for (int i = 0; i < length(); i++)
		newVal[i] = value[i];
	//Add ch character n times
	for (int i = length(); i < length() + n; i++)
		newVal[i] = *ch;
	//Add null terminator at the end of new Val
	newVal[length() + n] = '\0';
	
	//Reset and return
	delete[] value;
	value = newVal;
	

	//return value;
}

/****************************************************************
* Appends n copies of a constant character to the String.		*
*																*
* @param n: number of time the constant characters copied.		*
* @param ch: the constant character to copy.					*
****************************************************************/
void String::append(int n, const char ch)
{
	//Input validation
	if (n < 0)
	{
		cout << "First parameter cannot be negative.\n";
		exit(EXIT_FAILURE);
	}

	char* newVal = new char[length() + n + 1];	//Pointer to new string

	//Copy data of value to newVal
	for (int i = 0; i < length(); i++)
		newVal[i] = value[i];
	//Add ch character n times
	for (int i = length(); i < length() + n; i++)
		newVal[i] = ch;
	//Add null terminator at the end of new Val
	newVal[length() + n] = '\0';

	//Reset and return
	delete[] value;
	value = newVal;

}
/****************************************************************
* Appends a constant string to the original String.				*
*																*
* @param s: the String to copy.									*
****************************************************************/
void String::append(const char* s)
{
	String str(s);	//Convert str to String
	char* newVal = new char[length() + str.length() + 1];	//Pointer to new string

	//Copy data of value to newVal
	for (int i = 0; i < length(); i++)
		newVal[i] = value[i];
	//Add str to newVal
	for (int i = length(); i < length() + str.length(); i++)
		newVal[i] = str.value[i - length()];
	//Add null terminator at the end of new Val
	newVal[length() + str.length()] = '\0';

	//Reset and return to the original string
	delete[] value;
	value = newVal;
	
}

/****************************************************************
* Add a constant character to the String.						*
*																*
* @param ch: the constant character to add.						*
****************************************************************/
/*String String::append(const char ch)
{
	char* newVal = new char[length()+ 1];	//Pointer to new string

	//Copy data of value to newVal
	for (int i = 0; i < length(); i++)
		newVal[i] = value[i];
	//Add ch to newVal
	newVal[length()] = ch;
	//Add null terminator at the end of new Val
	newVal[length() + 1] = '\0';

	//Reset and return to the original string
	delete[] value;
	value = newVal;
	
	return value;
}*/

/****************************************************************
* Add a String to the original String.							*
*																*
* @param str: the String to add.								*
****************************************************************/
void String::append(const String& str)
{
	char* newVal = new char[length() + str.length() + 1];	//Pointer to new string

	//Copy data of value to newVal
	for (int i = 0; i < length(); i++)
		newVal[i] = value[i];
	//Add str to newVal
	for (int i = length(); i < length() + str.length(); i++)
		newVal[i] = str.value[i - length()];
	//Add null terminator at the end of new Val
	newVal[length() + str.length()] = '\0';

	//Reset and return to the original string
	delete[] value;
	value = newVal;
	//
	//return value;
}

/****************************************************************
* Add a copies of n character from String str to the original 	*
* String.														*
*																*
* Perform bound check for n.									*
*																*
* @param str: A String.											*
* @param n: number of characters to copy from str.				*
****************************************************************/
void String::append(const String& str, int n)
{
	//Input validation
	if (n > str.length()+1)
	{
		cout << "There are less than " << n << " characters in the string.\n";
		exit(EXIT_FAILURE);
	}

	char* newVal = new char[length() + n + 1];	//Pointer to new string

	//Copy data of value to newVal
	for (int i = 0; i < length(); i++)
		newVal[i] = value[i];
	cout << str.length() << endl;
	//Add n characters from str to newVal
	for (int i = length(); i < length() + n; i++)
		newVal[i] = str.value[i - length()];
	//Add null terminator at the end of new Val
	newVal[length() + n] = '\0';

	//Reset and return
	delete[] value;
	value = newVal;
}

/****************************************************************
* Add a copies of n character from constant character of array s*
* to the String.												*
*																*
* Perform bound check for n.									*
*																*
* @param s: pointer to a char array.							*
* @param n: number of characters to copy from str.				*
****************************************************************/
void String::append(const char* s, int n)
{
	String str = s;

	if (n > str.length() + 1)
	{
		cout << "There are less than " << n << " characters in the string.\n";
		exit(EXIT_FAILURE);
	}

	char* newVal = new char[length() + n + 1];	//Pointer to new string

	//Copy data of value to newVal
	for (int i = 0; i < length(); i++)
		newVal[i] = value[i];
	//Add n characters from str to newVal
	for (int i = length(); i < length() + n; i++)
		newVal[i] = str.value[i - length()];
	//Add null terminator at the end of new Val
	newVal[length() + n] = '\0';

	//Reset and return
	delete[] value;
	value = newVal;
	
}

/****************************************************************
* Add a copies of a substring from str to the original String.	*
*																*
* Perform bound check for x and n.								*
*																*
* @param str: A String.											*
* @param x: beginning position of the sub string of str.		*
* @param n: number of characters of the sub string of str.		*
****************************************************************/
void String::append(const String& str, int x, int n)
{
	//Input validation
	if (n > str.length() + 1 || x < 0 || n + x > str.length())
	{
		if (n > str.length() + 1)
			cout << "Substring's length is greater than the string's length.\n";
		if (x < 0)
			cout << "Invalid integer for possition.\n";
		if (n + x > str.length())
			cout << "Substring exceed the string's length.\n";
		exit(EXIT_FAILURE);
	}

	char* newVal = new char[length() + n + 1];	//Pointer to new string

	//Copy data of value to newVal
	for (int i = 0; i < length(); i++)
		newVal[i] = value[i];
	//Add n characters from position x of str to newVal
	for (int i = length(); i < length() + n; i++)
		newVal[i] = str.value[i - length() + x];
	//Add null terminator at the end of new Val
	newVal[length() + n] = '\0';

	//Reset and return
	delete[] value;
	value = newVal;
}

/****************************************************************
* Assign ch to the original String n times.						*
*																*
* Perform bound check for n.									*
*																*
* @param n: number of times to copy the character to String.	*
* @param ch: a constant character.								*
****************************************************************/
String String::assign(int n, const char ch)
{
	//Input validation
	if (n < 0)
	{
		cout << "Invalid amount of times!" << endl;
		exit(EXIT_FAILURE);
	}

	//Reset original string
	delete[] value;
	value = nullptr;
	
	value = new char[n + 1];	//Pointer to new char array

	//Assign ch to original String n times.
	for (int i = 0; i < n; i++)
		value[i] = ch;
	//Add null terminator at the end of new Val
	value[n] = '\0';
	return value;
}

String String::assign(int n, const char* ch)
{
	//Input validation
	if (n < 0)
	{
		cout << "Invalid amount of times!" << endl;
		exit(EXIT_FAILURE);
	}

	//Reset original string
	delete[] value;
	value = nullptr;

	value = new char[n + 1];	//Pointer to new char array

	//Assign ch to original String n times.
	for (int i = 0; i < n; i++)
		value[i] = *ch;
	//Add null terminator at the end of new Val
	value[n] = '\0';
	return value;
}

/****************************************************************
* Assign a String to the original String.						*
*																*
* @param ch: other String.										*
****************************************************************/
String String::assign(const String& ch)
{
	//Delete and reset
	delete[] value;
	value = nullptr;

	char* value = new char[ch.length() + 1];	//pointer to new String

	//Copy the array of character to the String.
	for (int i = 0; i <= ch.length(); i++)
		*(value + i) = ch.value[i];

	return *this;
}

/****************************************************************
* Assign the first n characters of the character array ch to the*
* original String.												*
*																*
* Perform bound check for SIZE.									*
*																*
* @param SIZE: number of times to copy the character to String.	*
* @param ch: a constant character.								*
****************************************************************/
String String::assign(const String& ch, int SIZE)
{
	//Delete and reset
	delete[] value;
	value = nullptr;

	//Input validation
	if (SIZE < 0 || SIZE >= ch.length())
	{
		if (SIZE < 0)
			cout << "Invalid integer!" << endl;
		if (SIZE >= ch.length())
			cout << SIZE << " exceed the length of the String." << endl;
		exit(EXIT_FAILURE);
	}
	
	value = new char[SIZE + 1];	//Pointer to new char array

	//Assign ch to original String n times.
	for (int i = 0; i < SIZE; i++)
		value[i] = ch.value[i];
	value[SIZE] = '\0';

	return value;
}

/****************************************************************
* Assign a sub string of str to the original String.			*
*																*
* Perform bound check for X and N.								*
*																*
* @param str: a String.											*
* @param x: Start position of the sub string in str.			*
* @param n: Number of characters of the sub string in str.		*
****************************************************************/
String String::assign(const String& str, int x, int n)
{
	//Input validation
	if (n > str.length() + 1 || x < 0 || n + x > str.length())
	{
		if (n > str.length() + 1)
			cout << "Substring's length is greater than the string's length.\n";
		if (x < 0)
			cout << "Invalid integer for possition.\n";
		if (x + n > str.length())
			cout << "Substring exceed the string's length.\n";
		exit(EXIT_FAILURE);
	}

	//Delete and reset
	delete[] value;
	value = nullptr;

	value = new char[n + 1]; //Pointer to new char array

	//Add n characters from position x of str to the original String
	for (int i = 0; i < n; i++)
		value[i] = str.value[x + i];
	//Add null terminator at the end of the String
	value[n] = '\0';

	return value;
}

/****************************************************************
* Deleting all the characters stored in the String and shrink	*
* the allocated memory size to 0.								*
****************************************************************/
void String::clear()
{
	delete[] value;
	value = nullptr;
}

/****************************************************************
* Performs a comparison between a String and an array of		*
* characters.													*
*																*																*
* @param s: a String object or a character array.				*
* @return False if the 2 string is equal, return True otherwise.*
****************************************************************/
bool String::compare(const char* s) const
{
	String str = s; //convert str to the String data type

	//Check size of 2 objects
	if (length() != str.length()) return true;

	//Check each character of each objects according to the index number
	for (int i = 0; i < length(); i++)
		if (value[i] != str.value[i]) return true;
	
	//Return false if nothing happend
	return false;
}

/****************************************************************
* Performs a comparison between two String.						*
*																*																*
* @param s: a String object or a character array.				*
* @return False if the 2 string is equal, return True otherwise.*
****************************************************************/
bool String::compare(const String& str) const
{
	//Check size of 2 objects
	if (length() != str.length()) return true;

	//Check each character of each objects according to the index number
	for (int i = 0; i < length(); i++)
		if (value[i] != str.value[i]) return true;

	//Return false if nothing happend
	return false;
}

/****************************************************************
* Performs a comparison between two char objects.				*
* 1st object is the original String, 2nd object is a sub string	*
* of the original String and also an array of characters.		*
*																*
* Perform bound check for x and n.								*
*																*
* @param s: a String object or a character array.				*
* @param x: the start of the sub String in str.					*
* @param n: number of characters of the sub String in str.		*
* @return False if the 2 string is equal, return True otherwise.*
****************************************************************/
bool String::compare(const char* s, int x, int n) const
{
	String str = s; //convert the sub String of str to the String data type

	str.assign(str, x, str.length());
	//Check size of 2 objects
	if (length() != str.length()) return true;

	//Check each character of each objects according to the index number
	for (int i = 0; i < length(); i++)
		if (value[i] != str.value[i]) return true;

	//Return false if nothing happend
	return false;
}

/****************************************************************
* Performs a comparison between two char objects.				*
* 1st object is the original String, 2nd object is a sub String	*
* of the original String.										*
*																*
* Perform bound check for x and n.								*
*																*
* @param s: a String object or a character array.				*
* @param x: the start of the sub String in str.					*
* @param n: number of characters of the sub String in str.		*
* @return False if the 2 string is equal, return True otherwise.*
****************************************************************/
bool String::compare(const String& s, int x, int n) const
{
	String str;
	str.assign(s, x, n);
	//Check size of 2 objects
	if (length() != str.length()) return true;

	//Check each character of each objects according to the index number
	for (int i = 0; i < length(); i++)
		if (value[i] != str.value[i]) return true;

	//Return false if nothing happend
	return false;
}




String String::operator+=(const char* str)
{
	append(str);
	return value;
}

String String::operator+=(const String& str)
{
//	String temp = value;
//	temp.append(str);
	append(str);
	return value;
}


String String::operator+(const String& str)
{
	String temp = value;

	temp.append(str);

	return temp;
}

String String::operator-(const String& str)
{
	String temp = value;
	return temp.projection(str);
}


const String String::operator=(const char* s)//String a = "asb";
{
	String str(s);
	if (*this != str)
	{
		delete[] value;
		value = new char[str.length() + 1];

		for (int i = 0; i < str.length(); i++)
			value[i] = str.value[i];

		value[str.length()] = '\0';
	}
	return *this;
}

const String String::operator=(const String& temp) //String a = temp;
{
	if (*this != temp)
	{	
	//Delete and reset
	delete[] value;
	value = nullptr;

	value = new char[temp.length() + 1];	//pointer to new String

	//Copy the array of character to the String.
	for (int i = 0; i < temp.length(); i++)
		*(value + i) = temp.value[i];

	value[temp.length()] = '\0';
	}

	return value;
}

bool String::operator==(const String&str) const
{
	return !compare(str);
}

bool String::operator!=(const String& str) const
{
	return compare(str);
}

bool String::operator>(const String& str) const
{
	String s1 = value;
	String s2 = str;
	bool greater;				//true if s1 is greater than s2
	int i = 0;					//counter for loop
	String s = "";				//empty string to hold s1 or s2 upercase temporarily

	//Turn s1 and s2 into uppercase
	s1.toupper();
	s2.toupper();
	//Compare s1 and s2
	if (s1.length() > s2.length())
	{
		greater = true;
		while (i < s2.length() && greater)
		{
			if (s1.value[i] > s2.value[i]) return true;
			else if (s1.value[i] < s2.value[i]) return false;
			else i++;
			//cout << s2[i] << " > " << s1[i] << " = " << greater << endl;
		}
	}
	else
	{
		greater = false;
		while (i < s1.length() && !greater)
		{
			if (s1.value[i] < s2.value[i]) return false;
			else if (s1.value[i] > s2.value[i]) return true;
			else i++;
		}
	}

	return greater;
}

bool String::operator<(const String& str) const
{
	String s1 = value;
	String s2 = str;

	return !(s1 > s2);
}


/****************************************************************
* Overloading operater prefix ++								*
* Add a period to the String.									*
*																*
* @return the new value of the String object.					*
****************************************************************/
String String::operator++()
{
	append(1,'.');
	return *this;
}

/****************************************************************
* Overloading operater postfix ++								*
* Add a period to the String.									*
*																*
* @return the original value of the String object.				*
****************************************************************/
String String::operator++(int)
{
	String temp = value;
	append(1,'.');
	return temp;
}

/****************************************************************
* Overloading operater prefix --								*
* Take the last character out of the String.					*
*																*
* @return the new value of the String object.					*
****************************************************************/
String String::operator--()
{
	assign(value, length() - 1);
	return *this;
}

/****************************************************************
* Overloading operater postfix --								*
* Take the last character out of the String.					*
*																*
* @return the original value of the String object.				*
****************************************************************/
String String::operator--(int)
{
	String temp = value;
	assign(temp, temp.length() - 1);
	return temp;
}

ostream& operator<<(ostream& out, const String& str)
{
	out << str.value;
	return out;
}

istream& operator>>(istream& in, String& str)
{
	in >> str.value;
	return in;
}

unsigned short String::toupper(const char ch)
{
	if (ch >= 'a' and ch <= 'z') return (unsigned short)ch - 32;
	return (unsigned short)ch;
}

/****************************************************************
* Check if s is a sub String of str.							*
*																*
* @param str: The parent String.								*
* @param s: The possible child String.							*
* @return true if s is a sub String of str, return false		*
* otherwise.													*
****************************************************************/
bool String::isSubstr(const String& str, const String& s)
{
	String test; //Every possible substring in srt with the same length as String s

	for (int i = 0; i < str.length() - s.length() + 1; i++)
	{
		test.assign(str, i, s.length());
		if (test == s) return true;
	}

	return false;
}

/****************************************************************
* Convert the String to all Upper cases.						*
*																*
* @return the String with all letter now is uppercases.			*
****************************************************************/
String String::toupper()
{
	String temp = value;
	for (int i = 0; i < length(); i++)
		value[i] = (char)toupper(temp.value[i]);
	return *this;
}

//Destructor
String::~String()
{
	delete[] value;
	value = nullptr;
}
