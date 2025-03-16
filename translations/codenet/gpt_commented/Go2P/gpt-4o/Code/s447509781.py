import sys

class Input:
    def __init__(self):
        self.reader = sys.stdin

    def next_line(self):
        return self.reader.readline().strip()

    def next_int(self):
        return int(self.next_line())

    def next_int_array(self):
        return list(map(int, self.next_line().split()))

def main():
    input = Input()
    
    # Read the number of elements and the array of integers from input
    n = input.next_int()
    s = input.next_int_array()
    
    # Create a boolean list to track used indices
    u = [False] * n
    
    # Initialize variables to store the maximum sum and a temporary sum
    m = 0
    f = 0
    
    # Iterate through possible values of c from 1 to n-2
    for c in range(1, n - 1):
        f = 0  # Reset the temporary sum for each c
        
        # Iterate to find pairs of indices based on the current value of c
        for k in range((n - 1) // c + 1):
            u[k * c] = True  # Mark the current index as used
            
            # Break if the corresponding index is already used
            if u[n - 1 - k * c]:
                break
            
            # Calculate the sum of the elements at the current indices
            f += s[n - 1 - k * c] + s[k * c]
            
            # Update the maximum sum if the current sum is greater
            if m < f:
                m = f
        
        # Reset the used indices for the next iteration of c
        for k in range((n - 1) // c + 1):
            u[k * c] = False
    
    # Print the maximum sum found
    print(m)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
