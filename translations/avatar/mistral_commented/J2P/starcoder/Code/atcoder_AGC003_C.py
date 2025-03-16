
# Importing the required utility classes
import sys
import queue

# Final static constant for the maximum size of the array
NUM = ( int ) ( 1e5 + 2 )

# Function to read input from stdin
def read_input():
    # Reading the number of elements in the array
    N = int(input())

    # Creating an empty HashMap to store the index of each unique element
    map = dict()

    # Creating an empty PriorityQueue to store the elements in ascending order
    nums = queue.PriorityQueue()

    # Reading the elements one by one and adding them to the PriorityQueue and HashMap
    for i in range(N):
        tmp = int(input()) # Reading an element
        nums.put(tmp) # Adding the element to the PriorityQueue
        map[tmp] = i # Adding the index of the element to the HashMap

    bin = 0 # Initializing a binary index variable
    diff = 0 # Initializing a variable to store the difference in parity between elements

    # Processing the elements in the PriorityQueue
    while not nums.empty():
        num = nums.get() # Polling an element from the PriorityQueue
        idx = map[num] # Getting the index of the element from the HashMap

        # Checking if the binary index and the index of the current element have opposite parity
        if ( ( bin % 2 )!= ( idx % 2 ) ):
            diff += 1 # Incrementing the difference if the condition is true

        bin += 1 # Incrementing the binary index
        bin %= 2 # Setting the binary index to 0 or 1 based on the current parity

    # Calculating and printing the answer
    ans = ( diff // 2 )
    print(ans)

# Main function
if __name__ == '__main__':
    read_input()

