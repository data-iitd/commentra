#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int num;
    cin >> num;
    int counter = 0;
    int fine = 0;
    vector<string> arr(num);

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[k][i] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
        counter = 0;
    }

    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[i][k] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
        counter = 0;
    }

    cout << fine << endl;

    return 0;
}

// <END-OF-CODE>
