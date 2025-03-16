#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return b < a;
}

int main()
{
    int array[10];

    for(int i = 0; i < 10; i++)
    {
        cin >> array[i];
    }

    sort(array, array + 10, compare);

    for(int i = 0; i < 3; i++)
    {
        cout << array[i] << endl;
    }

    return 0;
}
