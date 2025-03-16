# Read an integer input which represents the number of elements in the array
n = int(input())

# Read the next line of input, split it by spaces, convert each element to an integer, and store it in a list
arr = list(map(int, input().split()))

# Check if the first element of the array is greater than 15
if arr[0] > 15:
    # If true, print 15 as the output
    print(15)
else:
    # Iterate through the array starting from the second element
    for i in range(1, len(arr)):
        # Check if the difference between the current and previous element is greater than 15
        if arr[i] - arr[i - 1] > 15:
            # If true, print the previous element plus 15 and exit the loop
            print(arr[i - 1] + 15)
            break
    else:
        # If no break occurred, check the last element of the array
        if arr[-1] == 90 or arr[-1] + 15 >= 90:
            # If the last element is 90 or adding 15 to it results in 90 or more, print 90
            print(90)
        else:
            # Otherwise, print the last element plus 15
            print(arr[-1] + 15)
