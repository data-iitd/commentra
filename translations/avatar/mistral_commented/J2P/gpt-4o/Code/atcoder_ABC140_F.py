# Initialize scanner for user input
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the number of slimes N from user input
    N = int(data[0])
    # Calculate the size of the array S based on N
    size = 1 << N
    # Initialize the array S with user input
    S = list(map(int, data[1:size + 1]))
    # Initialize a boolean array spawned to keep track of which slimes have been spawned
    spawned = [False] * size
    # Set the last element of spawned to true, as it represents the position of the last slime
    spawned[size - 1] = True

    # Sort the array S in ascending order
    S.sort()

    # Initialize a list named active to store the indices of the currently active slimes
    active = []
    # Set the last element of spawned to true and add its index to the active list
    active.append(size - 1)

    # Iterate through each generation of slimes
    for i in range(N):
        # Sort the list active in descending order
        active.sort(reverse=True)

        # Initialize a list named activated to store the indices of the slimes that will be activated in the next generation
        activated = []
        # Initialize a variable named next to keep track of the index of the current slime in array S
        next_index = size - 1

        # Iterate through each slime in the current generation
        for slime in active:
            # While the current index next_index is greater than or equal to 0 and the slime size is greater than or equal to the size of the current slime or the current index has already been spawned
            while next_index >= 0 and (S[next_index] >= slime or spawned[next_index]):
                next_index -= 1
            # If the current index next_index is less than 0, it means that there is no empty space for the new slime to spawn, so print "No" and exit the program
            if next_index < 0:
                print("No")
                return
            # Set the current index as spawned and add its index to the activated list
            spawned[next_index] = True
            activated.append(S[next_index])

        # Add all the indices of the activated slimes to the active list
        active.extend(activated)

    # Print "Yes" to indicate that the program has successfully determined the positions of all N slimes
    print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
