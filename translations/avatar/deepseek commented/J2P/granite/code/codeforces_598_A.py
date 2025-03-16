
import math

def main():
    q = int(input())  # Read the number of queries
    for _ in range(q):
        n = int(input())  # Read the number n for the current query
        x = math.floor(math.log2(n)) + 1  # Calculate the position of the most significant bit of n
        s = -2**x + 2 + n*(n+1)//2 - 2**x  # Calculate s using arithmetic operations and power functions
        print(s)  # Print the result s for the current query

if __name__ == "__main__":
    main()
