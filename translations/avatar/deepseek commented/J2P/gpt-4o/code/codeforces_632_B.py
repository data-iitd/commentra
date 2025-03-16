def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    # Step 1: Reading Input
    n = int(data[0])  # Read the size of the array
    a = list(map(int, data[1].split()))  # Initialize the array
    s = data[2]  # Read the string
    
    # Step 3: Initial Sum Calculation
    sum_value = 0  # Initialize sum to store the sum of elements in array a where corresponding character in s is 'B'
    
    # Step 4: First Loop
    for i in range(len(s)):
        if s[i] == 'B':
            sum_value += a[i]  # Add the element at position i in array a to sum if the character is 'B'
    
    # Step 5: Main Logic
    ans = sum_value  # Initialize ans with the initial sum
    sum1 = sum_value  # Initialize sum1 for further calculations
    
    # First nested loop to calculate the maximum possible sum by flipping characters in s
    for i in range(len(s)):
        if s[i] == 'A':
            sum1 += a[i]  # Add the element at position i in array a to sum1 if the character is 'A'
        else:
            sum1 -= a[i]  # Subtract the element at position i in array a from sum1 if the character is 'B'
        ans = max(ans, sum1)  # Update ans with the maximum value between ans and sum1
    
    # Second nested loop to calculate the maximum possible sum by flipping characters in s from right to left
    sum1 = sum_value  # Reset sum1 to the initial sum
    for i in range(len(s) - 1, -1, -1):
        if s[i] == 'A':
            sum1 += a[i]  # Add the element at position i in array a to sum1 if the character is 'A'
        else:
            sum1 -= a[i]  # Subtract the element at position i in array a from sum1 if the character is 'B'
        ans = max(ans, sum1)  # Update ans with the maximum value between ans and sum1
    
    # Step 6: Output
    print(ans)  # Print the maximum sum found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
