#include<iostream>
#include<string>
using namespace std;


void isNumericConstant(){
    string x;
    cout<<"enter something: ";
    cin>>x;
    bool isNumeric = true;

    for(int i = 0; i<x.length(); i++){
        if((x[i]>='0' && x[i]<='9')==false){
            isNumeric = false;
            break;
        }
    }

    if(isNumeric == true){
        cout<<x<<" is a numeric constant."<<endl;
    }
    else{
        cout<<x<<" is not a numeric constant."<<endl;
    }
}



int main(){
    isNumericConstant();
}