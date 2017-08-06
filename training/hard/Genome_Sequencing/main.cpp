#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<string> subseqs;

int equal_letters(string a, string b){
    int equal_letters = 0;
    int min_length = min(a.length(), b.length());
    
    for(int i=0; i<min_length; i++){
        if (a.substr(a.length()-min_length+i, min_length-i) == b.substr(0, min_length-i)) equal_letters = max(equal_letters, min_length-i);
    }
        
    return equal_letters;
}

int subseq_size(vector<int>& perms){
    string current_sequence = subseqs[perms[0]];
    for(int i=1; i<perms.size(); i++){
        string subseq = subseqs[perms[i]];
        if (current_sequence.find(subseq) != string::npos) continue;
        else if (subseq.find(current_sequence) != string::npos) current_sequence = subseq;
        else{
            int e1 = equal_letters(current_sequence, subseq);
            int e2 = equal_letters(subseq, current_sequence);
            if (e1 >= e2){
                current_sequence += subseq.substr(e1, subseq.length()-e1);
            }else if (e2 >= e1) {
                current_sequence = subseq.substr(0, subseq.length()-e2) + current_sequence; 
            }else
                current_sequence += subseq;
        }
    }
    
    return current_sequence.length();
}

int main()
{
    vector<int> perms;
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string subseq;
        cin >> subseq; cin.ignore();
        
        subseqs.push_back(subseq);
        perms.push_back(i);
    }
    
    int mmin = INT_MAX;
    do {
        mmin = min(mmin, subseq_size(perms));
    } while ( next_permutation(perms.begin(), perms.end()));
    
    cout << mmin << endl;

}
