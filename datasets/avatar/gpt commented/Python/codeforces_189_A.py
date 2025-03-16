def cutRibbon():
    # Read input and convert it into a list of integers
    arr = [int(i) for i in input().split()]
    
    # The first element is the total length of the ribbon
    length = arr[0]
    
    # Sort the next three elements (the lengths of the pieces) in ascending order
    arr = sorted(arr[1:4], reverse=False)
    
    # If the total length is divisible by the smallest piece length, print the maximum number of pieces
    if (length % arr[0] == 0):
        print(int(length / arr[0]))
        return
    
    # Initialize the answer variable to keep track of the maximum pieces
    ans = 0
    
    # Case when the two smallest piece lengths are equal
    if (arr[0] == arr[1]):
        k = 0
        # Iterate through the number of the largest pieces that can fit into the ribbon
        for i in range(int(length / arr[2]) + 1):
            # Calculate the remaining length after using i pieces of the largest size
            check = length - i * arr[2]
            # Check if the remaining length can be completely divided by the smallest piece length
            if (check >= 0 and check % arr[0] == 0):
                k = int(check / arr[0])
                # Update the maximum pieces found
                ans = max(ans, k + i)
    else:
        # Case when the two smallest piece lengths are different
        k = 0
        # Iterate through the number of the largest pieces that can fit into the ribbon
        for i in range(int(length / arr[2]) + 1):
            # Iterate through the number of the second largest pieces that can fit into the ribbon
            for j in range(int(length / arr[1]) + 1):
                # Calculate the remaining length after using i pieces of the largest size and j pieces of the second largest size
                check = length - i * arr[2] - j * arr[1]
                # Check if the remaining length can be completely divided by the smallest piece length
                if (check >= 0 and check % arr[0] == 0):
                    k = int(check / arr[0])
                    # Update the maximum pieces found
                    ans = max(ans, k + i + j)
    
    # Print the maximum number of pieces that can be obtained
    print(ans)
    return

# Call the function to execute the ribbon cutting logic
cutRibbon()
