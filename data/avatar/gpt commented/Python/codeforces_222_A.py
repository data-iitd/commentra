def main():
    # Read two integers n and k from input
    n, k = list(map(int, input().split(' ')))
    
    # Read a list of n integers from input
    elems = list(map(int, input().split(' ')))
    
    # Define a lambda function to check if all elements in an array are the same
    all_same = lambda arr: all([x == arr[0] for x in arr])
    
    # If all elements in elems are the same, print 0 and exit
    if all_same(elems):
        print(0)
        return
    
    # If k is 1, it's impossible to satisfy the conditions, print -1 and exit
    if k == 1:
        print(-1)
        return
    
    # If the last k-1 elements are not the same, print -1 and exit
    if not all_same(elems[k - 1:]):
        print(-1)
        return
    
    # Set the target value to the last element of elems
    target = elems[-1]
    
    # Create a list of elements to delete, which are the first k-1 elements
    to_delete = elems[0:k - 1]
    
    # Remove elements from to_delete that are equal to the target from the end
    while to_delete and to_delete[-1] == target:
        to_delete.pop()
    
    # Print the number of elements that need to be deleted
    print(len(to_delete))

# Entry point of the program
if __name__ == "__main__":
    main()
