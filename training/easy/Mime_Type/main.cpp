#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct extension_type{
	string EXT;
	string MT;
	extension_type(string EXT_, string MT_): EXT(EXT_), MT(MT_) {};
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int N;
	cin >> N; cin.ignore();
	int Q;
	cin >> Q; cin.ignore();

	map<string, string> types;
	for (int i = 0; i < N; i++) {
		string EXT;
		string MT;
		cin >> EXT >> MT; cin.ignore();
		transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
		types[EXT] = MT;
	}

	for (int i = 0; i < Q; i++) {
		string FNAME; // One file name per line.
		getline(cin, FNAME);

		int dot_pos = FNAME.find_last_of(".");
		if (dot_pos == string::npos) {
			cout << "UNKNOWN" << endl;
			continue;
		}

		string extension = FNAME.substr(dot_pos+1, FNAME.length());
		transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

		if (types.find(extension) != types.end()) std::cout << types[extension] << endl;
		else cout << "UNKNOWN" << endl;
	}

}
