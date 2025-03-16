# Import necessary libraries
import sys

def main():
    # Declare variables
    n = 0  # Number of elements in the array
    sq = [0] * 10000  # Square array to store squares of numbers from 1 to n-1
    fr = [0] * 5000  # Frequency array to store the frequency of each difference between squares
    com = []  # List to store unique squares

    # Start of the infinite loop
    while True:
        n = int(input())  # Read the number of elements in the array from the user
        if n == 0:
            break  # If the number is zero, break the loop

        # Initialize square array
        for i in range(1, n):
            sq[i] = (i * i) % n
        com.clear()  # Clear the list before filling it with new unique squares

        # Find unique squares and store them in the list
        for i in range(1, n):
            if sq[i] not in com:  # If the square is not present, add it to the list
                com.append(sq[i])

        # Initialize frequency array
        for i in range((n - 1) // 2 + 1):
            fr[i] = 0

        # Find the frequency of each difference between unique squares
        for i in range(len(com)):
            for j in range(len(com)):
                if i != j:  # If the indices are not the same
                    tmp = com[i] - com[j]  # Calculate the difference between two squares
                    if tmp < 0:
                        tmp += n  # If the difference is negative, make it positive by adding n
                    if tmp > (n - 1) // 2:
                        tmp = n - tmp  # If the difference is greater than half the size of the array, make it smaller
                    fr[tmp] += 1  # Increment the frequency of the difference

        # Print the frequency of each difference
        for i in range(1, (n - 1) // 2 + 1):
            print(fr[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
