#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

#define MAX_R 100
#define MAX_C 200

int R; // number of rows.
int C; // number of columns.
int A; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.

char grid[MAX_R][MAX_C];

using Pos = pair<int,int>;

vector<Pos> GetNeighbors(Pos src) {
    if (grid[src.first][src.second] == '?') return vector<Pos>();
    
    vector<Pos> neighbors;
    
    if (grid[src.first][src.second-1] != '#') neighbors.push_back(make_pair(src.first, src.second-1));
    if (grid[src.first][src.second+1] != '#') neighbors.push_back(make_pair(src.first, src.second+1));
    if (grid[src.first-1][src.second] != '#') neighbors.push_back(make_pair(src.first-1, src.second));
    if (grid[src.first+1][src.second] != '#') neighbors.push_back(make_pair(src.first+1, src.second));
    
    return neighbors;
}

template<typename T> T pop_top(stack<T>& cont){
    T temp = cont.top();
    cont.pop();
    return temp;
}

vector<Pos> dijkstra_path(Pos src, char dst){
    
    int distances[R][C];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            distances[i][j] = INT_MAX;
    
    Pos parent[R][C];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            parent[i][j] = {INT_MAX, INT_MAX};
            
    vector<Pos> nodes;

    distances[src.first][src.second] = 0;
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++)
            nodes.push_back({x, y});
    }

    while (!nodes.empty()) {
        int minimum_distance_index = 0;
        int minimum_distance = INT_MAX;
        for (int i=0; i<nodes.size(); i++) {
            int temp_min = distances[nodes[i].first][nodes[i].second];
            if (temp_min < minimum_distance) {
                minimum_distance = temp_min;
                minimum_distance_index = i;
            }
        }
        
        if (minimum_distance == INT_MAX) {
            cerr << "Internal error" << endl;
            return vector<Pos>();
        }
            
        Pos curr_node = nodes[minimum_distance_index];
        cerr << "Current node: " << curr_node.first << " " << curr_node.second << " " << grid[curr_node.first][curr_node.second] << endl;
        nodes.erase(nodes.begin() + minimum_distance_index);

        if (grid[curr_node.first][curr_node.second] == dst) {
            cerr << "Found it!" << endl;
            stack<Pos> inverse_path;
            Pos node = curr_node;
            while (parent[node.first][node.second].first != INT_MAX && parent[node.first][node.second].second != INT_MAX) {
                inverse_path.push(node);
                node = parent[node.first][node.second];
            }

            vector<Pos> path;
            while (!inverse_path.empty()) path.push_back(pop_top(inverse_path));
        
            return path;
        }
        
        //Update minimum distance for neighbors
        vector<Pos> neighbors = GetNeighbors(curr_node);
        for(int i=0; i<neighbors.size(); i++){
            Pos n = neighbors[i];
            cerr << n.first << " " << n.second << endl;
            // Distance step is 1 weight
            if (distances[curr_node.first][curr_node.second] + 1 < distances[n.first][n.second]){
                distances[n.first][n.second] = distances[curr_node.first][curr_node.second] + 1;
                parent[n.first][n.second] = curr_node;
            }
        }
        
    }

    return vector<Pos>();
}


int main() {
    cin >> R >> C >> A; cin.ignore();

    bool isVisited = false;

    while (1) {
        int KR; // row where Kirk is located.
        int KC; // column where Kirk is located.
        cin >> KR >> KC; cin.ignore();
        
        for (int i = 0; i < R; i++) {
            string ROW; // C of the characters in '#.TC?' (i.e. one line of the ASCII maze).
            cin >> ROW; cin.ignore();
           
            strcpy(grid[i], ROW.c_str());
        }
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++)
                if (i==KR && j ==KC) cerr << "O";
                else cerr << grid[i][j];
            cerr << endl;
        }
        cerr << endl;
        
        cerr << "Point: " << KR << " " << KC << endl;
        if (grid[KR][KC] == 'C') isVisited = true;
        if (isVisited) cerr << "Control room visited" << endl;
        
        vector<Pos> path;
        if (isVisited) path = dijkstra_path({KR, KC}, 'T');
        else {
            path = dijkstra_path({KR, KC}, 'C');
            if (path.empty())
                path = dijkstra_path({KR, KC}, '?');
        }
        for(int i=0; i<path.size(); i++) cerr << path[i].first << " " << path[i].second << endl;
        
        if (path[0].first > KR)
            cout << "DOWN" << endl;
        else if (path[0].first < KR)
            cout << "UP" << endl;
        else if (path[0].second > KC)
            cout << "RIGHT" << endl;
        else
            cout << "LEFT" << endl;
        
        
    }
}
