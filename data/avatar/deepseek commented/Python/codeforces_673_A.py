n = int(input())  # Take input for the number of elements in the array
arr = list(map(int, input().split()))  # Take input for the array elements

# Check if the first element of the array is greater than 15
if arr[0] > 15:
    print(15)  # If true, print 15
else:
    # Iterate through the array starting from the second element
    for i in range(1, len(arr)):
        # Check if the difference between the current and previous element is greater than 15
        if arr[i] - arr[i - 1] > 15:
            print(arr[i - 1] + 15)  # If true, print the previous element plus 15 and break the loop
            break
    else:
        # If the loop completes without breaking
        if arr[-1] == 90 or arr[-1] + 15 >= 90:
            print(90)  # If the last element is 90 or adding 15 to the last element is >= 90, print 90
        else:
            print(arr[-1] + 15)  # Otherwise, print the last element plus 15
