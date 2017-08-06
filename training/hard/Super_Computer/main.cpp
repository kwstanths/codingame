#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    
    map<int, int> tasks;
    for (int i = 0; i < N; i++) {
        int J;
        int D;
        cin >> J >> D; cin.ignore();
        
        auto e = tasks.find(J);
        if (e == tasks.end() || tasks[J] > D) tasks[J] = D;
    }

    int number_of_tasks = 0;
    int last_task_end = 0;
    
    for(auto itr = tasks.begin(); itr != tasks.end(); ++itr){
        if (itr->first >= last_task_end){
            last_task_end = itr->first + itr->second;
            number_of_tasks++;
        } else last_task_end = min(last_task_end, itr->first + itr->second);
    }
    
    cout << number_of_tasks << endl;
}
