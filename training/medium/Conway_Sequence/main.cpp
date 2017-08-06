#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int pop_front(deque<int>& dq){
    int temp = dq.front();
    dq.pop_front();
    return temp;
}

void swap(deque<int>& a, deque<int>& b){
    deque<int> temp = a;
    a = b;
    b = temp;
}

int main()
{
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();

    deque<int> curr;
    deque<int> next;
    curr.push_back(R);
    
    for(int i=1; i<L; i++){
        while(!curr.empty()){
            int n;
            int instances=0;
            do{
                n = pop_front(curr);
                instances++;
            }while(n == curr.front());
            next.push_back(instances);
            next.push_back(n);
        }
        swap(curr,next);
    }

    for(int i=0; i<curr.size(); i++){
        cout << curr[i];
        if (i != curr.size()-1) cout << " ";
    }
}
