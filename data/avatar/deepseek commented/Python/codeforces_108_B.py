
def s():
    # Take input from the user
    input()
    # Read the input, split it into a list of integers, and store it in 'a'
    a = list(map(int, input().split()))
    # Sort the list 'a'
    a.sort()
    # Iterate through the sorted list starting from the second element
    for i in range(1, len(a)):
        # Check if the current element is not equal to the previous element
        # and if the current element is less than twice the previous element
        if a[i] != a[i - 1] and a[i] < a[i - 1] * 2:
            # If the condition is met, return 'YES'
            return 'YES'
    # If the loop completes without finding a match, return 'NO'
    return 'NO'
# Print the result returned by the function 's()'
print(s())

