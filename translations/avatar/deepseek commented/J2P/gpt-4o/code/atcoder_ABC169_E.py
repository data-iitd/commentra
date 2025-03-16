import sys

def main():
    # Declare and initialize a constant integer
    num = 998244353
    
    # Read the number of elements 'n' from the input
    n = int(sys.stdin.readline().strip())
    
    # Create two lists to store the pairs of integers
    ai = []
    bi = []
    
    # Read the pairs of integers from the input and store them in the lists
    for _ in range(n):
        a, b = map(int, sys.stdin.readline().strip().split())
        ai.append(a)
        bi.append(b)
    
    # Sort both lists
    ai.sort()
    bi.sort()
    
    # Check if 'n' is odd or even
    if n % 2 == 1:
        # If 'n' is odd, calculate the range
        print(bi[n // 2] - ai[n // 2] + 1)
    else:
        # If 'n' is even, calculate the range
        b = (ai[n // 2] + ai[n // 2 - 1]) / 2
        c = (bi[n // 2] + bi[n // 2 - 1]) / 2
        print(int(2 * (c - b) + 1))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
