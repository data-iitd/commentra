
# Python code to solve the problem

# Infinite loop to continuously process input until a break condition is met
while True:
    # Read the initial number and the length of digits
    an = list(map(int, input().split()))
    if an[1] == 0: break

    # Initialize aj with the first number and set end flag to 0
    aj = an[0]
    end = 0

    # Loop to process up to 20 iterations
    for k in range(1, 21):
        # Extract digits of aj into a1 and a2 arrays
        a1 = [int(d) for d in str(aj)]
        a2 = [int(d) for d in str(aj)][::-1]

        # Sort a1 in ascending order and a2 in descending order
        a1.sort()
        a2.sort(reverse=True)

        # Construct the max and min numbers from sorted digits
        max_num = int(''.join(map(str, a1)))
        min_num = int(''.join(map(str, a2)))

        # Calculate the difference
        def_num = max_num - min_num

        # Check if the difference is already in the an array
        if def_num in an[:k]:
            # If found, print the index, difference, and the number of iterations
            print(an[:k].index(def_num), def_num, k - an[:k].index(def_num))
            end = 1 # Set end flag to break the loop
            break

        # Store the new difference in the an array and update aj
        an.append(def_num)
        aj = def_num

    if end == 1: break

