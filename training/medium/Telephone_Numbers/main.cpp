#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node{
    int number_;
    vector<struct node*> kids;
    
    node(int number): number_(number){};
    
    void insert(string number){
        if (number.length() == 0) return;
        
        int first_digit = stoi(number.substr(0,1));
        string rest_number = number.erase(0,1);
        
        bool found = false;
        for(int i=0; i<kids.size(); i++){
            if (kids[i]->number_ == first_digit){
                found = true;
                kids[i]->insert(rest_number);
            }
        }
        
        if (!found) {
            kids.push_back(new node(first_digit));
            kids[kids.size()-1]->insert(rest_number);
        }
    }
    
    int count_nodes(){
        int sum = 1;
        for(int i=0; i<kids.size(); i++) sum += kids[i]->count_nodes();
        return sum;
    }
    
} node_t;

class Tree{
private:
    node_t * root_;
public:
    Tree(){
        root_ = new node_t(-1);
    }
    void insert(string number){
        root_->insert(number);
    }
    
    int count_nodes(){
        return root_->count_nodes() -1;
    }

};

int main()
{
    int N;
    cin >> N; cin.ignore();
    Tree t;
    for (int i = 0; i < N; i++) {
        string telephone;
        cin >> telephone; cin.ignore();
        t.insert(telephone);
    }
    
    cout << t.count_nodes();
}
