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
* Perform bound check for n.									*
*																*
* @param n: number of times to copy the character to String.	*
* @param ch: a constant character.								*
****************************************************************/
String::String(const char ch, const int n)
{
	//Input validation
	if (n < 0)
	{
		cout << "Invalid amount of times!" << endl;
		exit(EXIT_FAILURE);
	}

	value = new char[n + 1];	//Pointer to new char array

	//Assign ch to original String n times.
	for (int i = 0; i < n; i++)
		value[i] = ch;
	value[n] = '\0';
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
String::String(const String& str, const int x, const int n)
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

	value = new char[n + 1]; //Pointer to new char array

	//Add n characters from position x of str to the original String
	for (int i = 0; i < n; i++)
		value[i] = str.value[x + i];
	//Add null terminator at the end of the String
	value[n] = '\0';
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
	return value[0];
}

/****************************************************************
* @return The last character in the string.						*
****************************************************************/
char String::back() const
{
	return value[length() - 1];
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
	int i = 0;
	
	//get size
	while (*(value + i) != '\0')
		i++;

	if (i == 0)	return true;
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
void String::copy(const String str, int x, int n)
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

	char* newVal = new char[n + 1];	//Pointer to new string

	//copy n characters from position x of str to newVal
	for (int i = 0; i < n; i++)
		newVal[i] = str.value[x++];
	//Add null terminator at the end of new Val
	newVal[n] = '\0';

	//Reset and return
	delete[] value;
	value = newVal;
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
	//Input validation
	if (n > length() + 1 || x < 0 || n + x > length())
	{
		if (n > length() + 1)
			cout << "Substring's length is greater than the string's length.\n";
		if (x < 0)
			cout << "Invalid integer for possition.\n";
		if (n + x > length())
			cout << "Substring exceed the string's length.\n";
		exit(EXIT_FAILURE);
	}

	char* newVal = new char[n + 1];	//Pointer to new string

	//copy n characters from position x of str to newVal
	for (int i = 0; i < n; i++)
		newVal[i] = value[x++];
	//Add null terminator at the end of new Val
	newVal[n] = '\0';

	//Reset and return
	return newVal;
}

/****************************************************************
* Erases n characters from String at position x.				*
*																*
* Perform bound check for x and n.								*
*																*
* @param x: beginning position to erase.						*
* @param n: number of characters to earase from String.			*
****************************************************************/
void String::erase(int x, int n)
{
	//Input validation
	if (n > length() + 1 || x < 0 || n + x > length())
	{
		if (n > length() + 1)
			cout << "Substring's length is greater than the string's length.\n";
		if (x < 0)
			cout << "Invalid integer for possition.\n";
		if (n + x > length())
			cout << "Substring exceed the string's length.\n";
		exit(EXIT_FAILURE);
	}

	char* newVal = new char[length() - n + 1];
	
	for (int i = 0; i < x; i++)
		newVal[i] = value[i];
	for (int i = x + n; i < length(); i++)
		newVal[i-n] = value[i];
	
	newVal[length() - n] = '\0';

	delete[] value;

	value = newVal;
}

/****************************************************************
* Check if String is palindromic.								*
*																*
* @return true if the string is palindromic, and false otherwise*
****************************************************************/
bool String::palindrome() const
{
	//special case
	if (length() == 0) return true;

	int low = 0;
	int high = length() - 1;

	while (low < high)
		if (value[low++] != value[high--]) return false;
	return true;
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
	//Input validation
	if (n > length() + 1 || x < 0 || n + x > length())
	{
		if (n > length() + 1)
			cout << "Substring's length is greater than the string's length.\n";
		if (x < 0)
			cout << "Invalid integer for possition.\n";
		if (n + x > length())
			cout << "Substring exceed the string's length.\n";
		exit(EXIT_FAILURE);
	}

	String str = substr(x, n);

	return str.palindrome();
}

/****************************************************************
* Reverses the String.											*
*																*
* Flip the string backward and the order of which character is	*
* uppercase and which character is lowercase letters stay the	*
* same.															*
****************************************************************/
String String::reverse()
{
	String myString = value; //copy of the original string
	int len = length(); //size of the string

	bool* up = new bool[len];	//array of uppercase letter's location of the string

	//get the location of all uppercase character in the string
	for (int i = 0; i < len; i++)
	{
		if (isupper(value[i]))
		{
			up[i] = true;
		}
		else
		{
			up[i] = false;
		}
	}

	//turn myString to all uppercases
	myString.toupper();

	char* newstring = new char[len + 1]; //the reverse string

	//copy myString to newstring reversly
	for (int i = 0; i < len + 1; i++)
	{
		newstring[i] = myString.value[len - i -1];
	}

	//add null terminator at the end of newstring
	newstring[len] = '\0';

	//turn all the letters to the right cases
	for (int i = 0; i < len; i++)
	{
		if (up[i] == false)
		{
			newstring[i] = (char)tolower(newstring[i]);
		}
	}
	// after reversing the string, get the length, check the first letter (if first letter is upper then turn it to lower and 
	// or if first letter is lower is turn it to upper) so there will be two implemented functions

	delete[] up;
	delete[]value;
	value = newstring;
	return newstring;
}


/****************************************************************
* Removes all character x from the original String.				*
*																*
* @param x: the character to be removed from the String.		*
****************************************************************/
void String::projection(char x)
{
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

/****************************************************************
* Assign ch to the original String n times.						*
*																*
* Perform bound check for n.									*
*																*
* @param n: number of times to copy the character to String.	*
* @param ch: a pointer to constant character.					*
****************************************************************/
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

	value = new char[ch.length() + 1];	//pointer to new String

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
*																*
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
*																*
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

/****************************************************************
* Performs add and operator, it adds right operand to left		*
* operand and assigns result to left operand.					*
*																*
* @param str is a pointer to character value to be appended.	*
* @return the new value after being appended.					*
****************************************************************/
String String::operator+=(const char* str) //str += "asdf"
{
	append(str);
	return value;
}

/****************************************************************
* Performs add and operator, it adds right operand to left		*
* operand and assigns result to left operand.					*
*																*
* @param str is String object that will be added to another		*
* variable.														*
* @return the new value after being appended.					*
****************************************************************/
String String::operator+=(const String& str) //str += str1
{
	append(str);
	return value;
}

/****************************************************************
* Performs addition operator.									*
*																*
* @param str is a String object that will be compounded.		*
* @return the new value after being compounded.					*
****************************************************************/
String String::operator+(const String& str)
{
	String temp = value;

	temp.append(str);

	return temp;
}

/****************************************************************
* Performs subtraction operator.								*
*																*
* @param str is a String object that will be decreased/removed.	*
* @return the new value after being decreased.					*
****************************************************************/
String String::operator-(const String& str)
{
	String temp = value;
	return temp.projection(str);
}

/****************************************************************
* Performs assignment operator.									*
*																*
* @param s is a pointer to character array that will be assigned*
* to a variable.												*
* @return the new value after being assigned.					*
****************************************************************/
const String String::operator=(const char* s)
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

/****************************************************************
* Performs assignment operator.									*
*																*
* @param s is a String object that will be assigned to another	*
* String variable.												*
* @return the new value after being assigned.					*
****************************************************************/
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

/****************************************************************
* Performs comparasion operator.								*
*																*
* @param str is a String object that will be compared to this	*
* String variable.												*
* @return true if two String are equal and false otherwise.		*
****************************************************************/
bool String::operator==(const String& str) const
{
	return !compare(str);
}

/****************************************************************
* Performs not equal operator.									*
*																*
* @param str is a String object that will be compared to this	*
* String variable.												*
* @return false if two String are equal and true otherwise.		*
****************************************************************/
bool String::operator!=(const String& str) const
{
	return compare(str);
}

/****************************************************************
* Performs greater than operator.								*
*																*
* @param str is a String object that will be compared to this	*
* String variable.												*
* @return true if this String are greater than str and false	*
* otherwise.													*
****************************************************************/
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

/****************************************************************
* Performs smaller than operator.								*
*																*
* @param str is a String object that will be compared to this	*
* String variable.												*
* @return true if this String are smaller than str and false	*
* otherwise.													*
****************************************************************/
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

/****************************************************************
* This is a function to overload the operator << to write		*
* standard output												*
*																*
* @param (out) is an outstream object.							*
* @param (str) is a String object								*
* @return outstream object										*  
****************************************************************/
ostream& operator<<(ostream& out, const String& str)
{
	out << str.value;
	return out;
}

/****************************************************************
* This is a function to overload the operator >> to write		*
* standard output												*
*																*
* @param (in) is an instream object.							*
* @param (str) is a String object								*
* @return instream object										*
****************************************************************/
istream& operator>>(istream& in, String& str)
{
	in >> str.value;
	return in;
}

/****************************************************************
* This function return a number value of upercase character of a*
* lower case character.											*
*																*
* @param ch: a character.										*
* @return a number value of ch's upercase character if it is a	*
* lower case character, return ch's decimal ASCII code otherwise.
****************************************************************/
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

/****************************************************************
* Convert the String to all lower cases.						*
*																*
* @return the String with all letter now is lowercases.			*
****************************************************************/
unsigned short String::tolower(const char ch)
{
	if (ch >= 'A' and ch <= 'Z') return (unsigned short)ch + 32;
	return (unsigned short)ch;
}

/****************************************************************
* Checks if String is upper cases.						        *
*																*
* @return boolean function.                           			*
****************************************************************/
bool String::isupper(const char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return true;
	}
	return false;
}

//Destructor
String::~String()
{
	//static int i = 1;
	delete[] value;
	value = nullptr;
	//cout << "destructor done " << i++ << endl;
}
