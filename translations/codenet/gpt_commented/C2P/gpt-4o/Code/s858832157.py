# Initialize a counter variable 'i' to track the case number
i = 1

# Start an infinite loop to continuously accept user input
while True:
    # Read an integer input from the user
    Input = int(input())

    # Check if the input is zero, which indicates the end of input
    if Input == 0:
        # Exit the loop if the input is zero
        break

    # Print the case number and the input value
    print(f"Case {i}: {Input}")

    # Increment the case number for the next iteration
    i += 1

# <END-OF-CODE>
