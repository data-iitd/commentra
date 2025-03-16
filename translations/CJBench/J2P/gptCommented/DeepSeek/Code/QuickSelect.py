def select(elements, n):
    # Ensure the list is not None
    if elements is None:
        raise ValueError("The list of elements must not be None.")
    
    # Check if the list is empty
    if not elements:
        raise ValueError("The list of elements must not be empty.")
    
    # Validate the index n
    if n < 0 or n >= len(elements):
        raise IndexError("The index must be between 0 and the size of the list - 1.")
    
    # Get the index of the n-th smallest element
    index = select_index(elements, 0, len(elements) - 1, n)
    return elements[index]  # Return the n-th smallest element


def select_index(elements, left, right, n):
    while True:
        # If the left and right pointers converge, return the left index
        if left == right:
            return left
        
        # Choose a pivot index for partitioning
        pivot_index = pivot(elements, left, right)
        # Partition the list around the pivot and get the new pivot index
        pivot_index = partition(elements, left, right, pivot_index, n)
        
        # Check if the pivot index is the desired index
        if n == pivot_index:
            return n  # Found the n-th smallest element
        elif n < pivot_index:
            right = pivot_index - 1  # Search in the left part
        else:
            left = pivot_index + 1  # Search in the right part


def partition(elements, left, right, pivot_index, n):
    pivot_value = elements[pivot_index]  # Get the pivot value
    elements[pivot_index], elements[right] = elements[right], elements[pivot_index]  # Move pivot to the end
    store_index = left  # Pointer for the next position to swap
    
    # Partition the list into elements less than the pivot
    for i in range(left, right):
        if elements[i] < pivot_value:
            elements[store_index], elements[i] = elements[i], elements[store_index]
            store_index += 1
    
    # Handle elements equal to the pivot
    store_index_eq = store_index
    for i in range(store_index, right):
        if elements[i] == pivot_value:
            elements[store_index_eq], elements[i] = elements[i], elements[store_index_eq]
            store_index_eq += 1
    
    # Move the pivot to its final place
    elements[right], elements[store_index_eq] = elements[store_index_eq], elements[right]
    # Return the appropriate index based on the n value
    return store_index if n < store_index else min(n, store_index_eq)


def pivot(elements, left, right):
    # If the range is small, use a simple partitioning method
    if right - left < 5:
        return partition5(elements, left, right)
    
    # Group elements into sublists of 5 and find their medians
    for i in range(left, right, 5):
        sub_right = min(i + 4, right)
        median5 = partition5(elements, i, sub_right)
        elements[median5], elements[left + (i - left) // 5] = elements[left + (i - left) // 5], elements[median5]  # Move median to the front
    
    # Recursively select the median of the medians
    mid = left + (right - left) // 10 + 1
    right_index = left + (right - left) // 5
    return select_index(elements, left, right_index, mid)


def partition5(elements, left, right):
    sublist = elements[left:right + 1]  # Create a sublist
    sublist.sort()  # Sort the sublist
    return left + (right - left) // 2  # Return the median index


# Main function to execute the program
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements
    elements = list(map(int, data[1:n+1]))  # Read the elements into the list
    index = int(data[n+1])  # Read the index of the desired smallest element
    
    try:
        # Attempt to select the n-th smallest element
        result = select(elements, index)
        print(f"The {index}-th smallest element is: {result}")
    except Exception as e:
        # Print any exceptions that occur
        print(e)


if __name__ == "__main__":
    main()
