
import sys

def main():
    n = int(input()) # Read an integer value for n from the standard input
    data = list(map(int, input().split())) # Read n integers from the standard input and store them in a list

    max_value = max(data) # Find the maximum value in the list
    max_index = data.index(max_value) # Find the index of the maximum value in the list

    a = sum(data[:max_index] + data[max_index+1:]) # Calculate the sum of elements excluding the maximum value

    if a > max_value: # Compare the sum of the remaining elements (a) with the maximum value (max)
        print("Yes") # Print "Yes" if the sum of remaining elements is greater than the maximum value
    else:
        print("No") # Print "No" otherwise

if __name__ == "__main__":
    main()

