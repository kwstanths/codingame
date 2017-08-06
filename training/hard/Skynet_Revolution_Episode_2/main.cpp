#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <limits.h>

using namespace std;

#define MAX_N 500

// typedef struct node{
//     int id_;
//     bool is_gateway_;
//     node(int id, int is_gateway): id_(id), is_gateway_(is_gateway){};
// } node_t;

// typedef struct link{
//     int node1_;
//     int node2_;
//     link(int node1, int node2): node1_(node1), node2_(node2) {};
// } link_t;

vector<vector<int> > adj;
vector<int> gateways;
vector<int> distances;

int nOGs(int node){
    int count = 0;
    for(int i=0; i<adj.size(); i++)
        if (adj[node][i] && gateways[i]) count++;
    
    return count;
}

int BFS(int root, vector<int>& n_q_s, vector<int>& n_q_d){
     std::queue<int> nodes;
     std::set<int> visited;
   
    int number_of_double_nodes = 0; 
     nodes.push(root);
     while(!nodes.empty()){
        int current = nodes.front();
        nodes.pop();
        
        if (visited.find(current) != visited.end()) continue;
        visited.insert(current);
        
        for(int i=0; i<adj.size(); i++){
            if (adj[current][i] == 0) continue;
            nodes.push(i);
        }
        
        if (nOGs(current) == 1) n_q_s.push_back(current); 
        if (nOGs(current) > 1) {
            number_of_double_nodes++;
            n_q_d.push_back(current);
        }
    }
    return number_of_double_nodes;
}

int minDistance(bool * sptSet, int size) {
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < size; v++)
     if (sptSet[v] == false && distances[v] <= min)
         min = distances[v], min_index = v;
  
   return min_index;
}

void dijkstra(int src, int size) {
    bool sptSet[size];
    
    for (int i = 0; i < size; i++)
        distances[i] = INT_MAX, sptSet[i] = false;
  
    distances[src] = 0;
  
    for (int count = 0; count < size-1; count++) {
        int u = minDistance(sptSet, size);
  
        sptSet[u] = true;
  
    for (int v = 0; v < size; v++)
        if (!sptSet[v] && adj[u][v] && distances[u] != INT_MAX  && distances[u]+adj[u][v] < distances[v])
            distances[v] = distances[u] + adj[u][v];
    }
    
}

void sever(int a, int b){
    cout << a << " " << b << endl;
    adj[a][b] = 0;
    adj[b][a] = 0;
}

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    
    adj = vector<vector<int> >(N, vector<int>(N, 0));
    
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        adj[N1][N2] = 1;
        adj[N2][N1] = 1;
    }
    
    gateways = vector<int>(N, 0);
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        gateways[EI] = 1;
    }

    
    distances = vector<int>(N, 0);
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();

        
        if (nOGs(SI) == 2) cout << "This shouldn't happen" << endl;
        else if (nOGs(SI) == 1){
            //If the current node has one only gateway, then we have to choose to sever it
            for(int i=0; i<adj.size(); i++) 
                if (adj[SI][i] == 1 && gateways[i]) sever(SI,i);
        } else {
            //Else if we don't have any adjacent gateway, find a node with two gateways, and sever one of them

            vector<int> nodes_single;
            vector<int> nodes_double;
            int number_of_double_nodes = BFS(SI, nodes_single, nodes_double);
            dijkstra(SI, N);
            cerr << "Double: " << number_of_double_nodes << endl;

                        
            if (number_of_double_nodes == 0){
                //If we dont have any adjacent gateways, and no double nodes, then find the nearest link               
                sort(nodes_single.begin(), nodes_single.end(), 
                    [&SI](int a, int b){
                        int dist1 = distances[a] - nOGs(a);
                        int dist2 = distances[b] - nOGs(b);
                
                        return  dist1 < dist2;
                    }
                );
                int node = nodes_single[0];
                for(int i=0; i<adj.size(); i++) 
                    if (adj[node][i] == 1 && gateways[i]) {
                        sever(node,i);            
                        break;
                    }     
            }else{
                //Else if we dont have any adjacent gateways, and multiple double nodes, make a model of 
                //the next node that the virus will attack
                sort(nodes_double.begin(), nodes_double.end(), 
                    [&SI](int a, int b){
                        int dist1 = distances[a];
                        int dist2 = distances[b];
                
                        return  dist1 <= dist2;
                    }
                );
                //If there is a double node with 1 edge distance, then this one will be the target
                //Else it will be the second one
                int node = nodes_double[0];
                if (distances[nodes_double[0]] == 1) node = nodes_double[0];
                else if (nodes_double.size() >= 2) node = nodes_double[1];
                
                for(int i=0; i<adj.size(); i++) {
                    if (adj[node][i] == 1 && gateways[i]) {
                        sever(node,i);            
                        break;
                    }
                }
            }
            
            
        }
        
    }
    
    
    
}
