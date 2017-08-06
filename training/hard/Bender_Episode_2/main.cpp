#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define N_MAX 10000;

typedef struct room{
    int id_;
    int worth_;
    int n1_;
    int n2_;
    room(int id, int worth, int n1, int n2): id_(id), worth_(worth), n1_(n1), n2_(n2) {};
    room(){}
    
} room_t;
    
int bfs(vector<room_t>& r){
    
    vector<int> acc(r.size(), 0);
    queue<pair<int,int> > nodes = queue<pair<int,int> >();
    nodes.push(make_pair(0,0));
    
    while(!nodes.empty()){
        pair<int,int> temp_room = nodes.front();
        nodes.pop();
        int room_prev = temp_room.first;
        int room_curr = temp_room.second;
        
        if (acc[room_curr] < acc[room_prev] + r[room_curr].worth_){
            acc[room_curr] = acc[room_prev] + r[room_curr].worth_;
            if (r[room_curr].n1_ != -1) nodes.push(make_pair(room_curr, r[temp_room.second].n1_));
            if (r[room_curr].n2_ != -1) nodes.push(make_pair(room_curr, r[temp_room.second].n2_));
        }
    }
    
    int mmax=0;
    for(int i=0; i<acc.size(); i++) mmax = max(acc[i], mmax);
    
    return mmax;
}


int main() {
    int N;
    cin >> N; cin.ignore();

    vector<room_t> rooms(N);
    for (int i = 0; i < N; i++) {
        string id_str, worth_str, n1_str, n2_str;
        int id, worth, n1, n2;
        cin >> id_str;
        cin >> worth_str;
        cin >> n1_str;
        cin >> n2_str;
        id = stoi(id_str);
        worth = stoi(worth_str);
        n1 = (n1_str=="E")?-1:stoi(n1_str);
        n2 = (n2_str=="E")?-1:stoi(n2_str);
        rooms[i] = room_t(id,worth,n1,n2);
    }

   cout << bfs(rooms);
}
