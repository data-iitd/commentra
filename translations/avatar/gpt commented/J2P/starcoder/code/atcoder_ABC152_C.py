
# <START-OF-CODE>

def solve():
    # Create a Scanner object to read input from the user
    sc = Scanner(System.in)

    # Read the number of elements in the array
    N = sc.nextInt()

    # Initialize an array to hold the input values
    arr = [0] * N

    # Populate the array with user input
    for i in range(N):
        arr[i] = sc.nextInt()

    # Initialize a variable to keep track of the count of elements
    sum = 0

    # Create a priority queue to manage the elements
    q = PriorityQueue()

    # Iterate through the array to process each element
    for i in range(arr.length):
        # Add the current element to the priority queue
        q.add(arr[i])

        # Check if the current element is less than or equal to the smallest element in the queue
        if arr[i] <= q.peek():
            # Increment the count if the condition is met
            sum += 1

    # Return the final count of elements that met the condition
    return sum

# 