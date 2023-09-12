#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class String;

class String
{
private:
	char* value; //pointer to a charater array
public:
	//Constructs list, all done
	String();
	String(const char *ch);
	String(const String&);
	String(const char, const int);
	String(const String&, const int, const int);

	//12 member functions
	char at(const int) const; //done
	char front() const;	//Sedra
	char back() const;	//Sedra
	char* c_str() const;	//sedra
	bool empty() const;		//Minh
	int capacity() const;	//Done
	
	int length() const; //done
	int size() const;	//done
	void swap(String &); //done
	void copy(const String, int, int); //Minh
	String substr(int, int) const;	//Minh
	void erase(int, int); //Minh

	//Obligate member functions
	bool palindrome() const;				//Minh
	bool palindrome(int, int) const;		//Minh
	String reverse();							//Sedra
	String projection(char);					//Sedra
	String projection(String);				//Sedra

	//Extra stuff
	void print() const; //done
	void append(int, const char*);
	void append(int, const char);
	void append(const char*);
	void append(const String&);
	void append(const char*, int);
	void append(const String&, int);
	void append(const String&, int, int);
	String assign(int, const char);
	String assign(int, const char*);
	String assign(const String&);
	String assign(const String&, int);
	String assign(const String&, int, int);
	void clear();
	bool compare(const char*) const;
	bool compare(const String&) const;
	bool compare(const char*, int, int) const;
	bool compare(const String&, int, int) const;
	String toupper();

	//Supported operators	 //All done
	String operator+=(const char*);
	String operator+=(const String&);
	String operator+(const String&);
	String operator-(const String&);
	const String operator=(const char*);
	const String operator=(const String&);
	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	bool operator>(const String&) const;
	bool operator<(const String&) const;
	String operator++();
	String operator++(int);
	String operator--();
	String operator--(int);
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);

	static unsigned short toupper(const char);
	static bool isSubstr(const String&, const String&);
	static unsigned short tolower(const char);
	static bool isupper(const char);

	//Destructor
	~String();
};
#endif