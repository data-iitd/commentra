import sys

def main():
    # Read the first line of input and convert it to a character array
    arr = list(sys.stdin.readline().strip())
    
    # Get the length of the character array
    N = len(arr)
    
    # Read the number of queries K
    K = int(sys.stdin.readline().strip())
    
    # Initialize the result counter
    res = 0
    
    # Loop through each query
    for _ in range(K):
        # Read the input string for the current query
        input_str = sys.stdin.readline().strip()
        
        # Initialize counters for characters in the input string
        a = 0
        b = 0
        
        # Iterate through the character array
        for char in arr:
            # Count occurrences of the first character of the input string
            if char == input_str[0]:
                a += 1
            # Count occurrences of the second character of the input string
            elif char == input_str[1]:
                b += 1
            # If neither character is found, update the result and reset counters
            else:
                res += min(a, b)
                a = b = 0
        
        # Add the minimum count of the two characters to the result
        res += min(a, b)
    
    # Output the final result
    print(res)

if __name__ == "__main__":
    main()
