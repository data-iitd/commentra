import sys
import bisect

# Function to read an integer from input
def int_scanner():
    return int(sys.stdin.readline().strip())

def main():
    # Set the modulus value to 1000000007
    mod = 1000000007
    
    # Read the number of elements
    n = int_scanner()
    
    # Initialize a list to hold the integers
    as_list = [int_scanner() for _ in range(n)]
    
    # Initialize a list to hold the unique sorted integers
    xs = []
    
    # Iterate through the input integers
    for number in as_list:
        # Use binary search to find the position to insert the current integer
        idx = bisect.bisect_left(xs, number)
        
        # If the index is equal to the length of xs, append the integer
        if idx == len(xs):
            xs.append(number)
        else:
            # Otherwise, replace the existing integer at the found index
            xs[idx] = number
    
    # Print the number of unique integers found
    print(len(xs))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
