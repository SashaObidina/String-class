#include"my_string.h" 

//íå çàáûòü óäàëèòü, äëÿ òåñòèðîâàíèÿ
using namespace std;

//constructors
//default constructor
MyString::MyString()
{
	str = NULL;
	str_c_ = NULL;
	str_size_ = 0;
	str_cap_ = 0;
}

//copy constructor
MyString::MyString(const MyString& str2)
{
	int i = 0;
	str_size_ = str2.str_size_;
	str_cap_ = capacity_set(str_size_);
	this->str = new char[str_cap_+1];
	for (i = 0; i < str_cap_; i++)
	{
		if (str2.str[i] > 0)
			this->str[i] = str2.str[i];
		else
			this->str[i] = '\0';
	}
	this->str[str_cap_] = '\0';
}

//char array constructor
MyString::MyString(const char* str2)
{
	int i = 0;
	str_size_ = strlen(str2);
	str_cap_ = capacity_set(str_size_);
	this->str = new char[str_cap_+1];
	for (i = 0; i < str_cap_; i++)
	{
		if (str2[i] > 0)
			this->str[i] = str2[i];
		else
			this->str[i] = '\0';
	}
	this->str[str_cap_] = '\0';
}

//initializer list constructor
MyString::MyString(std::initializer_list<char>& li)
{
	int j = 0;
	this->str_cap_ = capacity_set(strlen(li.begin()));
	this->str = new char[str_cap_+1];
	for (const char* i = li.begin(); i != li.end(); i++, j++)
	{
		this->str[j] = *i;
	}
	this->str_size_ = j + 1;
	for (j = str_size_; j<str_cap_; j++)
		this->str[j] = '\0';
	this->str[str_cap_] = '\0';
}

//std::string constructor
MyString::MyString(std::string str2)
{
	int i = 0;
	str_size_ = str2.size();
	str_cap_ = capacity_set(str_size_);
	this->str = new char[str_cap_+1];
	for (i = 0; i < str_size_; i++)
	{
		this->str[i] = str2[i];
	}
	for (i = str_size_; i < str_cap_; i++)
		this->str[i] = '\0';
	this->str[str_cap_] = '\0';
}

//init class with count characters of  “char string”, Constructor(“hello”, 4) -> “hell”
MyString::MyString(const char* str2, int count)
{
	int i = 0;
	str_size_ = count;
	str_cap_ = capacity_set(str_size_);
	this->str = new char[str_cap_+1];
	for (i = 0; i < str_size_; i++)
		this->str[i] = str2[i];
	for (i = str_size_; i < str_cap_; i++)
		this->str[i] = '\0';
	this->str[str_cap_] = '\0';
}

MyString::MyString(unsigned int count, char symbol) //init class with count of characters, Constructor(4, ‘a’)->“aaa”
{
	int i = 0;
	str_size_ = count;
	str_cap_ = capacity_set(str_size_);
	this->str = new char[str_cap_+1];
	for (i = 0; i < str_size_; i++)
		this->str[i] = symbol;
	for (i = str_size_; i < str_cap_; i++)
		this->str[i] = '\0';
	this->str[str_cap_] = '\0';
}

//destructor
MyString::~MyString()
{
	if (this->str != NULL)
	{
		delete[] str;
	}
}

//operators
//concatenate with MyString
MyString MyString::operator + (const MyString& str2)
{
	int i = 0;
	int old_size = str_size_;
	str_size_ = old_size + str2.str_size_;
	str_cap_ = capacity_set(str_size_);
	char* new_str = new char[str_cap_ + 1];
	for (i = 0; i < old_size; i++)
		new_str[i] = str[i];
	for (i = old_size; i < str_size_; i++)
		new_str[i] = str2.str[i - old_size];
	for (i = str_size_; i < str_cap_; i++)
		new_str[i] = '\0';
	new_str[str_cap_] = '\0';
	this->str = new_str;
	return *this;
}

//concatenate with char array
MyString MyString::operator + (const char* str2)
{
	int i = 0;
	int old_size = str_size_;
	int str2_size = strlen(str2);
	str_size_ = old_size + str2_size;
	str_cap_ = capacity_set(str_size_);
	char* new_str = new char[str_cap_ + 1];
	for (i = 0; i < old_size; i++)
		new_str[i] = str[i];
	for (i = old_size; i < str_size_; i++)
		new_str[i] = str2[i - old_size];
	for (i = str_size_; i < str_cap_; i++)
		new_str[i] = '\0';
	new_str[str_cap_] = '\0';
	this->str = new_str;
	return *this;
}

//concatenate with std::string
MyString MyString::operator + (std::string str2)
{
	int i = 0;
	int old_size = str_size_;
	int str2_size = str2.size();
	str_size_ = old_size + str2_size;
	str_cap_ = capacity_set(str_size_);
	char* new_str = new char[str_cap_ + 1];
	for (i = 0; i < old_size; i++)
		new_str[i] = str[i];
	for (i = old_size; i < str_size_; i++)
		new_str[i] = str2[i - old_size];
	for (i = str_size_; i < str_cap_; i++)
		new_str[i] = '\0';
	new_str[str_cap_] = '\0';
	this->str = new_str;
	return *this;
}

//assignment concatenate with char array
MyString MyString::operator += (const char* str2)
{
	return *this = operator + (str2);
}

//assignment concatenate with std::string
MyString MyString::operator += (std::string str2)
{
	return *this = operator + (str2);
}

//MyString assignment
MyString& MyString::operator = (const MyString& str2) 
{
	int i = 0;
	str_size_ = str2.length();
	str_cap_ = capacity_set(str_size_);
	if (this->str)
	{
		delete[] str;
	}
	this->str = new char[str_cap_+1];
	for (i = 0; i < str_size_; i++)
		this->str[i] = str2.str[i];
	for (i = str_size_; i < str_cap_; i++)
		this->str[i] = '\0';
	this->str[str_cap_] = '\0';
	return *this;
}

//char string assignment
MyString& MyString::operator = (const char* str2)
{
	int i = 0;
	MyString tmp;
	tmp.str_size_ = strlen(str2);
	tmp.str_cap_ = capacity_set(tmp.str_size_);
	tmp.str = new char[tmp.str_cap_ + 1];
	for (i = 0; i < tmp.str_size_; i++)
		tmp.str[i] = str2[i];
	for (i = tmp.str_size_; i < tmp.str_cap_; i++)
		tmp.str[i] = '\0';
	tmp.str[tmp.str_cap_] = '\0';
	return operator = (tmp);
}

//std::string assignment
MyString& MyString::operator = (std::string str2)
{
	return operator = (c_str(str2));
}

//char assignment
MyString& MyString::operator = (char symbol)
{
	int i = 0;
	this->str_size_ = 1;
	this->str_cap_ = capacity_set(this->str_size_);
	this->str = new char[this->str_cap_];
	this->str[0] = symbol;
	for (i = this->str_size_; i < this->str_cap_; i++)
		this->str[i] = '\0';
	this->str[this->str_cap_] = '\0';
	return *this;
}

//index operator, Mystring(“012345”);[5] ->‘5’
char& MyString::operator [](int index) const
{
	return this->str[index];
}

bool MyString::operator > (const MyString& str2) const
{
	if (this->str_size_ > str2.str_size_) return true;
	return false;
}

bool MyString::operator > (char* str2) const
{
	int i = 0;
	int new_size = 0;
	for (i = 0; ; i++)
	{
		if (str2[i] > 0)
			new_size++;
		else
			break;
	}
	if (str_size_ > new_size) return true;
	return false;
}

bool MyString::operator > (std::string str2) const
{
	if (str_size_ > str2.size()) return true;
	return false;
}

bool MyString::operator < (const MyString& str2) const
{
	return !operator >= (str2);
}

bool MyString::operator < (char* str2) const
{
	return !operator >= (str2);
}

bool MyString::operator < (std::string str2) const
{

	return !operator >= (str2);
}

bool MyString::operator >= (const MyString& str2) const
{
	if (this->str_size_ >= str2.str_size_) return true;
	return false;
}

bool MyString::operator >= (char* str2) const
{
	int i = 0;
	int new_size = 0;
	for (i = 0; ; i++)
	{
		if (str2[i] > 0)
			new_size++;
		else
			break;
	}
	if (str_size_ >= new_size) return true;
	return false;
}

bool MyString::operator >= (std::string str2) const
{
	if (str_size_ >= str2.size()) return true;
	return false;
}

bool MyString::operator <= (const MyString& str2) const
{
	return !operator > (str2);
}

bool MyString::operator <= (char* str2) const
{
	return !operator > (str2);
}

bool MyString::operator <= (std::string str2) const
{
	return !operator > (str2);
}

bool MyString::operator == (const MyString& str2) const
{
	int i = 0;
	if (str_size_ != str2.str_size_)
		return false;
	for (i = 0; i < str_size_; i++)
	{
		if (this->str[i] != str2.str[i])
			return false;
	}
	return true;
}

bool MyString::operator == (char* str2) const
{
	int i = 0;
	int new_size = 0;
	for (i = 0; ; i++)
	{
		if (str[i] > 0)
			new_size++;
		else
			break;
	}
	if (str_size_ != new_size) 
		return false;
	for (i = 0; i < new_size; i++)
	{
		if (this->str[i] != str2[i])
			return false;
	}
	return true;
}

bool MyString::operator == (std::string str2) const
{
	int i = 0;
	int new_size = str2.size();
	if (str_size_ != new_size)
		return false;
	for (i = 0; i < new_size; i++)
	{
		if (this->str[i] != str2[i])
			return false;
	}
	return true;
}

bool MyString::operator !=(const MyString& str2) const
{
	return !operator == (str2);
}

bool MyString::operator != (char* str2) const
{
	return !operator == (str2);
}

bool MyString::operator != (std::string str2) const
{
	return !operator == (str2);
}

//like operator << (std::basic_string)
std::ostream& operator <<(std::ostream& os, MyString& str2)
{
	return (os << str2.Size());
}

//like operator >> (std::basic_string)
std::istream& operator >>(std::istream& is, MyString& str2)
{
	str2.clear();
	char c;
	do {
		c = is.get();
		if (c == '\n' || c == ' ')
			break;
		str2.append(1, c);
	} while (true);
	return is;
}

//return a pointer to null-terminated character array
const char* MyString::C_str()
{
	int i = 0;
	this->str_c_ = new char[strlen(str) + 1];
	for (i = 0; i < strlen(str); i++)
		str_c_[i] = str[i];
	str_c_[strlen(str)] = '\0';
	return this->str_c_;
}

//return a pointer to null-terminated character array, use for std::string
const char* MyString::c_str(std::string str)
{
	int i = 0;
	int new_size = 0;
	for (i = 0; ; i++)
	{
		if (str[i] > 0)
			new_size++;
		else
			break;
	}
	char* new_str = new char[new_size + 1];
	for (i = 0; i < new_size; i++)
		new_str[i] = str[i];
	new_str[new_size] = '\0';
	return new_str;
}

//return a pointer to array data that not required to be null-terminated
char* MyString::data() const
{
	return str;
}

//same as size 
unsigned int MyString::length() const
{
	return str_size_;
}

//return the number of char elements in string
unsigned int MyString::Size() const
{
	return str_size_;
}

//true if string is empty
bool MyString::empty() const
{
	if (this->str == NULL) return true;
	return false;
}

//return the current amount of allocated memory for array
unsigned int MyString::capacity() const
{
	return str_cap_;
}

//reduce the capacity to size
char* MyString::shrink_to_fit(unsigned int new_size_c)
{
	int i = 0;
	char* copy_str = new char[str_cap_];
	for (i = 0; i < str_cap_; i++)
	{
		copy_str[i] = this->str[i];
	}
	this->clear();
	int copy_size = this->str_cap_;
	this->str_cap_ = new_size_c;
	this->str = new char[new_size_c + 1];
	for (i = 0; i < copy_size; i++)
	{
		this->str[i] = copy_str[i];
	}
	int new_size_s = 0;
	for (i = 0; ; i++)
	{
		if (this->str[i] > 0)
			new_size_s++;
		else
			break;
	}
	this->str_size_ = new_size_s;
	delete[] copy_str;
	return this->str;
}

//remove all char element in string
void MyString::clear()
{
	if (this->str == NULL)
		return;
	str = new char[0];
}

//set capacity
unsigned int MyString::capacity_set(unsigned int size)
{
	unsigned int new_size = size / UNIT + 1;
	return (new_size * UNIT);
}

//return length of string
unsigned int MyString::strlen(const char* str)
{
	int i = 0;
	int str_size = 0;
	for (i = 0; ; i++)
	{
		if (str[i] > 0)
			str_size++;
		else
			break;
	}
	return str_size;
}

//insert count of char in index position
void MyString::insert(int index, int count, char symbol)
{
	int i = 0;
	if ((this->str_size_ + count) > this->str_cap_)
		this->shrink_to_fit(str_size_ + count);
	char* new_str = new char[str_cap_];
	memcpy(new_str, str, index);
	for (i = 0; i < count; i++)
		new_str[index + i] = symbol;
	memcpy(new_str + (index + count) * sizeof(char), str + index * sizeof(char), str_cap_ - index);
	this->str_size_ += count;
	this->str = new_str;
}

//insert null - terminated char string at index position
void MyString::insert(int index, const char* string)
{
	int i = 0;
	int count = strlen(string);
	if ((this->str_size_ + count) > this->str_cap_)
		this->shrink_to_fit(str_size_ + count);
	char* new_str = new char[str_cap_];
	memcpy(new_str, str, index);
	for (i = 0; i < count; i++)
		new_str[index + i] = string[i];
	memcpy(new_str + (index + count) * sizeof(char), str + index * sizeof(char), str_cap_ - index);
	this->str_size_ += count;
	this->str = new_str;
}

//insert count of null - terminated char string at index position
void MyString::insert(int index, const char* string, int count)
{
	int i = 0;
	int new_size = strlen(string);
	if (new_size < count)
		this->insert(index, string);
	if ((this->str_size_ + count) > this->str_cap_)
		this->shrink_to_fit(str_size_ + count);
	char* new_str = new char[str_cap_];
	memcpy(new_str, str, index);
	for (i = 0; i < count; i++)
		new_str[index + i] = string[i];
	memcpy(new_str + (index + count) * sizeof(char), str + index * sizeof(char), str_cap_ - index);
	this->str_size_ += count;
	this->str = new_str;
}

//insert std::string at index position
void MyString::insert(int index, std::string string)
{
	this->insert(index, c_str(string));
}

//insert count of std::string at index position
void MyString::insert(int index, std::string string, int count)
{
	this->insert(index, c_str(string), count);
}

//erase count of char at index position
void MyString::erase(int index, int count)
{
	int i = 0;
	int j = 0;
	int str_size = this->Size();
	for (i = index, j = index + count; i < str_size; i++, j++)
	{
		this->str[i] = this->str[j];
	}
	str_size_ -= count;
}

//append count of char
void MyString::append(int count, char symbol)
{
	int i = 0;
	int str_size = this->Size();
	if ((str_size + count) > this->str_cap_)
		this->shrink_to_fit(str_size + count);
	for (i = str_size; i < (str_size + count); i++)
		this->str[i] = symbol;
	this->str[str_size + count] = '\0';
	this->str_size_ += count;
}

//append null-terminated char string
void MyString::append(const char* string)
{
	insert(str_size_, string);
}

//append a count of null-terminated char string by index position
void MyString::append(const char* string, int index, int count)
{
	insert(this->str_size_, string + index, count);
}

//append std:: string
void MyString::append(std::string string)
{
	this->append(c_str(string));
}

//append a count of std:: string by index position
void MyString::append(std::string string, int index, int count)
{
	this->append(c_str(string), index, count);
}

//replace a count of char at index by char* str
void MyString::replace(int index, int count, const char* string)
{
	this->erase(index, count);
	this->insert(index, string);
}

//replace a count of char at index by std::string
void MyString::replace(int index, int count, std::string string)
{
	this->replace(index, count, c_str(string));
}

//return a substring starts with index position
MyString MyString::substr(int index) const
{
	int str_size = this->Size();
	MyString rez = this->str;
	if (index > str_size)
		return rez;
	rez.erase(0, index);
	return rez;
}

//return a count of substring’s char starts with index position
MyString MyString::substr(int index, int count) const
{
	int str_size = this->Size();
	MyString rez = this->str;
	if (index > str_size)
		return rez;
	rez.erase(index + count, rez.Size() - (index + count));
	rez.erase(0, index);
	return rez;
}

//if founded return the index of substring
int MyString::find(char* string) const
{
	return this->find(string, 0);
}

//same as find(char *str) but search starts from index position
int MyString::find(char* string, int index) const
{
	int i = 0;
	MyString rez = this->str;
	MyString sub = string;
	if (index > str_size_)
		return -1;
	for (i = index; i < str_size_; i++)
	{
		if ((rez.substr(i, sub.Size())) == sub)
			return 1;
	}
	return -1;
}

//if founded return the index of substring
int MyString::find(std::string string) const
{
	return this->find(string, 0);
}

//same as find(char *str) but search starts from index position
int MyString::find(std::string string, int index) const
{
	int i = 0;
	MyString rez = this->str;
	MyString sub = string;
	if (index > str_size_)
		return -1;
	for (i = index; i < str_size_; i++)
	{
		if ((rez.substr(i, sub.Size())) == sub)
			return 1;
	}
	return -1;
}

int main(void)
{
	//std::string b("aaaaa");
	const char str2[3] = "ha";
	MyString rez = "aa@@@@@aaa";
	//rez = rez + str2;
	std::string f = "@@@@@";
	//rez.insert(1, f);
	//rez.erase(2,3);
	//rez.append("lllnnnk", 3, 3);
	rez = "hello amazing world";
	rez.replace(6, 7, "wonderful");
	//rez.substr(6, 7);
	//rez = "hellololok";
	//rez.find("lolo", 7);
	rez.C_str();
	return 0;
}