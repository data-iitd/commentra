
import sys

def main():
    # Read the number of elements in the array
    n = int(input())

    # Initialize an array to hold the integers and a variable to store the sum
    arr = []
    sum = 0

    # Read the integers into the array and calculate the sum
    for i in range(n):
        arr.append(int(input()))
        sum += arr[i] # Accumulate the sum of the elements

    # Initialize a counter for valid indices and a StringBuilder for output
    c = 0
    sb = ""

    # Check each element to see if it can be the "removed" element
    for i in range(n):
        # Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
        if (sum - arr[i]) % (n - 1) == 0 and (sum - arr[i]) / (n - 1) == arr[i]:
            c += 1 # Increment the count of valid indices
            sb += str(i + 1) + " " # Append the 1-based index to the StringBuilder

    # Output the count of valid indices
    print(c)

    # Output the indices of valid elements
    print(sb)

if __name__ == "__main__":
    main()

