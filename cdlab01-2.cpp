#include<iostream>
#include<string>
using namespace std;

void isOperator(){
    string expr;
    cout<<"enter expression: ";
    cin>>expr;
    
    int count = 0;
    
    char operators[] = {'+','-','*','/','%','='};
    
    for(int i = 0; i<expr.length(); i++){
        for(int j = 0; j < sizeof(operators)/sizeof(operators[0]); j++){
            if(expr[i] == operators[j]){
                count++;
                cout << "operator" << count << ": " << expr[i] << endl;
            }
        }
    }
    if (count == 0) {
        cout << "No operators found." << endl;
    }
}  



int main(){
    isOperator();
}