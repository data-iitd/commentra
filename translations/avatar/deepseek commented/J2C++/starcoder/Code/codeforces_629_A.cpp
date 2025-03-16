
#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<string> arr(num);
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    int fine = 0;
    for (int i = 0; i < num; i++) {
        int counter = 0;
        for (int j = 0; j < num; j++) {
            if (arr[j][i] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
    }
    for (int i = 0; i < num; i++) {
        int counter = 0;
        for (int j = 0; j < num; j++) {
            if (arr[i][j] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
    }
    cout << fine << endl;
    return 0;
}

