#define _CRT_SECURE_NO_WARNINGS
#include "String.h"


int TString::GetLn()
{
	return length;
}
char* TString::GetStr()
{
	return str;
}


TString::TString()
{
	str = nullptr;
	length = 0;
}
TString::~TString()
{
	delete[] this->str;
}


TString::TString(const char* str)
{

	length = strlen(str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}

	this->str[length] = '\0';
}
TString::TString(const TString& per)
{
	length = strlen(per.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = per.str[i];
	}

	this->str[length] = '\0';
}



TString TString::operator + (const TString& per)
{
	TString newStr;

	int Ln = strlen(this->str);
	int perLn = strlen(per.str);

	newStr.length = Ln + perLn;

	newStr.str = new char[Ln + perLn + 1];

	int i = 0;
	for (; i < Ln; i++)
	{
		newStr.str[i] = this->str[i];
	}

	for (int j = 0; j < perLn; j++, i++)
	{
		newStr.str[i] = per.str[j];
	}

	newStr.str[Ln + perLn] = '\0';

	return newStr;
}

TString& TString::operator = (const TString& per)
{
	if (this->str != nullptr)
	{
		delete[] str;
	}

	length = strlen(per.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = per.str[i];
	}

	this->str[length] = '\0';

	return *this;

}

TString& TString::operator = (const char* per)
{
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(per);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = per[i];
		}

		this->str[length] = '\0';

		return *this;

	}
}

bool TString::operator == (const TString& per)
{
	if (this->length != per.length)
	{
		return false;
	}

	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] != per.str[i])
		{
			return false;
		}
	}
	return true;
}

char TString::operator [] (int i)
{
	return this->str[i];
}

bool TString::operator > (const TString& s)
{
	if (*this == s)
	{
		return false;
	}
	int i = 0;
	while (i <= min(length, s.length))
	{
		if (int(str[i]) > int(s.str[i]))
		{
			return true;
		}
		i++;
	}
	return length > s.length;
}

bool TString::operator < (const TString& s)
{
	if (*this == s)
	{
		return false;
	}
	int i = 0;
	while (i <= min(length, s.length))
	{
		if (int(str[i]) < int(s.str[i]))
		{
			return true;
		}
		i++;
	}
	return length < s.length;
}


int TString::SymbPos(char c)
{
	int n = -1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			n = i;
			break;
		}
	}
	return n;
}

int TString::PdSlPos(const char* s)
{
	int n = -1;
	int l;
	l = strlen(s);
	int i = 0;
	bool f;
	while (i <= length - l)
	{
		f = true;
		for (int j = i; j < i + l; j++)
		{
			if (str[j] != s[j - i])
			{
				f = false;
				break;
			}
		}
		if (f == true)
		{
			n = i;
			break;
		}
		else
		{
			i++;
		}
	}
	return n;
}

int TString::Split(char**& arr, const char a)const {
	char* s = new char[2];
	s[0] = a;
	int pt = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == s[0]) {
			pt++;
		}
	}
	if (str[0] == s[0]) {
		pt--;
	}
	if (str[strlen(str) - 1] == s[0]) {
		pt--;
	}
	arr = new char* [pt + 1];
	for (int i = 0; i <= pt; i++) {
		arr[i] = new char[strlen(str) + 1];
	}
	char* str1 = str;
	str1 = strtok(str1, s);
	int i = 0;
	for (int i = 0; i < pt; i++) {
		arr[i] = str1;
		str1 = strtok(NULL, s);
	}
	arr[pt] = str1;
	return pt + 1;
}



TString TString::operator * (int k) {
	if (k <= 0)
		cout << "Error, enter k > 0" << endl;

	TString res(*this);

	for (int i = 1; i < k; i++) {
		res = res + *this;
	}

	return res;
}



char* TString::WthRep(int& r)
{
	TString result(*this);
	char* vd = new char[length];
	int p = 0;


	for (int i = 0; i < length; i++) {

		bool pr = true;

		for (int j = 0; j <= i; j++) {
			if (result[i] == vd[j]) {
				pr = false;
				break;
			}
		}

		if (pr == true) {
			vd[p] = result[i];
			p++;
		}

		r = p;
	}
	return vd;
}


ostream& operator << (ostream& ost, const TString& s)
{
	ost << s.str;
	return ost;
}

istream& operator >> (istream& ist, TString& s)
{
	if (s.str != nullptr)
	{
		delete[] s.str;
		s.str = nullptr;
	}
	char* result = new char[9999];
	ist >> result;
	TString st(result);
	s = st;
	delete[] result;
	return ist;
}
