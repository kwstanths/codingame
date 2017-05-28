#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
	int n;
	cin >> n; cin.ignore();


	int v;
	cin >> v; cin.ignore();
	unsigned long prev_max = v;
	unsigned long curr_diff = 0;
	for (int i = 1; i < n; i++) {
		int v;
		cin >> v; cin.ignore();

		if (v < prev_max){
			if (curr_diff < prev_max - v){
				curr_diff = prev_max - v;
			}
		}else if (v > prev_max) prev_max = v;

	}

	signed long int diff = curr_diff * (-1);
	cout << diff << endl;
}
