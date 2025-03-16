#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Declare variables
    int n, i = 1, k = 0, p = 1;
    bool flag = true;
    int a[1000]; // Array to keep track of occurrences

    // Read an integer input from the user
    cin >> n;

    // Loop to check if the number is prime
    while(i <= n){
        if(n % i == 0){
            a[k] = i;
            k++;
        }
        i++;
    }

    // Check if the number is prime
    if(k == 2){
        cout << "Prime" << endl;
    }
    else{
        cout << "Not prime" << endl;
    }

    return 0;
}

