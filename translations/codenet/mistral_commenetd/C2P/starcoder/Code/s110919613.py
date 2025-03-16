
# <START-OF-CODE>

# Infinite loop to read input
while True:
    an = [0] * 20
    a1 = [0] * 6
    a2 = [0] * 6
    L = 0
    # Read input
    an[0], L = map(int, input().split())
    if L == 0:
        break  # Exit the loop if the input length is zero

    aj = an[0]
    end = 0

    # Iterate through each number in the input array
    for k in range(1, 20):
        # Iterate through each digit in the number from right to left
        for i in range(L-1, -1, -1):
            a1[i] = aj % 10
            a2[i] = aj % 10
            aj = int(aj / 10)
        # Sort the digits in both arrays in ascending order
        for i in range(1, L):
            for j in range(1, L):
                if a1[j-1] < a1[j]:  # Swap adjacent digits if they are in the wrong order
                    a1[j-1], a1[j] = a1[j], a1[j-1]
                if a2[j-1] > a2[j]:  # Swap adjacent digits if they are in the wrong order
                    a2[j-1], a2[j] = a2[j], a2[j-1]
        # Calculate the difference between the two numbers
        d = 1
        max = 0
        min = 0
        for i in range(L-1, -1, -1):
            max += (a1[i] % 10) * d
            min += (a2[i] % 10) * d
            d *= 10
        def = max - min  # Store the difference in a variable

        # Check if the difference has already been encountered in the array 'an'
        for i in range(k):
            if def == an[i]:  # If a match is found, print the result and exit the loop
                print(i, def, k-i)
                end = 1
                break
        if end == 1:
            break  # Exit the loop if a match is found
        an[k] = def
        aj = def  # Update the array and the variable for the next iteration

# 