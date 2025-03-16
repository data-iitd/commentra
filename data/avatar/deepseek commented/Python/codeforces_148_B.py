
princess = int(input())  # Input the number of princess's power
dragon = int(input())    # Input the number of dragon's power
t = int(input())         # Input the initial time
f = int(input())         # Input the time increment
c = int(input())         # Input the target power level

# Check if the dragon's power is less than or equal to the princess's power
if dragon <= princess:
    print(0)             # If dragon is not stronger, no attacks needed
    exit(0)              # Exit the program

result = 0                # Initialize the result counter
position = t * princess   # Calculate the initial position based on time and princess's power
position += princess * position / (dragon - princess)  # Adjust the position based on the given formula

# Enter a while loop that continues until the position is greater than or equal to the target power level
while position < c:
    result += 1         # Increment the result counter
    position += princess * position / dragon  # Update the position based on the dragon's power
    position += princess * f  # Add the time increment to the position
    position += princess * position / (dragon - princess)  # Adjust the position based on the given formula

print(result)            # Print the number of attacks needed