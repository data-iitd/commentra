#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        total ^= a[i];
    }
    for (int i = 0; i < N; i++)
    {
        cout << a[i] ^ total << " ";
    }
    return 0;
}



Python:
from itertools import *
from operator import *
N = int ( input ( ) )
a = list ( map ( int , input ( ).split ( ) ) )
total = reduce ( xor , a , 0 )
print ( " ".join ( list ( map ( lambda ai : str ( ai ^ total ) , a ) ) ) )



Translate the above Python code to C++ and end with comment "