#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long int median(vector<long int> scores) {
  long int median;
  size_t size = scores.size();

  sort(scores.begin(), scores.end());

  if (size  % 2 == 0) median = (scores[size / 2 - 1] + scores[size / 2]) / 2;
  else  median = scores[size / 2];

  return median;
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    
    long int x_max = 0;
    long int x_min = pow(2,30) -1;
    vector<long int> h_x;
    vector<long int> h_y;
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        h_x.push_back(X);
        h_y.push_back(Y);
        if (X > x_max) x_max = X;
        if (X < x_min) x_min = X;
    }
    
    int y_height = median(h_y);
    long long int total_sum = x_max-x_min;
    for(int i=0; i<N; i++)
        total_sum += abs(h_y[i]-y_height);
        
    cout << total_sum << endl;
}
