#include <iostream>
#include <vector>
#define LEN 300
#define TRUE 1
#define FALSE -1

int solve(int, int);
int n;
std::vector<int> A(LEN);
int flag;

int main() {
    int q, M;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::cin >> M;
        flag = FALSE;

        solve(-1, M);
        if (flag == TRUE) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }

    return 0;
}

int solve(int i, int m) {
    if (i >= n) return FALSE;
    else if (m < 0) return FALSE;
    else if (m == 0 || m - A[i + 1] == 0) {
        flag = TRUE;
        return TRUE;
    } else {
        // not use A[i]
        solve(i + 1, m);
        // use A[i]
        solve(i + 1, m - A[i]);
    }
    return FALSE; // Added return statement to avoid undefined behavior
}

// <END-OF-CODE>
