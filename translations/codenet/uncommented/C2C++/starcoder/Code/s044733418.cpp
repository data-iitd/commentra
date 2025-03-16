#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
    int array[10], i;
    for(i = 0; i!= 10; i++)
        cin >> array[i];
    sort(array, array+10);
    for(i = 0; i!= 3; i++)
        cout << array[i] << endl;
    return 0;
}
