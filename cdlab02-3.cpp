#include <iostream>
using namespace std;

void analyzeArray() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive." << endl;
        return;
    }

    double arr[n];
    double sum = 0;
    double minVal, maxVal;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];

        if (i == 0) {
            minVal = arr[i];
            maxVal = arr[i];
        } else {
            if (arr[i] < minVal)
                minVal = arr[i];
            if (arr[i] > maxVal)
                maxVal = arr[i];
        }
    }

    double avg = sum / n;
    cout << "Average value: " << avg << endl;
    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
}

int main() {
    analyzeArray(); 
    return 0;
}
