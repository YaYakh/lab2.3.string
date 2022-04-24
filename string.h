#pragma once
#include <iostream>
#include <string>


using namespace std;

class TString
{
public:

	int GetLn();
	char* GetStr();

	TString();
	~TString();
	TString(const char* str);
	TString(const TString& per);
	
	TString operator * (int k); //доп
	TString operator + (const TString& per);
	TString& operator = (const TString& per);
	TString& operator = (const char* per);
	bool operator == (const TString& per);
	char operator [] (int i);
	bool operator > (const TString& n);
	bool operator < (const TString& n);

	int Split(char**& arr, const char a)const;

	int SymbPos(char c);

	int PdSlPos(const char* n);

	char* WthRep(int& r);

	friend ostream& operator << (ostream& ost, const TString& n);
	friend istream& operator >> (istream& ist, TString& n);

private:

	char* str;
	int length;

};