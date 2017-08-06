#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

typedef struct node{
    int gain_;
    int next_;
    node(int gain, int next): gain_(gain), next_(next) {} 
} node_t;

int main()
{
    int places;
    int days;
    int ngroups;
    cin >> places >> days >> ngroups; cin.ignore();
    
    vector<int> groups;
    for (int i = 0; i < ngroups; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        groups.push_back(Pi);
    }
    
    //Calculate where we will land in the queue, and how much we will gain,
    //if we started from every possible group
    vector<node_t> nodes;
    for(int i=0; i<ngroups; i++){
        
        nodes.push_back(node_t(0,0));
        int index = i;
        while(true) {
            if (nodes[i].gain_ + groups[index] <= places){
                nodes[i].gain_ += groups[index];
            }else break;
            
            index++;
            if (index == ngroups) index = 0;
            if (index == i) break;

        }
        nodes[i].next_ = index;
    }
    
    int index = 0;
    unsigned long int coins = 0;
    for(int i=0; i<days; i++){
        coins += nodes[index].gain_;
        index = nodes[index].next_;
    }
    
    cout << coins << endl;
    
    

}
