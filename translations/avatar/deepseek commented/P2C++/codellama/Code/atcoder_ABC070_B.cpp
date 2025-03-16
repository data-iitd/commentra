
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> A;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    if (A[1] <= A[2] || A[3] <= A[0])
    {
        cout << 0 << endl;
    }
    else
    {
        sort(A.begin(), A.end());
        cout << A[2] - A[1] << endl;
    }
    return 0;
}

