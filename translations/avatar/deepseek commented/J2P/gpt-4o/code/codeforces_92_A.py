def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements in the sequence
    k = int(data[1])  # Read the initial value of k
    
    i = 1
    req = 1  # Initialize req to 1
    
    # Loop continues as long as k - req is non-negative
    while k - req >= 0:
        k -= req  # Subtract req from k
        i += 1  # Increment i
        if i % n != 0:
            req = i % n  # Update req to i % n if i % n is not zero
        else:
            req = n  # Update req to n if i % n is zero
    
    print(k)  # Print the final value of k

if __name__ == "__main__":
    main()

# <END-OF-CODE>
