#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int getScore(string word){
    
    int score = 0;
    for(int i=0; i<word.length(); i++){
        string l = word.substr(i,1);
        
        if (l=="d"||l=="g") score +=2;
        else if (l=="b"||l=="c"||l=="m"||l=="p") score +=3;
        else if (l=="f"||l=="h"||l=="v"||l=="w"||l=="y") score +=4;
        else if (l=="k") score +=5;
        else if (l=="j"||l=="x") score +=8;
        else if (l=="q"||l=="z") score +=10;
        else score += 1;
    }
    
    return score;
}

bool isPossible(string word, string letters){
    int letters_found = 0;
    string temp_letters = letters;
    for(int i=0; i<word.length(); i++){
        int position = temp_letters.find(word.substr(i,1));
        if (position != string::npos){
            letters_found++;
            temp_letters.erase(position,1);
        }
    }
    return letters_found == word.length();
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    
    vector<string> dic;
    for (int i = 0; i < N; i++) {
        string W;
        getline(cin, W);
        dic.push_back(W);
    }
    string LETTERS;
    getline(cin, LETTERS);

    string max_word;
    int max_score = 0;
    for(int i=0; i<dic.size(); i++){
        if (isPossible(dic[i], LETTERS)){
            int score = getScore(dic[i]);
            if (score > max_score){
                max_word = dic[i];
                max_score = score;
            }
        }
    }
    
    
    
    cout << max_word << endl;
}
