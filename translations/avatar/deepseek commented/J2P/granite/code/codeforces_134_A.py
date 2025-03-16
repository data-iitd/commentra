
import sys

def main():
    n = int(input()) # Read the size of the array
    arr = list(map(int, input().split())) # Read n integers from the user and store them in the list arr
    sum = sum(arr) # Calculate the sum of the array elements
    c = 0 # Initialize count of valid elements to remove
    indices = [] # Initialize a list to store the indices of valid elements

    # Iterate through the array arr to find elements that can be removed
    for i in range(n):
        # Check if removing the current element keeps the average unchanged
        if (sum - arr[i]) % (n - 1) == 0 and (sum - arr[i]) / (n - 1) == arr[i]:
            c += 1 # Increment the count
            indices.append(i + 1) # Append the index (plus one) to the list indices

    # Print the count of valid elements and the indices of these elements
    print(c)
    print(" ".join(map(str, indices)))

if __name__ == "__main__":
    main()

