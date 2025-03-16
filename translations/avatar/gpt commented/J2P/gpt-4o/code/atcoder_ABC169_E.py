import sys

def main():
    # Define a constant number for modulo operations
    num = 998244353
    
    # Read the number of pairs (n) from input
    n = int(sys.stdin.readline().strip())
    
    # Create two lists to store the two sets of integers
    ai = []
    bi = []
    
    # Read n pairs of integers from input
    for _ in range(n):
        a, b = map(int, sys.stdin.readline().strip().split())
        ai.append(a)
        bi.append(b)
    
    # Sort both lists to prepare for median calculation
    ai.sort()
    bi.sort()
    
    # Check if the number of elements is odd
    if n % 2 == 1:
        # Calculate the result for odd n using the median values
        print(bi[n // 2] - ai[n // 2] + 1)
    else:
        # Calculate the average of the two middle values for even n
        b = (ai[n // 2] + ai[n // 2 - 1]) / 2
        c = (bi[n // 2] + bi[n // 2 - 1]) / 2
        # Calculate the result for even n and print it
        print(int(2 * (c - b) + 1))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
