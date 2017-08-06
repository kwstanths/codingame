#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_W 20
#define MAX_H 20
#define MAX_T 14

typedef struct room{
    map<string, string> choices;
} room_t;

int main()
{
    room_t rooms[MAX_T];
    rooms[1].choices["LEFT"] = "BOT";
    rooms[1].choices["TOP"] = "BOT";
    rooms[1].choices["RIGHT"] = "BOT";
    rooms[2].choices["LEFT"] = "RIGHT";
    rooms[2].choices["RIGHT"] = "LEFT";
    rooms[3].choices["TOP"] = "BOT";
    rooms[4].choices["TOP"] = "LEFT";
    rooms[4].choices["RIGHT"] = "BOT";
    rooms[5].choices["TOP"] = "RIGHT";
    rooms[5].choices["LEFT"] = "BOT";
    rooms[6].choices["RIGHT"] = "LEFT";
    rooms[6].choices["LEFT"] = "RIGHT";
    rooms[7].choices["TOP"] = "BOT";
    rooms[7].choices["RIGHT"] = "BOT";
    rooms[8].choices["LEFT"] = "BOT";
    rooms[8].choices["RIGHT"] = "BOT";
    rooms[9].choices["TOP"] = "BOT";
    rooms[9].choices["LEFT"] = "BOT";
    rooms[10].choices["TOP"] = "LEFT";
    rooms[11].choices["TOP"] = "RIGHT";
    rooms[12].choices["RIGHT"] = "BOT";
    rooms[13].choices["LEFT"] = "BOT";
     
    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();
    
    int labr [MAX_H][MAX_W];
    for (int i = 0; i < H; i++) {
        for(int j=0; j<W; j++){
            int room_type;
            cin >> room_type;
            labr[i][j] = room_type;
        }
    }
    
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();


    // game loop
    while (1) {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();
        
        string direction = rooms[labr[YI][XI]].choices.find(POS)->second;
        if (direction == "BOT") cout << XI << " " << YI + 1 << endl;
        if (direction == "LEFT") cout << XI -1 << " " << YI << endl;
        if (direction == "RIGHT") cout << XI + 1 << " " << YI << endl;
    }
}
