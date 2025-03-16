def select(elements, n):
    # Ensure the list is not None
    if elements is None:
        raise ValueError("The list of elements must not be None.")
    
    # Check if the list is empty
    if not elements:
        raise ValueError("The list of elements must not be empty.")
    
    # Check if the index is within the valid range
    if n < 0 or n >= len(elements):
        raise IndexError("The index must be between 0 and the size of the list - 1.")
    
    # Find the index of the n-th smallest element
    index = select_index(elements, 0, len(elements) - 1, n)
    
    # Return the n-th smallest element
    return elements[index]

def select_index(elements, left, right, n):
    while True:
        if left == right:
            return left
        pivot_index = pivot(elements, left, right)
        pivot_index = partition(elements, left, right, pivot_index, n)
        if n == pivot_index:
            return n
        elif n < pivot_index:
            right = pivot_index - 1
        else:
            left = pivot_index + 1

def partition(elements, left, right, pivot_index, n):
    pivot_value = elements[pivot_index]
    elements[pivot_index], elements[right] = elements[right], elements[pivot_index]
    store_index = left
    for i in range(left, right):
        if elements[i] < pivot_value:
            elements[store_index], elements[i] = elements[i], elements[store_index]
            store_index += 1
    store_index_eq = store_index
    for i in range(store_index, right):
        if elements[i] == pivot_value:
            elements[store_index_eq], elements[i] = elements[i], elements[store_index_eq]
            store_index_eq += 1
    elements[right], elements[store_index_eq] = elements[store_index_eq], elements[right]
    return min(n, store_index_eq) if n < store_index else store_index

def pivot(elements, left, right):
    if right - left < 5:
        return partition5(elements, left, right)
    for i in range(left, right, 5):
        sub_right = min(i + 4, right)
        median5 = partition5(elements, i, sub_right)
        elements[median5], elements[left + (i - left) // 5] = elements[left + (i - left) // 5], elements[median5]
    mid = left + (right - left) // 10 + 1
    right_index = left + (right - left) // 5
    return select_index(elements, left, right_index, mid)

def partition5(elements, left, right):
    sublist = elements[left:right + 1]
    sublist.sort()
    return left + (right - left) // 2

# Main function to read input, call the select method, and print the result
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    elements = [int(data[i]) for i in range(1, n + 1)]
    index = int(data[n + 1])
    try:
        result = select(elements, index)
        print(f"The {index}-th smallest element is: {result}")
    except Exception as e:
        print(str(e))

if __name__ == "__main__":
    main()
