#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

void head_towards(int goal, int current, string direction){
	if (current > goal && direction == "RIGHT") cout << "BLOCK" << endl;
	else if (current > goal && direction == "LEFT") cout << "WAIT" << endl;
	else if (current < goal && direction == "RIGHT") cout << "WAIT" << endl;
	else if (current < goal && direction == "LEFT") cout << "BLOCK" << endl;
	else cout << "WAIT" << endl;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int nbFloors; // number of floors
	int width; // width of the area
	int nbRounds; // maximum number of rounds
	int exitFloor; // floor on which the exit is found
	int exitPos; // position of the exit on its floor
	int nbTotalClones; // number of generated clones
	int nbAdditionalElevators; // ignore (always zero)
	int nbElevators; // number of elevators
	cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();

	int elevators[15];
	memset(elevators, -1, sizeof(int)*15);
	for (int i = 0; i < nbElevators; i++) {
		int elevatorFloor; // floor on which this elevator is found
		int elevatorPos; // position of the elevator on its floor
		cin >> elevatorFloor >> elevatorPos; cin.ignore();
		elevators[elevatorFloor] = elevatorPos;
	}

	int i = 1;
	// game loop
	while (1) {
		int cloneFloor; // floor of the leading clone
		int clonePos; // position of the leading clone on its floor
		string direction; // direction of the leading clone: LEFT or RIGHT
		cin >> cloneFloor >> clonePos >> direction; cin.ignore();

		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;
		if (cloneFloor == -1) cout << "WAIT" << endl;
		else if (cloneFloor == exitFloor)
			head_towards(exitPos, clonePos, direction);
		else if (elevators[cloneFloor] != -1 )
			head_towards(elevators[cloneFloor], clonePos, direction);
		else cout << "impossibru" << endl;

	}
}
