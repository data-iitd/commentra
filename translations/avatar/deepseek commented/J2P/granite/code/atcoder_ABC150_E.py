
import sys

def main():
    n = int(input()) # Reading the first line and parsing it as integer n
    c = list(map(int, input().split())) # Reading the second line and splitting it by spaces, then converting to list and storing in c
    mod = 1000000007 # Defining the modulo value
    if n == 1:
        print((c[0] * 2) % mod) # If n is 1, print the result directly
        return # Exit the program as no further computation is needed
    c.sort() # Sorting the list c in ascending order

    b = pow(2, n, mod) # Calculating 2^n
    a = pow(2, n - 2, mod) # Calculating 2^(n-2)
    ans = 0 # Initializing the answer variable

    # Calculating the final answer
    for i in range(2, n + 2):
        val = (a * i) % mod # Intermediate calculation
        val = (val * c[n + 1 - i]) % mod # Intermediate calculation
        ans = (ans + val) % mod # Adding to the answer

    ans = (ans * b) % mod # Multiplying the answer by b
    print(ans) # Printing the final result

if __name__ == "__main__":
    main() # Calling the main function

