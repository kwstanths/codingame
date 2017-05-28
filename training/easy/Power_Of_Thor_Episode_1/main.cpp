#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
	int lightX; // the X position of the light of power
	int lightY; // the Y position of the light of power
	int initialTX; // Thor's starting X position
	int initialTY; // Thor's starting Y position
	cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
	int moves_horizontal = initialTX - lightX;
	int moves_vertical = initialTY - lightY;

	// game loop
	while (1) {
		int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
		cin >> remainingTurns; cin.ignore();

		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;

		if (moves_horizontal > 0){
			//left
			moves_horizontal--;
			if (moves_vertical > 0){
				cout << "NW" << endl;
				moves_vertical--;
			}else if (moves_vertical < 0){
				cout << "SW" << endl;
				moves_vertical++;
			}else {
				cout << "W" << endl;
			}
		}else if (moves_horizontal < 0){
			//right
			moves_horizontal++;
			if (moves_vertical > 0){
				cout << "NE" << endl;
				moves_vertical--;
			}else if (moves_vertical < 0){
				cout << "SE" << endl;
				moves_vertical++;
			}else {
				cout << "E" << endl;
			}    
		}else{
			moves_vertical--;
			if (moves_vertical > 0){
				cout << "N" << endl;    
			}else{
				cout << "S" << endl;
			}    
		}


	}
}
