#include <iostream>
#include <cmath>  # Include the cmath library for the abs function

using namespace std;

int main():
    long long x, y;
    cin >> x >> y;  # Read two integers from standard input
    if abs(x-y) <= 1:
        print("Brown")
    else:
        print("Alice")

