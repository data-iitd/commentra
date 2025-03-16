import sys

def main():
    # Reading the number of elements in the array from the standard input
    n = int(input().strip())
    # Reading the array elements from the standard input
    a = list(map(int, input().strip().split()))
    # Reading the string from the standard input
    s = input().strip()
    
    # Initializing the sum variable to zero
    sum_b = 0
    # Calculating the sum of the array elements corresponding to the 'B' characters
    for i in range(n):
        if s[i] == 'B':
            sum_b += a[i]
    
    # Initializing the answer variable with the sum calculated above
    ans = sum_b
    sum1 = sum_b
    
    # Iterating through the string to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
    for i in range(n):
        if s[i] == 'A':
            sum1 += a[i]
        else:
            sum1 -= a[i]
        ans = max(ans, sum1)
    
    # Resetting the temporary sum variable with the sum calculated at the beginning
    sum1 = sum_b
    
    # Iterating through the string in reverse order to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
    for i in range(n-1, -1, -1):
        if s[i] == 'A':
            sum1 += a[i]
        else:
            sum1 -= a[i]
        ans = max(ans, sum1)
    
    # Printing the maximum sum found
    print(ans)

if __name__ == "__main__":
    main()
