# Take the number of elements in the list as input
n = int(input())

# Initialize an empty list 'arr' to store the input elements
arr = list(map(int, input().split()))

# Check if the first element of the list is greater than 15
if arr[0] > 15:
    # If it is, print 15
    print(15)
else:
    # Else, iterate through the list starting from the second element
    for i in range(1, len(arr)):
        # Check if the difference between the current and previous elements is greater than 15
        if arr[i] - arr[i-1] > 15:
            # If it is, print the index of the previous element and add 15 to it
            print(arr[i-1] + 15)
            # Break the loop as we have found the answer
            break
    # Else, if we reach here, it means that no difference was greater than 15
    else:
        # Check if the last element of the list is 90 or if adding 15 to it results in 90 or more
        if arr[-1] == 90 or arr[-1] + 15 >= 90:
            # If it is, print 90
            print(90)
        else:
            # Else, print the last element plus 15
            print(arr[-1] + 15)
