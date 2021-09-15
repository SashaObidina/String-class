#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define UNIT 64
#include <iostream>
#include <cstdio>
#include <string.h>
class MyString
{
private:
	char* str;
	char* str_c_;
	unsigned int str_size_; //size is how many characters actually exist in the string
	unsigned int str_cap_; //capacity is the maximum number of characters that the string can currently hold without having to grow

public: //constructor
	MyString(); //default constructor
	MyString(const MyString& str2); // copy constructor
	MyString(const char* str2); //char array constructor
	MyString(std::initializer_list<char>& li); //initializer list constructor
	MyString(std::string str2); //std::string constructor
	MyString(const char* str2, int count); //init class with count characters of  “char string”, Constructor(“hello”, 4) -> “hell”
	MyString(unsigned int count, char symbol); //init class with count of characters, Constructor(4, ‘a’)->“aaa”

	~MyString(); //destructor

	MyString operator + (const MyString& str2); //concatenate with Mystring
	MyString operator + (const char* str2); //concatenate with char array
	MyString operator + (std::string str2); //concatenate with std::string

	MyString operator += (const char* str2); //assignment concatenate with char array
	MyString operator += (std::string str2); //assignment concatenate with std::string
	
	MyString& operator = (const MyString& str2);//MyString assignment
	MyString& operator = (const char* str2); //char string assignment
	MyString& operator = (std::string str2); //std::string assignment
	MyString& operator = (char symbol); //char assignment
	char& operator[](int i) const; //index operator, Mystring(“012345”);[5] ->‘5’

	bool operator > (const MyString& str2) const;
	bool operator > (char* str2) const;
	bool operator > (std::string str2) const;
	
	bool operator < (const MyString& str2) const;
	bool operator < (char* str2) const;
	bool operator < (std::string str2) const;

	bool operator >= (const MyString& str2) const;
	bool operator >= (char* str2) const;
	bool operator >= (std::string str2) const;

	bool operator <= (const MyString& str2) const;
	bool operator <= (char* str2) const;
	bool operator <= (std::string str2) const;

	bool operator == (const MyString& str2) const;
	bool operator == (char* str2) const;
	bool operator == (std::string str2) const;

	bool operator != (const MyString& str2) const;
	bool operator != (char* str2) const;
	bool operator != (std::string str2) const;

	friend std::ostream& operator <<(std::ostream& os, MyString& str2); //like operator << (std::basic_string)
	friend std::istream& operator >>(std::istream& is, MyString& str2); //like operator >> (std::basic_string)

	const char* C_str(); //return a pointer to null-terminated character array
	const char* c_str(std::string str); //return a pointer to null-terminated character array, use for std::string
	char* data() const; //return a pointer to array data that not required to be null-terminated
	unsigned int length() const; //same as size 
	unsigned int Size() const; //return the number of char elements in string
	bool empty() const; //true if string is empty
	unsigned int capacity() const; //return the current amount of allocated memory for array
	char* shrink_to_fit(unsigned int new_size); //reduce the capacity to size
	void clear(); //remove all char element in string
	unsigned int capacity_set(unsigned int size); //set capacity	
	unsigned int strlen(const char* str); //return length of string

	void insert(int index, int count, char symbol); /* insert count of char in index position s = “aaaaa”
														s.insert(0, 1, ’!’)->“!aaaaa”
														s.insert(3, 2, ’@’)->“!aa@@aaa” */
	void insert(int index, const char* string); /* insert null-terminated char string at index position
														s = “aaaaa”
														s.insert(1, ”@@@@@”)->“a@@@@@aaaa” */
	void insert(int index, const char* string, int count); /* insert count of null-terminated char string at index position
														s = “aaaaa”
														s.insert(1, ”@@@@@”, 2)->“a@@aaaa” */
	void insert(int index, std::string string); /* insert std::string at index position
														s = “aaaaa”
														string = “@@@@@”
														s.insert(1, std::string(“@@@@@”))->“a@@@@@aaaa” */
	void insert(int index, std::string string, int count); /* insert count of std::string at index position
														s = “aaaaa”
														s.insert(1, std::string(“@@@@@”)), 2)->“a@@aaaa” */
	void erase(int index, int count); /* erase count of char at index position
														s = “aa@@@@@aaa”
														s.erase(2, 3)->“a@@aaaa” */
	void append(int count, char symbol); /* append count of char
														str.clear()->“”
														str.append(3, ’!’)->“!!!”
														str.append(3, ’@’)->“!!!@@@” */
	void append(const char* string); /* append null-terminated char string
														str.clear()->“”
														str.append(“hello ”)->“hello ”
														str.append(“world”)->“hello world” */
	void append(const char* string, int index, int count); /* append a count of null-terminated char string by index position
														str.clear()->“”
														str.append(“hello world”, 0, 6)->“hello ”
														str.append(“hello world”, 6, 5)->“hello world” */
	void append(std::string string); /* append std:: string
														/*str.clear()->“”
														str.append(std::string(“hello ”))->“hello ”
														str.append(std::string(“world”))->“hello world” */
	void append(std::string string, int index, int count); /* append a count of std:: string by index position
														/*str.clear()->“”
														str.append(std::string(“hello world”), 0, 6)->“hello ”
														str.append(std::string(“hello world”), 6, 5)->“hello world” */
	void replace(int index, int count, const char* string); /* replace a count of char at index by char *str
														/*s = “hello amazing world”
														s.replace(6, 7, ”wonderful”)->“hello wonderful world” */
	void replace(int index, int count, std::string string); /* replace a count of char at index by std::string
														/*s = “hello amazing world”
														s.replace(6, 7, std::string(”wonderful”))->“hello wonderful world” */
	MyString substr(int index) const; /* return a substring starts with index position
														s = “hello amazing world”
														s.substr(6)->“amazing world” */
	MyString substr(int index, int count) const;	/* return a count of substring’s char starts with index position
														s = “hello amazing world”
														s.substr(6, 7)->“amazing” */
	int find(char* string) const; //if founded return the index of substring
	int find(char* string, int index) const; //same as find(char *str) but search starts from index position
	int find(std::string string) const; //if founded return the index of substring
	int find(std::string string, int index) const; //same as find(char *str) but search starts from index position
};