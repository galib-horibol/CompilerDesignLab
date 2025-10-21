#include<iostream>
#include<string>
using namespace std;


void isComment(){
    string s;
    cout<<"enter something: ";
    getline(cin, s);
    
    bool hasComment = false;
    
    for(int i = 0; i<s.length()-1; i++){
        if(s[i] == '/' && s[i++] == '/'){
            hasComment = true; 
            cout<<"found comment\n";
            for (int j = i+1; j < s.length(); j++) {
                cout << s[j];
            }
            cout << endl;
            break;
        }
        
    }
    if(hasComment = false){
            cout<<"no comment found"<<endl;
        }
}


int main(){
    isComment();
}