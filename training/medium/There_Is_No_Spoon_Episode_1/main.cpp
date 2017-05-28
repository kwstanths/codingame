#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define MAX_HEIGHT 30
#define MAX_WIDTH 30

struct node {
	bool exists;
	bool printed;
};

struct node grid[MAX_HEIGHT][MAX_WIDTH];

string find_horizontal(int i, int j, int width){
	int pos = -1;
	int col = j;
	while(pos == -1 && col < width){
		if (grid[i][col].exists == 1) {
			pos = col;
		}
		col++;
	}

	if (pos == -1) return "-1 -1";
	else return to_string(pos) + " " + to_string(i);
}

string find_vertical(int i, int j, int height){
	int pos = -1;
	int row = i;
	while(pos == -1 && row < height){
		if (grid[row][j].exists == 1){
			pos = row;
		}
		row++;
	}

	if (pos == -1) return "-1 -1";
	else return to_string(j) + " " + to_string(pos);
}

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
	int width; // the number of cells on the X axis
	cin >> width; cin.ignore();
	int height; // the number of cells on the Y axis
	cin >> height; cin.ignore();
	memset(grid, 0, sizeof(struct node)*MAX_HEIGHT*MAX_WIDTH);
	for (int i = 0; i < height; i++) {
		string line; // width characters, each either 0 or .
		getline(cin, line);
		for(int j = 0; j < width; j++) {
			if (line.substr(j,1) == "0") grid[i][j].exists = 1;
		}
	}

	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++)
			cerr << grid[i][j].exists ;
		cerr <<endl;
	}


	for(int j=0; j<width; j++) 
		for(int i=0; i<height; i++){
			if (grid[i][j].exists) cout << j << " " << i << " ";
			else continue;
			cout << find_horizontal(i,j+1, width) << " ";
			cout << find_vertical(i+1,j, height) << endl;
		}

}
