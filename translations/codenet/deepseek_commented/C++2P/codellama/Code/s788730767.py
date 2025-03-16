#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

int n, a[50], p, b = 0, c = 0;

# Function to calculate nPr
def nPr(n, r):
    res = 1
    for i in range(r):
        res *= (n - i)
    return res

# Function to calculate nCr
def nCr(n, r):
    res = 1
    for i in range(r):
        res *= (n - i)
        res /= (i+1)
    return res

def main():
    cin >> n >> p
    for i in range(n):
        cin >> a[i]
        if a[i] % 2 == 0:
            b += 1
        else:
            c += 1

    # Calculate the number of subsets with even and odd numbers
    bsum = pow(2, b)
    csum = 0

    if p == 0:
        # Sum combinations where the number of elements is even
        for i in range(c+1):
            if i % 2 == 0:
                csum += nCr(c, i)
    else:
        # Sum combinations where the number of elements is odd
        for i in range(c+1):
            if i % 2 == 1:
                csum += nCr(c, i)

    # Calculate the final answer as the product of bsum and csum
    ans = bsum * csum
    print(ans)


