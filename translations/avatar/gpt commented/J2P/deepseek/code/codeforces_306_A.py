def main():
    # Read two integers n and m from user input
    n, m = map(int, input().split())
    
    # Initialize a list of size m to hold the results
    a = [0] * m
    
    # Check if n is divisible by m
    if n % m == 0:
        # If divisible, fill the list with equal parts
        a = [n // m] * m
    else:
        # If not divisible, calculate the base value for each part
        sub = n // m
        for i in range(m):
            a[i] = sub
        
        # Calculate the remainder that needs to be distributed
        test = n - (sub * m)
        count = 0
        
        # Distribute the remainder across the first few elements of the list
        for i in range(test):
            a[count] += 1
            count += 1
            
            # Wrap around if count exceeds the list length
            if count >= m:
                count = 0
    
    # Print the list in reverse order
    for i in range(m - 1, -1, -1):
        print(a[i], end=' ')

if __name__ == "__main__":
    main()
