#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 100000

int Partition(std::vector<char>&, std::vector<int>&, int, int);
void Quicksort(std::vector<char>&, std::vector<int>&, int, int);
void Merge(std::vector<char>&, std::vector<int>&, int, int, int);
void Merge_Sort(std::vector<char>&, std::vector<int>&, int, int);

int q;

int main() {
    std::vector<int> A(MAX + 1);
    std::vector<char> C(MAX + 1);
    std::vector<char> MC(MAX + 1);
    std::vector<int> MN(MAX + 1);

    int n;
    int count = 0;

    std::cin >> n;

    for (int i = 1; i <= n; i++)
        std::cin >> C[i] >> A[i];

    for (int i = 1; i <= n; i++) {
        MC[i] = C[i];
        MN[i] = A[i];
    }

    Merge_Sort(MC, MN, 1, n);
    int p = 1;
    Quicksort(C, A, p, n);

    for (int i = 1; i <= n; i++) {
        if (MN[i] == A[i] && MC[i] == C[i])
            count++;
    }

    if (count == n)
        std::cout << "Stable\n";
    else
        std::cout << "Not stable\n";

    for (int i = 1; i <= n; i++)
        std::cout << C[i] << " " << A[i] << "\n";

    return 0;
}

int Partition(std::vector<char>& C, std::vector<int>& A, int p, int r) {
    int i, j;
    char tmpC, x;
    int tmpN, y;

    x = C[r];
    y = A[r];
    i = p - 1;

    for (j = p; j < r; j++) {
        if (A[j] <= y) {
            i = i + 1;
            std::swap(A[j], A[i]);
            std::swap(C[j], C[i]);
        }
    }

    std::swap(A[i + 1], A[r]);
    std::swap(C[i + 1], C[r]);

    return i + 1;
}

void Quicksort(std::vector<char>& C, std::vector<int>& A, int p, int r) {
    if (p < r) {
        q = Partition(C, A, p, r);
        Quicksort(C, A, p, q - 1);
        Quicksort(C, A, q + 1, r);
    }
}

void Merge(std::vector<char>& MC, std::vector<int>& MN, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> LN(n1 + 1);
    std::vector<int> RN(n2 + 1);
    std::vector<char> LC(n1 + 1);
    std::vector<char> RC(n2 + 1);

    for (int i = 1; i <= n1; i++) {
        LN[i] = MN[left + i - 1];
        LC[i] = MC[left + i - 1];
    }

    for (int i = 1; i <= n2; i++) {
        RN[i] = MN[mid + i];
        RC[i] = MC[mid + i];
    }

    LN[n1 + 1] = 1000000000;
    RN[n2 + 1] = 1000000000;

    int i = 1, j = 1;

    for (int k = left; k <= right; k++) {
        if (LN[i] <= RN[j]) {
            MN[k] = LN[i];
            MC[k] = LC[i++];
        } else {
            MN[k] = RN[j];
            MC[k] = RC[j++];
        }
    }
}

void Merge_Sort(std::vector<char>& MC, std::vector<int>& MN, int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;
        Merge_Sort(MC, MN, left, mid);
        Merge_Sort(MC, MN, mid + 1, right);
        Merge(MC, MN, left, mid, right);
    }
}

// <END-OF-CODE>
