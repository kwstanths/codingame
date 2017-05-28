#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int letter_index(string letter){
	if (letter == "A") return 0;
	if (letter == "B") return 1;
	if (letter == "C") return 2;
	if (letter == "D") return 3;
	if (letter == "E") return 4;
	if (letter == "F") return 5;
	if (letter == "G") return 6;
	if (letter == "H") return 7;
	if (letter == "I") return 8;
	if (letter == "J") return 9;
	if (letter == "K") return 10;
	if (letter == "L") return 11;
	if (letter == "M") return 12;
	if (letter == "N") return 13;
	if (letter == "O") return 14;
	if (letter == "P") return 15;
	if (letter == "Q") return 16;
	if (letter == "R") return 17;
	if (letter == "S") return 18;
	if (letter == "T") return 19;
	if (letter == "U") return 20;
	if (letter == "V") return 21;
	if (letter == "W") return 22;
	if (letter == "X") return 23;
	if (letter == "Y") return 24;
	if (letter == "Z") return 25;
	return 26;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int L;
	cin >> L; cin.ignore();
	int H;
	cin >> H; cin.ignore();
	string T;
	getline(cin, T);

	//turn everything to upper case
	transform(T.begin(), T.end(), T.begin(), ::toupper);

	//Data representation
	char alphabet[30][27*30];
	//Initialize everything to whitespace
	memset(alphabet, ' ', sizeof(char)*H*27*L);
	for (int i = 0; i < H; i++) {
		string ROW;
		getline(cin, ROW);
		memcpy(alphabet[i], ROW.c_str(), sizeof(char) * 27 * L);
	}

	//print
	for(int row=0; row<H; row++){
		for(int letter=0; letter<T.size(); letter++){
			string character = T.substr(letter,1);
			int index = letter_index(character);
			for(int row_letter=0; row_letter<L; row_letter++)
				cout << alphabet[row][index*L+row_letter];

		}
		cout << endl;
	}
}
