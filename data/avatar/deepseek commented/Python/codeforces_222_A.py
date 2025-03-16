
def main():
    # Read the number of elements (n) and the parameter (k)
    n, k = list(map(int, input().split(' ')))
    
    # Read the list of elements
    elems = list(map(int, input().split(' ')))
    
    # Define a lambda function to check if all elements in a list are the same
    all_same = lambda arr: all([x == arr[0] for x in arr])
    
    # Check if all elements in the list are the same
    if all_same(elems):
        # If all elements are the same, print 0 and return
        print(0)
        return
    
    # If k is 1, print -1 and return
    if k == 1:
        print(-1)
        return
    
    # Check if elements from index k-1 to the end are all the same
    if not all_same(elems[k-1:]):
        # If not, print -1 and return
        print(-1)
        return
    
    # Set the target to the last element of the list
    target = elems[-1]
    
    # Initialize to_delete as elements from the start to k-1
    to_delete = elems[:k-1]
    
    # Remove elements from to_delete that are equal to target until a different element is found
    while to_delete and to_delete[-1] == target:
        to_delete.pop()
    
    # Print the length of to_delete
    print(len(to_delete))

if __name__ == "__main__":
    main()

