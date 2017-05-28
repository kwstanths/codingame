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
	int W; // width of the building.
	int H; // height of the building.
	cin >> W >> H; cin.ignore();
	int N; // maximum number of turns before game over.
	cin >> N; cin.ignore();
	int X0;
	int Y0;
	cin >> X0 >> Y0; cin.ignore();

	int W_L = 0;
	int W_R = W;
	int H_U = 0;
	int H_D = H;
	// game loop
	while (1) {
		string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
		cin >> bombDir; cin.ignore();

		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;
		if (bombDir == "U") {
			H_D = Y0;
			Y0 -= ceil(Y0-H_U)/2;
		}else if (bombDir == "D"){
			H_U = Y0;
			Y0 += ceil(H_D-Y0)/2;
		}else if (bombDir == "L"){
			W_R = X0;
			X0 -= ceil(X0-W_L)/2;
		}else if (bombDir == "R"){
			W_L = X0;
			X0 += ceil(W_R-X0)/2;
		}else if (bombDir == "UR"){
			H_D = Y0;
			W_L = X0;
			Y0 -= ceil(Y0-H_U)/2;
			X0 += ceil(W_R-X0)/2;
		}else if (bombDir == "DR"){
			H_U = Y0;
			W_L = X0;
			Y0 += ceil(H_D-Y0)/2;
			X0 += ceil(W_R-X0)/2;
		}else if (bombDir == "DL"){
			H_U = Y0;
			W_R = X0;
			Y0 += ceil(H_D-Y0)/2;
			X0 -= ceil(X0-W_L)/2;
		}else if (bombDir == "UL"){
			H_D = Y0;
			W_R = X0;
			Y0 -= ceil(Y0-H_U)/2;
			X0 -= ceil(X0-W_L)/2;
		}
		cout << X0 << " " << Y0 << endl;


	}
}
