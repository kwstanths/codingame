#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int n; // the number of temperatures to analyse
	cin >> n; cin.ignore();

	//read and store smallest numbers
	int current_distance = 10000000;
	std::vector<int> numbers;
	for(int i=0; i<n; i++){
		string str_temp;
		cin >> str_temp;
		int current_number = stoi(str_temp);
		if (abs(current_number) < current_distance){
			current_distance = abs(current_number);
			numbers.clear();
			numbers.push_back(current_number);
		}else if (current_number == current_distance) numbers.push_back(current_number);
	}

	//calculate and print output
	bool negative = false;
	bool positive = false;
	for(int i=0; i <numbers.size(); i++) {
		if (numbers.at(i) < 0) negative = true;
		else if (numbers.at(i) > 0) positive = true;
	}

	if (numbers.size() == 0) cout << "0" << endl;
	if (!positive && negative) cout << numbers.at(0);
	else cout << abs(numbers.at(0));

}
