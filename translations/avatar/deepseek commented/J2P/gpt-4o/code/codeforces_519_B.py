import sys

def main():
    # Read the number of elements
    n = int(input())
    
    # Initialize sums of subsets
    a = 0
    b = 0
    c = 0
    
    # Sum all n elements
    for _ in range(n):
        a += int(input())
    
    # Sum n-1 elements
    for _ in range(n - 1):
        b += int(input())
    
    # Sum n-2 elements
    for _ in range(n - 2):
        c += int(input())
    
    # Calculate the differences
    x = a - b
    y = b - c
    
    # Output the results
    print(x)
    print(y)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
