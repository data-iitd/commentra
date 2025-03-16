# Import the necessary module for reading input
import sys

# Define a function to reverse the order of elements in an array
def revpos(p, q):
    vec = [0, 0]  # Initialize a temporary vector with zeros

    # Calculate the differences between corresponding elements of p and q
    for i in range(len(vec)):
        vec[i] = p[i] - q[i]  # Subtract corresponding elements of p and q

    # Swap the first and second elements of the vector
    tmp = vec[0]
    vec[0] = vec[1]
    vec[1] = -tmp

    # Calculate the new positions by adding the vector elements to the corresponding elements of q
    newpos = [0, 0]
    for i in range(len(newpos)):
        newpos[i] = q[i] + vec[i]

    # Return the new positions
    return newpos

# Define the main function to read input and perform the required calculations
def main():
    # Read four integers as input and store them in a list
    input_values = list(map(int, sys.stdin.readline().strip().split()))

    # Define a 2D list to store the positions of the four integers
    position = [[0, 0] for _ in range(4)]
    position[0][0] = input_values[0]  # Store the first integer as the x-coordinate of the first position
    position[0][1] = input_values[1]  # Store the second integer as the y-coordinate of the first position
    position[1][0] = input_values[2]  # Store the third integer as the x-coordinate of the second position
    position[1][1] = input_values[3]  # Store the fourth integer as the y-coordinate of the second position

    # Calculate the reversed positions of the first and second positions
    reversed_positions = [revpos(position[0], position[1]), revpos(position[1], position[0])]

    # Check if the first and second reversed positions are equal
    if position[0] == reversed_positions[1]:  # Compare the first position with the reversed second position
        print("OK")  # Print "OK" if they are equal

    # Calculate the output list by taking the reversed positions
    output = [0, 0, 0, 0]
    output[0] = reversed_positions[0][0]  # Store the x-coordinate of the reversed first position in output[0]
    output[1] = reversed_positions[0][1]  # Store the y-coordinate of the reversed first position in output[1]
    output[2] = reversed_positions[1][0]  # Store the x-coordinate of the reversed second position in output[2]
    output[3] = reversed_positions[1][1]  # Store the y-coordinate of the reversed second position in output[3]

    # Print the output list
    for i in output:
        print(i)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
