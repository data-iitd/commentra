#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class InputReader {
public:
    InputReader() {}

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
};

class Task {
public:
    void solve(InputReader& in) {
        int n = in.nextInt();
        vector<int> array(1001, 0);
        
        for (int i = 0; i < n; i++) {
            int index = in.nextInt();
            array[index]++;
        }

        int countMax = -1;
        for (int i = 1; i < array.size(); i++) {
            countMax = max(countMax, array[i]);
        }

        if (n % 2 == 0) {
            if (countMax <= n / 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (countMax <= n / 2 + 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
};

int main() {
    InputReader in;
    Task solver;
    solver.solve(in);
    return 0;
}

// <END-OF-CODE>
