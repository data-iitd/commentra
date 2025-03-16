# Importing the necessary module
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Reading the number of elements in the array
    a = list(map(int, sys.stdin.readline().strip().split()))  # Reading the array elements

    s = sys.stdin.readline().strip()  # Reading the string
    sum_value = 0  # Initializing the sum variable to zero

    for i in range(len(s)):  # Iterating through the string to calculate the sum of the array elements corresponding to the 'B' characters
        if s[i] == 'B':
            sum_value += a[i]

    ans = sum_value  # Initializing the answer variable with the sum calculated above
    sum1 = sum_value  # Initializing a temporary sum variable with the sum calculated above

    for i in range(len(s)):  # Iterating through the string to calculate the sum of the array elements corresponding to the 'A' characters
        if s[i] == 'A':
            sum1 += a[i]
        else:
            sum1 -= a[i]
        ans = max(ans, sum1)  # Updating the maximum sum found

    sum1 = sum_value  # Resetting the temporary sum variable with the sum calculated at the beginning

    for i in range(len(s) - 1, -1, -1):  # Iterating through the string in reverse order
        if s[i] == 'A':
            sum1 += a[i]
        else:
            sum1 -= a[i]
        ans = max(ans, sum1)  # Updating the maximum sum found

    print(ans)  # Printing the maximum sum found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
