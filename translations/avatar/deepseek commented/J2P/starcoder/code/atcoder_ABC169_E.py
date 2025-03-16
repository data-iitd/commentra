
import sys

def main():
    # Declare and initialize a constant integer
    num = 998244353

    # Read the number of elements 'n' from the input
    n = int(input())

    # Create two lists to store the pairs of integers
    ai = []
    bi = []

    # Read the pairs of integers from the input and store them in the lists
    for i in range(n):
        ai.append(int(input().split()[0]))
        bi.append(int(input().split()[1]))

    # Sort both the lists
    ai.sort()
    bi.sort()

    # Check if 'n' is odd or even
    if n % 2 == 1:
        # If 'n' is odd, calculate the range by subtracting the middle element of 'bi' from the middle element of 'ai' and add 1
        print(bi[len(bi) // 2] - ai[len(ai) // 2] + 1)
    else:
        # If 'n' is even, calculate the range by averaging the middle elements of 'ai' and 'bi' and multiply by 2, then add 1
        b = (ai[len(ai) // 2] + ai[len(ai) // 2 - 1] + 0.0) / 2
        c = (bi[len(bi) // 2] + bi[len(bi) // 2 - 1] + 0.0) / 2
        print(int(2 * (c - b) + 1))

if __name__ == "__main__":
    main()

# 