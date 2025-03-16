#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000

using namespace std;

int Partition(vector<char>&, vector<int>&, int, int);
void Quicksort(vector<char>&, vector<int>&, int, int);

void Merge(vector<char>&, vector<int>&, int, int, int);
void Merge_Sort(vector<char>&, vector<int>&, int, int);

int q;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<char> C(MAX + 1);
    vector<int> A(MAX + 1);
    vector<char> MC(MAX + 1);
    vector<int> MN(MAX + 1);

    int i, p, n;
    int count = 0;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> C[i] >> A[i];

    for(i = 1; i <= n; i++){
        MC[i] = C[i];
        MN[i] = A[i];
    }

    Merge_Sort(MC, MN, 1, n);

    p = 1;
    Quicksort(C, A, p, n);

    for(i = 1; i <= n; i++){
        if(MN[i] == A[i] && MC[i] == C[i])
            count++;
    }

    if(count == n)
        cout << "Stable" << "\n";
    else
        cout << "Not stable" << "\n";

    for(i = 1; i <= n; i++)
        cout << C[i] << " " << A[i] << "\n";

    return 0;
}

int Partition(vector<char>& C, vector<int>& A, int p, int r){
    int i, j;
    char tmpC;
    int tmpN;
    char x;
    int y;

    x = C[r];
    y = A[r];
    i = p - 1;

    for(j = p; j < r; j++){
        if(A[j] <= y){
            i = i + 1;
            tmpN = A[j];
            tmpC = C[j];
            A[j] = A[i];
            C[j] = C[i];
            A[i] = tmpN;
            C[i] = tmpC;
        }
    }

    tmpN = A[i + 1];
    tmpC = C[i + 1];
    A[i + 1] = A[r];
    C[i + 1] = C[r];
    A[r] = tmpN;
    C[r] = tmpC;

    return i + 1;
}

void Quicksort(vector<char>& C, vector<int>& A, int p, int r){
    if(p < r){
        q = Partition(C, A, p, r);
        Quicksort(C, A, p, q - 1);
        Quicksort(C, A, q + 1, r);
    }
}

void Merge(vector<char>& MC, vector<int>& MN, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> LN(n1 + 1);
    vector<int> RN(n2 + 1);
    vector<char> LC(n1 + 1);
    vector<char> RC(n2 + 1);

    int i, j, k;

    for(i = 1; i <= n1; i++){
        LN[i] = MN[left + i - 1];
        LC[i] = MC[left + i - 1];
    }

    for(i = 1; i <= n2; i++){
        RN[i] = MN[mid + i];
        RC[i] = MC[mid + i];
    }

    LN[n1 + 1] = 1000000000;
    RN[n2 + 1] = 1000000000;

    i = 1;
    j = 1;

    for(k = left; k <= right; k++){
        if(LN[i] <= RN[j]){
            MN[k] = LN[i];
            MC[k] = LC[i++];
        }
        else{
            MN[k] = RN[j];
            MC[k] = RC[j++];
        }
    }
}

void Merge_Sort(vector<char>& MC, vector<int>& MN, int left, int right){
    int mid;

    if(left < right){
        mid = (left + right) / 2;
        Merge_Sort(MC, MN, left, mid);
        Merge_Sort(MC, MN, mid + 1, right);
        Merge(MC, MN, left, mid, right);
    }
}

