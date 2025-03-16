
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int num, k;
    cin >> num >> k;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    set<int> different;
    int temp = 0;
    sort(arr, arr + num);
    for (int i = 0; i < num; i++)
    {
        if (arr[i] % k != 0 || find(different.begin(), different.end(), arr[i] / k) == different.end())
        {
            different.insert(arr[i]);
        }
        temp = max(temp, (int)different.size());
    }
    cout << temp << endl;
    return 0;
}

