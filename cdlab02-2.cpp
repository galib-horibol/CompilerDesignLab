#include<iostream>
using namespace std;
void checkIdentifier(){
    string input; 
    cout<<"enter input: ";
    cin>>input;

    char first = input[0];
    if (!((first >= 'A' && first <= 'Z') || (first >= 'a' && first <= 'z') || first == '_'))
    {
        cout << "Invalid Identifier" << endl;
        return;
    }

    for (int i = 1; input[i] != '\0'; i++)
    {
        char ch = input[i];
        if (!((ch >= 'A' && ch <= 'Z') || 
              (ch >= 'a' && ch <= 'z') || 
              (ch >= '0' && ch <= '9') || 
               ch == '_'))
        {
            cout << "Invalid Identifier" << endl;
            return;
        }
    }

    cout << "Valid Identifier" << endl;
}
int main(){
    checkIdentifier();
    return 0;
}