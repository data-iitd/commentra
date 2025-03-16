
import sys

# Create a new Scanner object to read input from the standard input stream
scanner = Scanner(sys.stdin)

# Read four integers as input and store them in an array
input = [0, 0, 0, 0]
for i in range(len(input)):
    input[i] = scanner.nextInt() # Read an integer from the standard input stream and store it in input[i]

# Close the Scanner object to prevent resource leaks
scanner.close()

# Define a 2D array to store the positions of the four integers
position = [[0, 0], [0, 0], [0, 0], [0, 0]]
position[0][0] = input[0] # Store the first integer as the x-coordinate of the first position
position[0][1] = input[1] # Store the second integer as the y-coordinate of the first position
position[1][0] = input[2] # Store the third integer as the x-coordinate of the second position
position[1][1] = input[3] # Store the fourth integer as the y-coordinate of the second position

# Calculate the reversed positions of the first and second positions
reversedPositions = [[0, 0], [0, 0], [0, 0], [0, 0]]
reversedPositions[0] = revpos(position[0], position[1])
reversedPositions[1] = revpos(position[1], position[0])

# Check if the first and second reversed positions are equal
if position[0] == reversedPositions[1]: # Compare the first position with the reversed second position
    print("OK") # Print "OK" if they are equal

# Calculate the output array by taking the reversed positions and swapping their x and y coordinates
output = [0, 0, 0, 0]
output[0] = reversedPositions[2][0] # Store the x-coordinate of the reversed third position in output[0]
output[1] = reversedPositions[2][1] # Store the y-coordinate of the reversed third position in output[1]
output[2] = reversedPositions[3][0] # Store the x-coordinate of the reversed fourth position in output[2]
output[3] = reversedPositions[3][1] # Store the y-coordinate of the reversed fourth position in output[3]

# Print the output array
for i in output:
    print(i)

# 