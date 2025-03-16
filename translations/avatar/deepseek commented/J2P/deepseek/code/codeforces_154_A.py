import sys

def main():
    # Reading input from standard input
    arr = list(sys.stdin.readline().strip())  # Read a line and convert it to a list of characters
    N = len(arr)  # Store the length of the character array
    
    # Initialize a set to store unique strings and read the number of test cases
    set_ = set()
    K = int(sys.stdin.readline().strip())
    
    # Initialize the result variable to store the final count
    res = 0
    
    # Loop to process each test case
    for _ in range(K):
        input_ = sys.stdin.readline().strip()  # Read the input string for the current test case
        a = 0  # Counter for the first character of the input
        b = 0  # Counter for the second character of the input
        
        # Iterate over the characters of the input array
        for char in arr:
            if char == input_[0]:  # If the character matches the first character of the input
                a += 1
            elif char == input_[1]:  # If the character matches the second character of the input
                b += 1
            else:  # If the character does not match either of the input characters
                res += min(a, b)  # Add the minimum of a and b to the result
                a = b = 0  # Reset the counters
        
        res += min(a, b)  # Add the minimum of a and b to the result after the loop
    
    # Print the final result
    print(res)

if __name__ == "__main__":
    main()
