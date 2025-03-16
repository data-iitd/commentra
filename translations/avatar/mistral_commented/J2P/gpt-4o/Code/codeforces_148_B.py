def main():
    import sys

    VP = float(sys.stdin.readline().strip())  # Read VP
    VD = float(sys.stdin.readline().strip())  # Read VD
    T = float(sys.stdin.readline().strip())   # Read T
    F = float(sys.stdin.readline().strip())   # Read F
    C = float(sys.stdin.readline().strip())   # Read C

    if VD <= VP:  # Check if VD is less than or equal to VP
        print("0")  # If it is, then the answer is 0
        return

    answer = 0
    start = T

    while True:  # Enter a while loop that runs indefinitely
        x = start * VP / (VD - VP)  # Calculate the time it takes to fill a volume VP

        if (start + x) * VP >= C:  # Check if the total volume filled is greater than or equal to C
            break  # If it is, then we break out of the loop

        start += 2 * x + F  # Update the value of start
        answer += 1  # Increment the value of answer by 1

    print(answer)  # Print the value of answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
