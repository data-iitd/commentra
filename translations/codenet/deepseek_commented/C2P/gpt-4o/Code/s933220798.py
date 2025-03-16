# Initialize a variable to store the sum of values
ave = 0  

# Loop to read 5 values from the user
for i in range(5):
    a = float(input())  # Read a double value from the user and store it in 'a'
    if a <= 40:  # Check if the value of 'a' is less than or equal to 40
        ave += 40  # Add 40 to 'ave' if the condition is true
    else:
        ave += a  # Add the value of 'a' to 'ave' if the condition is false

ave /= 5.0  # Calculate the average of the values added to 'ave' and divide by 5.0

print(round(ave))  # Print the average value rounded to the nearest integer

# <END-OF-CODE>
