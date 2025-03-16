def main():
    # Read the number of elements in the array
    n = int(input())
    
    # Initialize a list to hold the integers and a variable to store the sum
    arr = list(map(int, input().split()))
    total_sum = sum(arr)
    
    # Initialize a counter for valid indices and a list for output
    valid_indices = []
    
    # Check each element to see if it can be the "removed" element
    for i in range(n):
        # Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
        if (total_sum - arr[i]) % (n - 1) == 0 and (total_sum - arr[i]) // (n - 1) == arr[i]:
            valid_indices.append(i + 1)  # Append the 1-based index to the list
    
    # Output the count of valid indices
    print(len(valid_indices))
    
    # Output the indices of valid elements
    print(" ".join(map(str, valid_indices)))

if __name__ == "__main__":
    main()
