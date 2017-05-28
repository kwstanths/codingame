#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define MAX_N 500

typedef struct node{
	int id_;
	bool is_gateway_;
	vector<int> neighbors_;
	node(int id, int is_gateway): id_(id), is_gateway_(is_gateway){};
} node_t;


vector<node_t *> nodes;

void BFS(int root){
	std::queue<int> node_queue;
	std::set<int> visited;

	node_queue.push(root);
	while(!node_queue.empty()){
		int current = node_queue.front();
		visited.insert(current);
		node_queue.pop();

		for(int i=0; i<nodes.at(current)->neighbors_.size(); i++){
			int neighbor = nodes.at(current)->neighbors_.at(i);
			if (nodes.at(neighbor)->is_gateway_){
				cout << current << " " << neighbor << endl;
				return;
			} else if (visited.find(neighbor) == visited.end())
				node_queue.push(neighbor);
		}

	}
}


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int N; // the total number of nodes in the level, including the gateways
	int L; // the number of links
	int E; // the number of exit gateways
	cin >> N >> L >> E; cin.ignore();

	for(int i=0; i<N; i++) nodes.push_back(new node_t(i,0));

	for (int i = 0; i < L; i++) {
		int N1; // N1 and N2 defines a link between these nodes
		int N2;
		cin >> N1 >> N2; cin.ignore();

		nodes.at(N1)->neighbors_.push_back(N2);
		nodes.at(N2)->neighbors_.push_back(N1);
	}
	for (int i = 0; i < E; i++) {
		int EI; // the index of a gateway node
		cin >> EI; cin.ignore();
		nodes.at(EI)->is_gateway_ = 1;
	}

	// game loop
	while (1) {
		int SI; // The index of the node on which the Skynet agent is positioned this turn
		cin >> SI; cin.ignore();

		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;
		BFS(SI);

		// Example: 0 1 are the indices of the nodes you wish to sever the link between
	}
}
