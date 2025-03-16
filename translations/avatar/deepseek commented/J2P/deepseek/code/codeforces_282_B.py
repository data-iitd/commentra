import sys

def main():
    n = int(input().strip())  # Read the number of elements
    ch = [None] * n  # Declare a character array to store the result
    s1, s2 = 0, 0  # Initialize sums for two paths
    j = 0  # Index for the result array
    flag = 0  # Flag for invalid configuration

    # Loop to read inputs and decide paths
    for i in range(n):
        x, y = map(int, input().strip().split())  # Read the next integers for path 'x' and 'y'
        temp1 = s1 + x  # Calculate temporary sum for path 'x'
        temp2 = s2 + y  # Calculate temporary sum for path 'y'

        # Check if adding to path 'x' or 'y' is valid
        if abs(temp1 - s2) <= 500:
            s1 += x  # Update sum for path 'x'
            ch[j] = 'A'  # Append 'A' to the result array
            j += 1  # Increment the index
        elif abs(temp2 - s1) <= 500:
            s2 += y  # Update sum for path 'y'
            ch[j] = 'G'  # Append 'G' to the result array
            j += 1  # Increment the index
        else:
            flag = 1  # Set flag to indicate invalid configuration
            break  # Break out of the loop

    # Handle the result based on the flag
    if flag == 1:
        print(-1)  # Print -1 if configuration is invalid
    else:
        ans = ''.join(ch[:j])  # Convert character array to string
        print(ans)  # Print the result string

if __name__ == "__main__":
    main()
