
import sys

# Function to calculate x^y mod mod using efficient exponentiation by squaring
def modPower(x, y, mod):
    res = 1
    x %= mod
    if x == 0:
        return 0
    while y > 0:
        if y % 2 == 1:
            res = (res * x) % mod
        y = y >> 1
        x = (x * x) % mod
    return res

# Main function to read input, calculate the maximum product, and print the result
def main():
    a = list(map(int, input().split()))
    print(max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))))

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "