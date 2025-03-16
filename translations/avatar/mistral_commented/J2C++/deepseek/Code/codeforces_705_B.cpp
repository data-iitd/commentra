#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> arr(t);

    for (int i = 0; i < t; i++) {
        cin >> arr[i];
        if (arr[i] == 1) {
            static int prevWinner = 0;
            if (prevWinner == 0) {
                prevWinner = 2;
            }

            if ((arr[i] - 1) % 2 == 0) {
                cout << (prevWinner == 0 ? 2 : 1) << endl;
                prevWinner = (prevWinner == 0 ? 2 : 1);
            }
        }
    }

    return 0;
}
