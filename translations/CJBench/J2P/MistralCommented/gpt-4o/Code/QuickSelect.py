import random

# This class provides a method to select the n-th smallest element from a list of comparable elements.
class Main:
    @staticmethod
    def select(lst, n):
        if lst is None:
            raise ValueError("The list of elements must not be null.")  # Check if the list is null.
        if len(lst) == 0:
            raise ValueError("The list of elements must not be empty.")  # Check if the list is empty.
        if n < 0 or n >= len(lst):
            raise IndexError("The index must be between 0 and the size of the list - 1.")  # Check index bounds.
        
        # Find the index of the n-th smallest element using the select_index method.
        index = Main.select_index(lst, n)
        # Return the n-th smallest element.
        return lst[index]

    @staticmethod
    def select_index(lst, n):
        return Main.select_index_helper(lst, 0, len(lst) - 1, n)

    @staticmethod
    def select_index_helper(lst, left, right, n):
        while True:
            pivot_index = Main.pivot(lst, left, right)  # Find the pivot index.
            pivot_index_partitioned = Main.partition(lst, left, right, pivot_index, n)  # Partition the list around the pivot.
            if n == pivot_index_partitioned:  # If n is the pivot index, return it.
                return n
            elif n < pivot_index_partitioned:  # If n is to the left of the pivot index, search in the left subarray.
                right = pivot_index_partitioned - 1
            else:  # If n is to the right of the pivot index, search in the right subarray.
                left = pivot_index_partitioned + 1

    @staticmethod
    def partition(lst, left, right, pivot_index, n):
        pivot_value = lst[pivot_index]  # Get the value of the pivot element.
        lst[pivot_index], lst[right] = lst[right], lst[pivot_index]  # Swap the pivot element with the last element.
        store_index = left  # Initialize the index of the first element in the sorted subarray.
        
        for i in range(left, right):  # Iterate through the elements in the subarray.
            if lst[i] < pivot_value:  # If the element is smaller than the pivot, swap it with the first element in the sorted subarray and increment the index.
                lst[store_index], lst[i] = lst[i], lst[store_index]
                store_index += 1
        
        store_index_eq = store_index  # Initialize the index of the first equal element in the sorted subarray.
        for i in range(store_index, right):  # Iterate through the equal elements in the subarray.
            if lst[i] == pivot_value:  # If the element is equal to the pivot, swap it with the last equal element in the sorted subarray and increment the index.
                lst[store_index_eq], lst[i] = lst[i], lst[store_index_eq]
                store_index_eq += 1
        
        lst[right], lst[store_index_eq] = lst[store_index_eq], lst[right]  # Swap the last equal element with the last element in the subarray.
        return store_index if n < store_index else min(n, store_index_eq)  # Return the index of n in the sorted subarray.

    @staticmethod
    def pivot(lst, left, right):
        if right - left < 5:  # If the subarray has fewer than five elements, use the simple partitioning method.
            return Main.partition5(lst, left, right)
        
        for i in range(left, right + 1, 5):  # Iterate through the subarray in steps of five elements.
            sub_right = min(i + 4, right)  # Determine the index of the last element in the current subarray of five elements.
            median5 = Main.partition5(lst, i, sub_right)  # Find the median of the current subarray of five elements.
            lst[median5], lst[left + (i - left) // 5] = lst[left + (i - left) // 5], lst[median5]  # Swap the median with the pivot position.
        
        mid = left + (right - left) // 10 + 1  # Determine the middle index of the subarray.
        right_index = left + (right - left) // 5  # Determine the index of the fifth element from the left in the subarray.
        return Main.select_index_helper(lst, left, right_index, mid)  # Find the index of the pivot using the select_index method.

    @staticmethod
    def partition5(lst, left, right):
        sublist = lst[left:right + 1]  # Create a sublist of the current subarray.
        sublist.sort()  # Sort the sublist.
        return left + (right - left) // 2  # Return the index of the middle element in the sorted sublist.

# Main method to read input and test the select method.
if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))  # Read the number of elements in the list.
    lst = []  # Create an empty list to store the elements.
    for _ in range(n):  # Iterate through the input and add each element to the list.
        lst.append(int(input()))
    index = int(input("Enter the index of the desired element: "))  # Read the index of the desired element.
    
    try:  # Begin a try block to handle exceptions.
        result = Main.select(lst, index)  # Call the select method to find the desired element.
        print(f"The {index}-th smallest element is: {result}")  # Print the result if successful.
    except Exception as e:  # Catch any exceptions thrown by the select method.
        print(e)  # Print the error message if an exception occurs.

# <END-OF-CODE>
