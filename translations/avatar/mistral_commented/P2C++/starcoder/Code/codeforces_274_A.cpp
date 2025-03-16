#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, k;
    cin >> num >> k;
    vector<int> arr(num);
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    set<int> different;
    for (int x : arr)
    {
        if (x % k!= 0 ||!x / k in different)
            different.insert(x);
        int temp = max(different.size(), temp);
    }
    cout << temp << endl;
    return 0;
}

