import random

def select(lst, n):
    if lst is None:
        raise ValueError("The list of elements must not be null.")
    if len(lst) == 0:
        raise ValueError("The list of elements must not be empty.")
    if n < 0 or n >= len(lst):
        raise IndexError("The index must be between 0 and the size of the list - 1.")
    
    index = select_index(lst, n)
    return lst[index]

def select_index(lst, n):
    return select_index_helper(lst, 0, len(lst) - 1, n)

def select_index_helper(lst, left, right, n):
    while True:
        if left == right:
            return left
        pivot_index = pivot(lst, left, right)
        pivot_index = partition(lst, left, right, pivot_index, n)
        if n == pivot_index:
            return n
        elif n < pivot_index:
            right = pivot_index - 1
        else:
            left = pivot_index + 1

def partition(lst, left, right, pivot_index, n):
    pivot_value = lst[pivot_index]
    lst[pivot_index], lst[right] = lst[right], lst[pivot_index]
    store_index = left
    for i in range(left, right):
        if lst[i] < pivot_value:
            lst[store_index], lst[i] = lst[i], lst[store_index]
            store_index += 1
    store_index_eq = store_index
    for i in range(store_index, right):
        if lst[i] == pivot_value:
            lst[store_index_eq], lst[i] = lst[i], lst[store_index_eq]
            store_index_eq += 1
    lst[right], lst[store_index_eq] = lst[store_index_eq], lst[right]
    return store_index if n < store_index else min(n, store_index_eq)

def pivot(lst, left, right):
    if right - left < 5:
        return partition5(lst, left, right)
    for i in range(left, right + 1, 5):
        sub_right = min(i + 4, right)
        median5 = partition5(lst, i, sub_right)
        lst[median5], lst[left + (i - left) // 5] = lst[left + (i - left) // 5], lst[median5]
    mid = left + (right - left) // 10 + 1
    right_index = left + (right - left) // 5
    return select_index_helper(lst, left, right_index, mid)

def partition5(lst, left, right):
    sublist = lst[left:right + 1]
    sublist.sort()
    lst[left:left + len(sublist)] = sublist
    return left + (right - left) // 2

if __name__ == "__main__":
    n = int(input())
    lst = list(map(int, input().split()))
    index = int(input())
    try:
        result = select(lst, index)
        print(f"The {index}-th smallest element is: {result}")
    except Exception as e:
        print(e)

# <END-OF-CODE>
