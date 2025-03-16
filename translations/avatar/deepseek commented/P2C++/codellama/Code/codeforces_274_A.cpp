
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

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
    int temp = 0;
    for (int x : arr)
    {
        if (x % k != 0 || !different.count(x / k))
            different.insert(x);
        temp = max(temp, (int)different.size());
    }
    cout << temp << endl;
    return 0;
}

