import sys

# Private constructor to prevent instantiation of the Main class
class Main:
    def __init__(self):
        pass

    def main(self):
        # Create a Scanner object to read input from the console
        scanner = sys.stdin
        
        # Read the number of elements in the array
        n = int(scanner.readline())
        
        # Initialize an array to hold the input values
        arr = []
        
        # Read the values into the array
        for i in range(n):
            arr.append(int(scanner.readline()))
        
        # Call the wpbu method to calculate the maximum profit
        result = wpbu(arr)
        
        # Output the maximum profit
        print("Maximum profit: " + str(result))
        
        # Close the scanner to free up resources
        scanner.close()

    def wpbu(self, arr):
        # Validate the input array to ensure it is not null or empty
        if arr == None or len(arr) == 0:
            raise Exception("Input array cannot be null or empty.")
        
        # Get the length of the array
        n = len(arr)
        
        # Create a 2D array to store the maximum profit values for subproblems
        strg = [[0 for x in range(n)] for x in range(n)]
        
        # Iterate over the possible lengths of the subarrays (slides)
        for slide in range(0, n):
            # Iterate over the starting index of the subarray
            for si in range(0, n - slide):
                # Calculate the ending index of the subarray
                ei = si + slide
                
                # Calculate the current year based on the number of remaining items
                year = (n - (ei - si + 1)) + 1
                
                # If the subarray has only one item, calculate its profit
                if si == ei:
                    strg[si][ei] = arr[si] * year
                else:
                    # Calculate the profit if taking the start or the end item
                    start = strg[si + 1][ei] + arr[si] * year # Profit by taking the start item
                    end = strg[si][ei - 1] + arr[ei] * year   # Profit by taking the end item
                    
                    # Store the maximum profit in the DP table
                    strg[si][ei] = max(start, end)
        
        # Return the maximum profit obtainable from the entire array
        return strg[0][n - 1]

# Main method to execute the program
if __name__ == "__main__":
    Main().main()

# 