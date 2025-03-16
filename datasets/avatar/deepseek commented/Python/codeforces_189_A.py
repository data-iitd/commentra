def cutRibbon():
    # Take input from the user, which is expected to be a list of three integers
    arr = [int(i) for i in input().split()]
    
    # Assign the first integer in the input list to the variable 'length'
    length = arr[0]
    
    # Sort the remaining three integers in ascending order and assign to 'arr'
    arr = sorted(arr[1:4], reverse=False)
    
    # Check if 'length' is perfectly divisible by the largest integer in 'arr'
    if length % arr[0] == 0:
        # Print the quotient and return if true
        print(int(length / arr[0]))
        return
    
    # Initialize 'ans' to 0 for storing the maximum number of ribbons
    ans = 0
    
    # If the two smaller integers are equal, proceed with this block
    if arr[0] == arr[1]:
        k = 0
        # Iterate through possible combinations of the two smaller integers
        for i in range(int(length / arr[2]) + 1):
            check = length - i * arr[2]
            if check >= 0 and check % arr[0] == 0:
                k = int(check / arr[0])
                ans = max(ans, k + i)
    else:
        # If the two smaller integers are not equal, iterate through all three integers
        k = 0
        for i in range(int(length / arr[2]) + 1):
            for j in range(int(length / arr[1]) + 1):
                check = length - i * arr[2] - j * arr[1]
                if check >= 0 and check % arr[0] == 0:
                    k = int(check / arr[0])
                    ans = max(ans, k + i + j)
    
    # Print the maximum number of ribbons that can be cut and return
    print(ans)
    return

# Call the function 'cutRibbon' to execute the program
cutRibbon()
