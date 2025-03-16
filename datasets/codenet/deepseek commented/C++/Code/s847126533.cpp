#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to check if it's possible to carry all books with n people and a given weight limit
bool check(int n, int wei, vector<int> book) {
    int tmp = wei;
    n--;
    for (int i = 0; i < book.size(); i++) {
        if (tmp < book[i]) {
            if (n > 0) {
                n--;
                tmp = wei;
                if (tmp < book[i])
                    return false;
            } else {
                return false;
            }
        }
        tmp -= book[i];
    }
    return true;
}

int main() {
    int m, n;
    while (cin >> m >> n, m) {
        vector<int> book;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            book.push_back(tmp);
        }

        // Binary search to find the maximum weight a person can carry
        int l = 0;
        int r = 1500000;
        int ans;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(m, mid, book)) {
                ans = mid;
                r = mid; // Adjust the right boundary
            } else {
                l = mid; // Adjust the left boundary
            }
        }
        cout << ans << endl;
    }
}
