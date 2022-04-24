using namespace std;
#include<iostream>
#include "string.h"



int main()
{
	TString st1("aaaabbbcxxxxxybbbbaacxcxcx");
	TString st2("bbcccaaaaaXyZabX");
	TString st3("");
	TString st4(st1);
	TString st5("");

	cout << "st1: " << st1 << endl << "st2: " << st2 << "\n" <<  "st3: " << st3 << "\n" << "st4: " << st4 << endl;

	
	st3 = st1 + st2;
	cout << "\n+ :   st3 = st1 + st2" << endl << "st3: " << st3 << "\n" << endl;

	st4 = st3;
	cout << "= :   st4 = st3" << endl << "st4: " << st4 << "\n" << endl;

	cout << "== : " << endl;
	if (st3 == st4) {
		cout << "st3 == st4" << endl;
	}
	else {
		cout << "st3 != st4" << endl;
	}

	cout << "\n< or > : " << endl;
	if (st2 > st3) {
		cout << "st2 > st3" << endl;
	}
	else {
		cout << "st2 < st3" << endl;
	}

	
	cout << "\n[] : st2[7]: " << st2[7] << "\n" << endl;

	
	//—чЄт позиции начинаетс€ с нул€ и т.д.
	cout << "First Pod Slovo 'xyb' in st1 : " << st1.PdSlPos("xyb") << endl;
	cout << "\nfirst symbol 'y' in st2 : " << st2.SymbPos('y') << endl;


	char** arr;
	int pos;
	pos = st1.Split(arr, 'y'); 
	cout << "\nSplit st1 on symbol 'y' : \n";
	for (int i = 0; i < pos; i++) {
		cout << arr[i] << endl;
	}
	delete[] arr;

	cout << "\nRepeat st1 3 times: ";
	st5 = st1 * 3;
	cout << st5 << endl;

	int k;
	cout << "\n\nst2: " << st2 << endl;
	cout << "st2 without repetition: ";
	st5 = st2.WthRep(k);
	for (int i = 0; i < k; i++) {
		cout << st5[i];
	}
	cout << endl;


	return 0;
}
