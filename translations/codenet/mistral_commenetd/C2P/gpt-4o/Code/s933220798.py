# Initialize a variable 'ave' with an initial value of 0
ave = 0.0

# Start a for loop that iterates 5 times
for i in range(5):
    a = float(input("Enter a number: "))  # Read a double value from the user

    # Check if the value of 'a' is less than or equal to 40
    if a <= 40:
        ave += 40  # If it is, add 40 to the variable 'ave'
        print(f"Number {i + 1} is less than or equal to 40. Adding 40 to the average.")
    else:
        ave += a  # If greater than 40, add it directly to 'ave'
        print(f"Number {i + 1} is greater than 40. Adding {a} to the average.")

# Calculate the average of the 5 numbers
ave /= 5.0

# Print the average value
print(f"The average of the 5 numbers is: {ave:.0f}")

# End of the code
# <END-OF-CODE>
