def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])  # Read the number of elements
    ch = []  # Declare a list to store the result
    s1, s2 = 0, 0  # Initialize sums for two paths
    flag = 0  # Flag for invalid configuration

    # Loop to read inputs and decide paths
    for i in range(1, n + 1):
        x, y = map(int, data[i].split())  # Read the next integers for path 'x' and 'y'
        temp1 = s1 + x  # Calculate temporary sum for path 'x'
        temp2 = s2 + y  # Calculate temporary sum for path 'y'

        # Check if adding to path 'x' or 'y' is valid
        if abs(temp1 - s2) <= 500:
            s1 += x  # Update sum for path 'x'
            ch.append('A')  # Append 'A' to the result list
            continue  # Continue to the next iteration
        if abs(temp2 - s1) <= 500:
            s2 += y  # Update sum for path 'y'
            ch.append('G')  # Append 'G' to the result list
            continue  # Continue to the next iteration
        
        flag = 1  # Set flag to indicate invalid configuration
        break  # Break out of the loop

    # Handle the result based on the flag
    if flag == 1:
        print(-1)  # Print -1 if configuration is invalid
    else:
        ans = ''.join(ch)  # Convert list to string
        print(ans)  # Print the result string

if __name__ == "__main__":
    main()

# <END-OF-CODE>
