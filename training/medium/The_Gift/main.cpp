#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

template<typename T> T get_front(deque<T>& container){
    T temp = container.front();
    container.pop_front();
    return temp;
}

bool isPossible(deque<int>& budgets, int gift_price){
    int sum = 0;
    for(int i=0; i < budgets.size(); i++) sum += budgets.at(i);
    return sum >= gift_price;
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    int C;
    cin >> C; cin.ignore();
    deque<int> budgets;
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B; cin.ignore();
        budgets.push_back(B);
    }

    std::sort(budgets.begin(), budgets.end(), [](int a, int b){return a<b;});

    if (!isPossible(budgets, C))  {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    deque<int> shares;
    int money_to_fill = C;
    while (!budgets.empty()){
        int fair_share = money_to_fill / budgets.size();
        int odd_budget = get_front(budgets);
        if (odd_budget < fair_share){
            shares.push_back(odd_budget);
            money_to_fill -= odd_budget;
        }else{
            shares.push_back(fair_share);
            money_to_fill -= fair_share;
        }
    }
    
    for(int i=0; i<shares.size(); i++) cout << shares.at(i) << endl;
    
}
