#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

#define MAX_N 150000
#define MAX_X 200000
#define MAX_Y 200000


typedef struct node{
    int dist_;
    vector<int> neighs_;
    node(int dist):dist_(dist) {};
} node_t;

node_t * graph[MAX_X];

int dfs(deque<int>& nodes, map<int,int>& v, int distance) {
    
    if (nodes.empty()) return distance;
    
    int front_node = nodes.back();
    nodes.pop_back();
    
    //cout << front_node << " " << distance << endl;
    
    if (v.find(front_node) != v.end()) return distance;
    v[front_node] = 1;
    
    int dmax = 0;
    for(int i=0; i<graph[front_node]->neighs_.size(); i++) {
        nodes.push_back(graph[front_node]->neighs_.at(i));
        dmax = max(dfs(nodes, v, distance+1), dmax);
    }
        
    
    return dmax;
}

int find_farthest_node(deque<int>& nodes, map<int, int>& v){
    
    int leaf_node = -1;
    while(!nodes.empty()){
        int front_node = nodes.front();
        nodes.pop_front();
        
        if (v.find(front_node) != v.end()) continue;
        v[front_node] = 1;
        leaf_node = front_node;
    
        for(int i=0; i<graph[front_node]->neighs_.size(); i++)
            nodes.push_back(graph[front_node]->neighs_.at(i));
        
    }
    
    return leaf_node;
    
}

int main() {
    int n; // the number of adjacency relations
    cin >> n; cin.ignore();
    
    int max_nodes = 0;
    memset(graph, NULL, sizeof(node_t *) * MAX_X);
    for (int i = 0; i < n; i++) {
        int xi; // the ID of a person which is adjacent to yi
        int yi; // the ID of a person which is adjacent to xi
        cin >> xi >> yi; cin.ignore();
        
        if (graph[xi] == NULL) graph[xi] = new node_t(0);
        if (graph[yi] == NULL) graph[yi] = new node_t(0);
    
        graph[xi]->neighs_.push_back(yi);
        graph[yi]->neighs_.push_back(xi);
        
        if (xi > max_nodes) max_nodes = xi;
        if (yi > max_nodes) max_nodes = yi;
    }
    
    int farthest_leaf;
    {
        deque<int> nodes;
        map<int,int> v;
        nodes.push_back(max_nodes);
        farthest_leaf = find_farthest_node(nodes, v);
    }
    
    deque<int> nodes;
    map<int,int> v;
    nodes.push_back(farthest_leaf);    
    
    cout << dfs(nodes, v, 0)/2 << endl;
    
}
