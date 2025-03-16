
# Python 3 program to solve the problem

# Function to find the position of the element greater than or equal to max_L
def find_pos(L, max_L):

    # Initialize a variable to store the position of the element greater than or equal to max_L
    pos = -1

    # Traverse the vector
    for i in range(len(L)):

        # If the element is greater than or equal to max_L, update the position
        if L[i] >= max_L:
            pos = i
            break

    # Return the position
    return pos

# Function to perform the required operations for M times
def perform_operations(L, M):

    # Traverse the vector for M times
    for i in range(M):

        # Get the last element of the vector
        max_L = L[-1]

        # If the last element is 0, break the loop
        if max_L == 0:
            break

        # Divide the last element by 2
        max_L = max_L // 2

        # Find the position of the element greater than or equal to max_L
        pos = find_pos(L, max_L)

        # Insert max_L before the found position and remove the last element
        L.insert(pos, max_L)
        L.pop()

# Function to calculate the answer
def calculate_answer(L):

    # Initialize a variable to store the answer
    ans = 0

    # Traverse the vector
    for i in range(len(L)):

        # Add the element to the answer
        ans += L[i]

    # Return the answer
    return ans

# Main function starts here
if __name__ == '__main__':

    # Read input from user
    N, M = map(int, input().split())

    # Initialize a vector of integers with size N
    L = [0] * N

    # Read integers from user and store them in the vector
    for i in range(N):
        L[i] = int(input())

    # Perform the required operations for M times
    perform_operations(L, M)

    # Calculate the answer and print it
    ans = calculate_answer(L)
    print(ans)

