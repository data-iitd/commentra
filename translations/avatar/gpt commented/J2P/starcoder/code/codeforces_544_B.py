import sys

def printIsland(n, count):
    # Calculate the number of 'L' and 'S' characters that can be placed on the island
    a = (n + 1) / 2 # Number of 'L' characters in the first half
    b = n / 2       # Number of 'L' characters in the second half
    max = a * a + b * b # Maximum number of 'L' characters that can fit in the island
    
    # Check if the provided count exceeds the maximum possible 'L' characters
    if count > max:
        print("NO") # Print "NO" if the count is too high
        return # Exit the method
    
    # If the count is valid, print "YES"
    print("YES")
    
    # Loop through each row of the island
    for i in range(n):
        sb = "" # Create a StringBuilder to construct the row
        
        # Loop through each column of the island
        for j in range(n):
            # Place 'L' if the sum of indices is even and there are still 'L' characters left
            if (i + j) % 2 == 0 and count > 0:
                sb += "L" # Append 'L' to the current row
                count -= 1 # Decrement the count of 'L' characters
            else:
                sb += "S" # Append 'S' to the current row
        print(sb) # Print the constructed row of the island

if __name__ == "__main__":
    # Read the size of the island (n) and the number of 'L' characters (count) from the input
    n = int(input())
    count = int(input())
    
    # Call the method to print the island pattern based on the input values
    printIsland(n, count)

