# Function to define the main logic of the program
def main():

    # Read input: number of elements 'n' and the difference 'k'
    n, k = list(map(int, input().split(' ')))

    # Read input: list of elements 'elems'
    elems = list(map(int, input().split(' ')))

    # Helper function to check if all elements in a list are the same
    def all_same(arr):
        # Return True if all elements in the list are the same, else False
        return all([x == arr[0] for x in arr])

    # Check if all elements in the list are the same
    if all_same(elems):
        # If all elements are the same, print 0 and exit
        print(0)
        return

    # Check if difference 'k' is 1
    if k == 1:
        # If difference is 1, print -1 and exit
        print(-1)
        return

    # Check if last 'k' elements in the list are not all the same
    if not all_same(elems[k-1:]):
        # If last 'k' elements are not all the same, print -1 and exit
        print(-1)
        return

    # Initialize target element
    target = elems[-1]

    # Initialize list 'to_delete' to store elements to be deleted
    to_delete = elems[0:k-1]

    # While 'to_delete' is not empty and its last element is 'target'
    while to_delete and to_delete[-1] == target:
        # Pop the last element from 'to_delete'
        to_delete.pop()

    # Print the length of 'to_delete'
    print(len(to_delete))
