# Declare variables to hold marks for midterm, final, and retake
m, f, r = 0, 0, 0

# Continuously read input until the termination condition is met
while True:
    # Read input for midterm, final, and retake
    m, f, r = map(int, input().split())

    # Check if either midterm or final score is -1, indicating failure
    if m == -1 or f == -1:
        print("F") # Output "F" for failure
    # Check if the total score is 80 or more for grade A
    elif m + f >= 80:
        print("A") # Output "A" for excellent performance
    # Check if the total score is between 65 and 79 for grade B
    elif m + f >= 65:
        print("B") # Output "B" for good performance
    # Check if the total score is between 50 and 64 or retake score is 50 or more for grade C
    elif m + f >= 50 or r >= 50:
        print("C") # Output "C" for satisfactory performance
    # Check if the total score is between 30 and 49 for grade D
    elif m + f >= 30:
        print("D") # Output "D" for passing but needs improvement
    # If none of the above conditions are met, output "F"
    else:
        print("F") # Output "F" for failure

    # Print a newline after each grade output
    print()

# End of the program
