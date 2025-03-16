import sys

def main():
    # Step 1: Reading Input
    n = int(input().strip())  # Read the size of the array
    a = list(map(int, input().strip().split()))  # Read the elements of the array
    
    # Step 2: Reading a String
    s = input().strip()  # Read the string
    
    # Step 3: Initial Sum Calculation
    sum_ = 0  # Initialize sum to store the sum of elements in array a where corresponding character in s is 'B'
    
    # Step 4: First Loop
    for i in range(n):
        if s[i] == 'B':
            sum_ += a[i]  # Add the element at position i in array a to sum if the character is 'B'
    
    # Step 5: Main Logic
    ans = sum_  # Initialize ans with the initial sum
    sum1 = sum_  # Initialize sum1 for further calculations
    
    # First nested loop to calculate the maximum possible sum by flipping characters in s
    for i in range(n):
        if s[i] == 'A':
            sum1 += a[i]  # Add the element at position i in array a to sum1 if the character is 'A'
        else:
            sum1 -= a[i]  # Subtract the element at position i in array a from sum1 if the character is 'B'
        ans = max(ans, sum1)  # Update ans with the maximum value between ans and sum1
    
    # Second nested loop to calculate the maximum possible sum by flipping characters in s from right to left
    sum1 = sum_  # Reset sum1 to the initial sum
    for i in range(n - 1, -1, -1):
        if s[i] == 'A':
            sum1 += a[i]  # Add the element at position i in array a to sum1 if the character is 'A'
        else:
            sum1 -= a[i]  # Subtract the element at position i in array a from sum1 if the character is 'B'
        ans = max(ans, sum1)  # Update ans with the maximum value between ans and sum1
    
    # Step 6: Output
    print(ans)  # Print the maximum sum found

if __name__ == "__main__":
    main()
