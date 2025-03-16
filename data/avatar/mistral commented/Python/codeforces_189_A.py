def cutRibbon():
    # Function to find the maximum number of pieces that can be cut from a ribbon of given length

    # Take input as a list of integers, where the first integer represents the length of the ribbon
    arr = [int(i) for i in input().split()]

    # Assign the length of the ribbon to a variable
    length = arr[0]

    # Sort the next three elements of the list in ascending order
    arr = sorted(arr[1:4], reverse=False)

    # Check if the length of the ribbon is divisible by the first element of the sorted list
    if length % arr[0] == 0:
        # If it is, print the number of pieces required and return
        print(int(length / arr[0]))
        return

    # Initialize an answer variable to keep track of the maximum number of pieces that can be cut
    ans = 0

    # If the first two elements of the sorted list are equal
    if arr[0] == arr[1]:
        # Initialize a variable k to keep track of the number of pieces required
        k = 0

        # Loop to find the maximum number of pieces that can be cut from the ribbon
        for i in range(int(length / arr[2]) + 1):
            # Check if the remaining length after subtracting i * arr[2] is divisible by arr[0]
            check = length - i * arr[2]
            if check >= 0 and check % arr[0] == 0:
                # If it is, update the answer and k
                k = int(check / arr[0])
                ans = max(ans, k + i)

    # If the first two elements of the sorted list are not equal
    else:
        # Initialize a variable k to keep track of the number of pieces required
        k = 0

        # Double loop to find the maximum number of pieces that can be cut from the ribbon
        for i in range(int(length / arr[2]) + 1):
            for j in range(int(length / arr[1]) + 1):
                # Check if the remaining length after subtracting i * arr[2] and j * arr[1] is divisible by arr[0]
                check = length - i * arr[2] - j * arr[1]
                if check >= 0 and check % arr[0] == 0:
                    # If it is, update the answer and k
                    k = int(check / arr[0])
                    ans = max(ans, k + i + j)

    # Print the final answer and return
    print(ans)
    return

cutRibbon()
