#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <set>

using namespace std;

#define MAX_N 10000
#define MAX_X 10000
#define MAX_Y 10000

bool arr[MAX_X][MAX_Y];

int depth(int node){
    int max = 0;
    for(int j=0; j<MAX_Y; j++)
        if(arr[node][j]){
            int tdepth = depth(j);
            if (tdepth > max) max = tdepth;
        }
    return max + 1;
}

void findConnectedComponents(deque<int>& comp){

}

int main()
{
    int n; // the number of relationships of influence
    cin >> n; cin.ignore();
    
    int max_node = -1;
    memset(arr,0,sizeof(bool)*MAX_X*MAX_Y);
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        if (x > max_node) max_node = x;
        if (y > max_node) max_node = y;
        
        arr[x][y] = true;
    }
    
    //bad solution. Does more work. 
    //Best solution whould be to find connected components, and find the max of their depths
    int max_seq = 0;
    for(int i=0; i<max_node; i++){
        int d = depth(i);
        if (d > max_seq) max_seq = d;
    }
    cout << max_seq << endl;
}
