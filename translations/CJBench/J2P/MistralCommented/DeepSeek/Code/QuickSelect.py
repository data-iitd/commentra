import random

def select(nums, n):
    if nums is None or len(nums) == 0:
        raise ValueError("The list of elements must not be null or empty.")
    if n < 0 or n >= len(nums):
        raise IndexError("The index must be between 0 and the size of the list - 1.")
    
    def select_index(nums, left, right, n):
        while True:
            if left == right:
                return left
            pivot_index = random.randint(left, right)
            pivot_index = partition(nums, left, right, pivot_index, n)
            if n == pivot_index:
                return n
            elif n < pivot_index:
                right = pivot_index - 1
            else:
                left = pivot_index + 1
    
    def partition(nums, left, right, pivot_index, n):
        pivot_value = nums[pivot_index]
        nums[pivot_index], nums[right] = nums[right], nums[pivot_index]
        store_index = left
        for i in range(left, right):
            if nums[i] < pivot_value:
                nums[store_index], nums[i] = nums[i], nums[store_index]
                store_index += 1
        store_index_eq = store_index
        for i in range(store_index, right):
            if nums[i] == pivot_value:
                nums[store_index_eq], nums[i] = nums[i], nums[store_index_eq]
                store_index_eq += 1
        nums[right], nums[store_index_eq] = nums[store_index_eq], nums[right]
        return store_index_eq if n < store_index else min(n, store_index_eq)
    
    return nums[select_index(nums, 0, len(nums) - 1, n)]

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    nums = list(map(int, data[1:n+1]))
    index = int(data[n+1])
    try:
        result = select(nums, index)
        print(f"The {index}-th smallest element is: {result}")
    except Exception as e:
        print(str(e))
