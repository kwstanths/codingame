#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <map>

using namespace std;

#define MAX_WIDTH 10000
#define MAX_HEIGHT 10000

int H;
int L;

char grid[MAX_HEIGHT][MAX_WIDTH];
int water[MAX_HEIGHT][MAX_WIDTH];


int BFS(int x, int y){
    if (water[x][y] != 0) {
        return water[x][y];
   }
    queue<pair<int,int>> nodes;
    vector<vector<bool>> visited(H, vector<bool>(L, false));
    vector<pair<int,int>> water_nodes;
    
    int lake_size = 0;
    
    nodes.push({x,y});
    while(!nodes.empty()){
        pair<int,int> temp = nodes.front();
        nodes.pop();
        if (visited[temp.first][temp.second]) continue;
        visited[temp.first][temp.second] = true;

        if (grid[temp.first][temp.second] == '#') continue;
        if (grid[temp.first][temp.second] == 'O'){
            lake_size++;
            water_nodes.push_back({temp.first, temp.second});
        } 
        
        if (temp.first>0 && grid[temp.first-1][temp.second] == 'O') nodes.push({temp.first-1,temp.second});
        if (temp.first<H-1 && grid[temp.first+1][temp.second] == 'O') nodes.push({temp.first+1, temp.second});
        if (temp.second>0 && grid[temp.first][temp.second-1] == 'O') nodes.push({temp.first, temp.second-1});
        if (temp.second<L-1 && grid[temp.first][temp.second+1] == 'O') nodes.push({temp.first, temp.second+1});
    }
    
    for(int i=0; i<water_nodes.size(); i++)
        water[water_nodes[i].first][water_nodes[i].second] = lake_size;
        
    return lake_size;
}

int main()
{
    cin >> L; cin.ignore();
    cin >> H; cin.ignore();
    for (int i = 0; i < H; i++) {
        string row;
        getline(cin, row);
        strcpy(grid[i], row.c_str());
    }
    
    int N;
    cin >> N; cin.ignore();
    
    vector<pair<int,int>> cases;
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        cases.push_back(make_pair(Y,X));
    }
    
    memset(water, 0, sizeof(int)*MAX_WIDTH*MAX_HEIGHT);
    for (int i = 0; i < N; i++) {
        int water_size = BFS(cases[i].first, cases[i].second);
        cout << water_size << endl;

    }
}
