def main():
    # Read the number of elements (n) from standard input
    n = int(input())
    # Read the threshold value (x) from standard input
    x = int(input())
    
    # Initialize a list to hold the integers (l)
    l = []
    
    # Loop to read n integers from standard input and append them to the list l
    for _ in range(n):
        tmpL = int(input())
        l.append(tmpL)
    
    # Initialize variables to keep track of the cumulative sum (tmpSum) and the result (rs)
    tmpSum = 0
    rs = 0
    
    # Loop through the list l to calculate the cumulative sum and determine the result
    for i, v in enumerate(l):
        # Add the current value to the cumulative sum
        tmpSum += v
        
        # Check if the index exceeds the number of elements
        if i >= n:
            rs = n  # Set result to n if index exceeds n
            break
        
        # If the cumulative sum is less than or equal to x, update the result
        if tmpSum <= x:
            rs = i + 2  # Update result to the current index + 2
        elif tmpSum > x:
            break  # Exit the loop if the cumulative sum exceeds x
    
    # Print the final result
    print(rs)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
