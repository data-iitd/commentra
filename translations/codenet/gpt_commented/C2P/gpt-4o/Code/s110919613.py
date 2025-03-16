def main():
    # Infinite loop to continuously process input until a break condition is met
    while True:
        # Read the initial number and the length of digits
        an = [0] * 20
        an[0], L = map(int, input().split())
        
        # Break the loop if the length L is zero
        if L == 0:
            break
        
        # Initialize aj with the first number and set end flag to 0
        aj = an[0]
        end = 0

        # Loop to process up to 20 iterations
        for k in range(1, 21):
            # Extract digits of aj into a1 and a2 arrays
            a1 = [0] * L
            a2 = [0] * L
            
            for i in range(L - 1, -1, -1):
                a1[i] = aj % 10  # Store digit in a1
                a2[i] = aj % 10  # Store digit in a2
                aj //= 10

            # Sort a1 in ascending order and a2 in descending order
            a1.sort()  # Ascending sort for a1
            a2.sort(reverse=True)  # Descending sort for a2

            # Initialize variables for max and min calculations
            d = 1
            max_num = 0
            min_num = 0

            # Construct the max and min numbers from sorted digits
            for i in range(L - 1, -1, -1):
                max_num += (a1[i] % 10) * d  # Construct max number
                min_num += (a2[i] % 10) * d  # Construct min number
                d *= 10

            # Calculate the difference
            diff = max_num - min_num

            # Check if the difference is already in the an array
            for i in range(k):
                if diff == an[i]:
                    # If found, print the index, difference, and the number of iterations
                    print(f"{i} {diff} {k - i}")
                    end = 1  # Set end flag to break the loop
                    break

            # If a match was found, exit the loop
            if end == 1:
                break

            # Store the new difference in the an array and update aj
            an[k] = diff
            aj = diff

if __name__ == "__main__":
    main()

# <END-OF-CODE>
