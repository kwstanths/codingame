#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

#define C_MAX 100
#define L_MAX 100


string grid[L_MAX][C_MAX];

bool canGo(string direction, int x, int y){
    if (direction == "SOUTH" && grid[x+1][y] != "X" && grid[x+1][y] != "#" ) return true;
    else if (direction == "EAST" && grid[x][y+1] != "X" && grid[x][y+1] != "#") return true;
    else if (direction == "NORTH" && grid[x-1][y] != "X" && grid[x-1][y] != "#") return true;
    else if (direction == "WEST" && grid[x][y-1] != "X" && grid[x][y-1] != "#") return true;
    else return false;
}

bool isConstantObstacle(string direction, int x, int y){
    if (direction == "SOUTH" && grid[x+1][y] == "#") return true;
    else if (direction == "EAST" && grid[x][y+1] == "#") return true;
    else if (direction == "NORTH" && grid[x-1][y] == "#") return true;
    else if (direction == "WEST" && grid[x][y-1] == "#") return true;
    else return false;
}

void move(string direction, int * x, int * y){
    if (direction == "SOUTH") (*x)++;
    if (direction == "EAST") (*y)++;
    if (direction == "NORTH") (*x)--;
    if (direction == "WEST") (*y)--;  
}


string get_state(int x, int y, string comp, string direction, int beer, int reverted_prio){
    string state = to_string(x)+to_string(y)+comp+direction+to_string(beer)+to_string(reverted_prio);
    return state;
}

int main()
{
    int L;
    int C;
    cin >> L >> C; cin.ignore();
    
    int current_x, current_y;
    int teleporter1_x=-1, teleporter1_y=-1, teleporter2_x=-1, teleporter2_y=-1;
    
    for (int i = 0; i < L; i++) {
        string row;
        getline(cin, row);
        for(int j=0; j<C; j++){
            string temp = row.substr(j,1);
            cerr << temp;
            grid[i][j] = temp;
            if (temp == "@"){
                current_x = i;
                current_y = j;
            }else if (temp == "T") {
                if (teleporter1_x == -1){
                    teleporter1_x = i;
                    teleporter1_y = j;
                }else{
                    teleporter2_x = i;
                    teleporter2_y = j;
                }
            }
        }
       cerr << endl;
         
    }
 
    string current_direction = "SOUTH";
    int isReverted = -1;
    int hasBeer = -1;
    int justTeleported = -1;
    
    deque<string> fdir;
    fdir.push_back("SOUTH");
    fdir.push_back("EAST");
    fdir.push_back("NORTH");
    fdir.push_back("WEST");
    deque<string> bdir;
    bdir.push_back("WEST");
    bdir.push_back("NORTH");
    bdir.push_back("EAST");
    bdir.push_back("SOUTH");
    
    deque<string> movements;
    deque<string> dir = fdir;
    map<string, int> vstates;
    while(1) {
        if (grid[current_x][current_y] == "$") break;
        
        string current_state = get_state(current_x, current_y, grid[current_x][current_y], current_direction, hasBeer, isReverted);
        if (vstates.find(current_state) != vstates.end()) {
            cout << "LOOP" << endl;
            return 0;
        }else vstates[current_state] = 1;
        
        if (grid[current_x][current_y] == "B"){
            hasBeer *= -1;
        }
        
        if (grid[current_x][current_y] == "I"){
            isReverted *= -1;
            if(isReverted == 1) dir = bdir;
            else dir = fdir;
            
        }
        
        if (grid[current_x][current_y] == "T"){
            justTeleported *= -1;
            if (current_x == teleporter1_x && current_y == teleporter1_y) {
                current_x = teleporter2_x;
                current_y = teleporter2_y;
            }else{
                current_x = teleporter1_x;
                current_y = teleporter1_y;
            }
        }
        
        if (!canGo(current_direction, current_x, current_y) && hasBeer == 1 && !isConstantObstacle(current_direction,current_x,current_y)){
            move(current_direction, &current_x, &current_y);
            grid[current_x][current_y] = " ";
            vstates.clear();
            movements.push_back(current_direction);
            continue;
        }
        
        string new_direction = current_direction;
        if (grid[current_x][current_y] == "S") new_direction = "SOUTH";
        else if (grid[current_x][current_y] == "E") new_direction = "EAST";
        else if (grid[current_x][current_y] == "N") new_direction = "NORTH";
        else if (grid[current_x][current_y] == "W") new_direction = "WEST";
        current_direction = new_direction;
        
        
        if (canGo(current_direction, current_x, current_y)) {
            move(current_direction, &current_x, &current_y);
            movements.push_back(current_direction);
        } else {
            for(int i=0; i<dir.size(); i++)
                if (canGo(dir[i], current_x, current_y)){
                    current_direction = dir[i];
                    move(current_direction, &current_x, &current_y);
                    movements.push_back(current_direction);
                    break;
                }
        }
    }
    
    for(int i=0; i<movements.size(); i++) cout << movements[i] << endl;
    
    
}
