while True:
    try:
        # Read input values into a list 'c'
        c = list(map(int, input().split()))
        
        # Initialize a list 'card' of size 10 with all elements set to 0
        card = [0] * 10
        count = 0
        sum_c = c[0] + c[1]  # Initialize sum with the sum of the first two input values

        # Loop through the list 'c' to mark the corresponding index in 'card' list
        for i in c:
            card[i - 1] = 1  # Set the index in 'card' list to 1 if the corresponding value in 'c' is read

        # Loop through the list 'card' to check if there are at least 4 distinct numbers in the input
        for i in range(10):
            # If the index in 'card' list is not set to 1 and the sum of input values, index and 1 is less than or equal to 20
            if card[i] == 0 and sum_c + i + 1 <= 20:
                count += 1  # Increment the count if the condition is true

        # Check if the count is greater than or equal to 4 and print "YES" if true, otherwise print "NO"
        if count >= 4:
            print("YES")
        else:
            print("NO")
    except EOFError:
        break

