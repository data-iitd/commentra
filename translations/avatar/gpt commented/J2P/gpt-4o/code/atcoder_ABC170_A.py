import sys

def main():
    # Read a line of input, split it into a list of strings based on spaces
    input_array = sys.stdin.readline().strip().split()
    
    # Initialize a counter to keep track of the number of non-zero inputs
    result = 0
    
    # Iterate through each string in the input array
    for str in input_array:
        # Increment the counter for each input
        result += 1
        
        # If the input is "0", break out of the loop
        if str == "0":
            break
    
    # Print the result, which is the count of non-zero inputs before the first "0"
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
