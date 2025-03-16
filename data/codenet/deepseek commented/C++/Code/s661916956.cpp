#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    // Read three integers from the standard input
    int a, b, c;
    cin >> a >> b >> c;

    // Sort the integers in ascending order
    if (a > b) {
        swap(a, b); // Swap a and b if a is greater than b
    }
    if (b > c) {
        swap(b, c); // Swap b and c if b is greater than c
    }
    if (a > b) {
        swap(a, b); // Swap a and b again to ensure a is not greater than b after the second swap
    }

    // Print the sorted integers
    cout << a << " " << b << " " << c << endl;
}
