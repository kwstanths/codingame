#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	string MESSAGE;
	getline(cin, MESSAGE);


	char text[100];
	memset(text, '\0', sizeof(char)*100);
	memcpy(text, MESSAGE.c_str(), sizeof(char)*MESSAGE.length());


	std::vector<int> codes;
	for(int i=0; i < MESSAGE.length(); i++){
		char letter = text[i];
		int code = (int)letter;
		codes.push_back((code & 0x40)?1:0);
		codes.push_back((code & 0x20)?1:0);
		codes.push_back((code & 0x10)?1:0);
		codes.push_back((code & 0x08)?1:0);
		codes.push_back((code & 0x04)?1:0);
		codes.push_back((code & 0x02)?1:0);
		codes.push_back((code & 0x01)?1:0);
	}

	if (codes[0] == 1) cout << "0 0";
	else cout << "00 0";
	int previous_code = codes[0];

	for(int i=1; i<codes.size(); i++){
		if (codes[i] == previous_code) cout << "0";
		else if (codes[i] == 1) {
			previous_code = 1;
			cout << " 0 0";
		}
		else {
			previous_code = 0;
			cout << " 00 0";
		}
	}

}
