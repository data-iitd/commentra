# <START-OF-CODE>

# Function to read the input
def read_input():
    # Read the initial number and the length of digits
    an = int(input())
    L = int(input())
    return an, L

# Function to sort the digits in ascending and descending order
def sort_digits(an, L):
    # Arrays to hold digits and intermediate values
    a1 = [0] * L
    a2 = [0] * L

    # Extract digits of aj into a1 and a2 arrays
    for i in range(L - 1, -1, -1):
        a1[i] = an % 10
        a2[i] = an % 10
        an = an // 10

    # Sort a1 in ascending order and a2 in descending order
    for i in range(1, L):
        for j in range(1, L):
            # Ascending sort for a1
            if a1[j - 1] < a1[j]:
                a1[j - 1], a1[j] = a1[j], a1[j - 1]
            # Descending sort for a2
            if a2[j - 1] > a2[j]:
                a2[j - 1], a2[j] = a2[j], a2[j - 1]

    # Construct the max and min numbers from sorted digits
    max = 0
    min = 0
    d = 1
    for i in range(L - 1, -1, -1):
        max += (a1[i] % 10) * d
        min += (a2[i] % 10) * d
        d *= 10

    # Calculate the difference
    def = max - min

    return def

# Function to check if the difference is already in the an array
def check_diff(an, def, k):
    for i in range(k):
        if def == an[i]:
            return True
    return False

# Function to print the output
def print_output(an, def, k):
    print(an.index(def), def, k - an.index(def))

# Main function
def main():
    # Infinite loop to continuously process input until a break condition is met
    while True:
        # Read the initial number and the length of digits
        an, L = read_input()

        # Break the loop if the length L is zero
        if not L:
            break

        # Arrays to hold digits and intermediate values
        an = [0] * 20
        a1 = [0] * 6
        a2 = [0] * 6

        # Initialize aj with the first number and set end flag to 0
        aj = an[0]
        end = 0

        # Loop to process up to 20 iterations
        for k in range(1, 21):
            # Extract digits of aj into a1 and a2 arrays
            for i in range(L - 1, -1, -1):
                a1[i] = aj % 10
                a2[i] = aj % 10
                aj = aj // 10

            # Sort a1 in ascending order and a2 in descending order
            for i in range(1, L):
                for j in range(1, L):
                    # Ascending sort for a1
                    if a1[j - 1] < a1[j]:
                        a1[j - 1], a1[j] = a1[j], a1[j - 1]
                    # Descending sort for a2
                    if a2[j - 1] > a2[j]:
                        a2[j - 1], a2[j] = a2[j], a2[j - 1]

            # Construct the max and min numbers from sorted digits
            max = 0
            min = 0
            d = 1
            for i in range(L - 1, -1, -1):
                max += (a1[i] % 10) * d
                min += (a2[i] % 10) * d
                d *= 10

            # Calculate the difference
            def = max - min

            # Check if the difference is already in the an array
            if check_diff(an, def, k):
                # If found, print the index, difference, and the number of iterations
                print_output(an, def, k)
                end = 1
                break

            # Store the new difference in the an array and update aj
            an[k] = def
            aj = def

        # If a match was found, exit the loop
        if end == 1:
            break

# Call the main function
if __name__ == '__main__':
    main()

# 