# Importing the Scanner class for user input (in Python, we use the built-in input function)

def main():
    # Reading two integers from user input
    a = int(input())
    b = int(input())
    
    # Initializing a counter to keep track of the number of pairs processed
    count = 0
    
    # Loop to process pairs of a and b while both are greater than zero
    while True:
        # Check if both a and b are positive
        if a > 0 and b > 0:
            # Increment the count of pairs
            count += 1
            # Decrement both a and b
            a -= 1
            b -= 1
        else:
            # Break the loop if either a or b is not positive
            break
    
    # Calculate the number of pairs that can be formed from the remaining a and b
    ans = a // 2 + b // 2
    
    # Output the count of pairs processed and the calculated answer
    print(count, ans)

# Call the main function
if __name__ == "__main__":
    main()
