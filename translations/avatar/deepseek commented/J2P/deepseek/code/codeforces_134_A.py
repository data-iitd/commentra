import sys

def main():
    # Read the size of the array
    n = int(input().strip())
    # Read n integers from the user and store them in the array arr
    arr = list(map(int, input().strip().split()))
    # Calculate the sum of the array elements
    total_sum = sum(arr)
    # Initialize count of valid elements to remove
    count = 0
    # Create a list to store the indices of valid elements
    indices = []

    # Iterate through the array arr to find elements that can be removed
    for i in range(n):
        # Check if removing the current element keeps the average unchanged
        if (total_sum - arr[i]) % (n - 1) == 0 and (total_sum - arr[i]) // (n - 1) == arr[i]:
            count += 1  # Increment the count
            indices.append(i + 1)  # Append the index (plus one) to the list

    # Print the count of valid elements and the indices of these elements
    print(count)
    print(" ".join(map(str, indices)))

if __name__ == "__main__":
    main()
