#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<int> horses(N);
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        horses.at(i) = Pi;
    }

    std::sort (horses.begin(), horses.end(), [](const int a, const int b){return a < b;}); 

    int max = horses.at(horses.size()-1) - horses.at(0);
    for(int i=0; i<N-1; i++)
        if (horses.at(i+1) - horses.at(i) < max) max = horses.at(i+1) - horses.at(i);

    cout << max << endl;
}
