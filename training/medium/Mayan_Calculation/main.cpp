#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

#define MAX_L 100
#define MAX_H 100
#define MAX_S1 1000
#define MAX_S2 1000

char characters[MAX_H][20*MAX_L];
char first_number[MAX_S1][MAX_L];
char second_number[MAX_S2][MAX_L];

int pop_digit(deque<int>& mq){
	int temp = mq.front();
	mq.pop_front();
	return temp;
}

void print_digit(int digit, int H, int L){
	cerr << "Digit: " << digit << endl;
	for(int i=0; i<H; i++){
		for(int j=0; j<L; j++){
			cout << characters[i][L*digit + j];
		}
		cout << endl;
	}
}

/*
   Find the digit based on a digits  table
 */
int find_digit(char number[][MAX_L], int offset, int L){

	for(int i=0; i<20; i++){
		int equal = 0;
		int j=0;
		while(equal == 0 && j<L){
			equal = memcmp(characters[j] +L*i, number[j+offset], sizeof(char)*L);
			if (equal==0) j++;
		}
		if (j == L) {
			return i;
		}

	}
	cerr << "Internal error" << endl;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int L;
	int H;
	cin >> L >> H; cin.ignore();
	for (int i = 0; i < H; i++) {
		string numeral;
		cin >> numeral; cin.ignore();
		cerr << numeral << endl;
		memcpy(characters[i], numeral.c_str(), sizeof(char)*20*L);
	}

	int S1;
	cin >> S1; cin.ignore();
	for (int i = 0; i < S1; i++) {
		string num1Line;
		cin >> num1Line; cin.ignore();
		cerr << num1Line << endl;
		memcpy(first_number[i], num1Line.c_str(), sizeof(char)*MAX_L);
	}
	int S2;
	cin >> S2; cin.ignore();
	for (int i = 0; i < S2; i++) {
		string num2Line;
		cin >> num2Line; cin.ignore();
		cerr << num2Line << endl;
		memcpy(second_number[i], num2Line.c_str(), sizeof(char)*MAX_L);
	}
	string operation;
	cin >> operation; cin.ignore();


	//calculate numbers in dec representation
	int digits1 = S1 / H;
	unsigned long int sum1 = 0;
	for(int i=0; i<digits1; i++){
		sum1 += pow(20,digits1-i-1) * find_digit(first_number, i*H, L);
	}

	int digits2 = S2 / H;
	unsigned long int sum2 = 0;
	for(int i=0; i<digits2; i++){
		sum2 += pow(20,digits2-i-1) * find_digit(second_number, i*H, L);
	}
	cerr << "Number 1:" << sum1 << ", Number 2:" << sum2 << endl;

	//calculate result in dec representation
	unsigned long int result;
	if (operation == "*") result = sum1*sum2;
	else if (operation == "/") result = sum1/sum2;
	else if (operation == "+") result = sum1+sum2;
	else if (operation == "-") result = sum1-sum2;
	cerr << "Result: " << result << endl;

	//calculate digits in 20-base representation
	deque<int> digits;
	int mul = 20;
	if (result == 0) digits.push_front(0);
	else
		while(result > 0){
			digits.push_front(result % 20);
			result /= 20;
		}

	//print output
	while(!digits.empty()) print_digit(pop_digit(digits), H, L);    


}

