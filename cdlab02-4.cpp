#include <iostream>
#include <string>
using namespace std;

void fullName() {
    string firstName, lastName;

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    string fullName = firstName + " " + lastName;

    cout << "Full name: " << fullName << endl;
}

int main() {
    fullName(); 
    return 0;
}
