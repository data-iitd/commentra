
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> n(N);
    cout << "Enter the elements separated by spaces: ";
    for (int i = 0; i < N; i++)
        cin >> n[i];

    int a = 1;
    int pos = 0;
    for (int i = 1; i < N; i++)
    {
        if (n[pos] > n[i])
        {
            a++;
            pos = i;
        }
    }

    cout << a << endl;

    return 0;
}

