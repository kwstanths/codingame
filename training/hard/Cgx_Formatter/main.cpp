#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> text;

int identation = 0;
bool inside_string = false;
bool in_new_line = true;

int print(string ch){
    if (in_new_line){
        for(int i=0; i<identation; i++) cout << " ";
        in_new_line = false;
    }
    
    cout << ch;
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string CGXLine;
        getline(cin, CGXLine);
        for(int c=0; c<CGXLine.length(); c++)
            text.push_back(CGXLine.substr(c,1));
    }
    
    for(int ch=0; ch<text.size(); ch++){
        if (inside_string && text[ch] != "'") {
            print(text[ch]);
            continue;
        }
        
        if (text[ch] == " ") continue;
        else if (text[ch] == "\t") continue;
        else if (text[ch] == "(") {
            if (!in_new_line){
                    cout << endl;
                    in_new_line = true;
            }
            print("(");
            cout << endl;
            in_new_line = true;
            identation += 4;
        }else if (text[ch] == ")"){
            if (!in_new_line) {
                cout << endl;
                in_new_line = true;
            }
            identation -=4;
            print(")");
        }else if (text[ch] == "'"){
            print("'");
            inside_string ^= true;
        }else if (text[ch] == ";"){
            print(";");
            cout << endl;
            in_new_line = true;
        }else{
            print(text[ch]);
        }
    }

}
