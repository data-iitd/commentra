import sys

# The Main class contains the main method that initializes the scanner, reads input, and prints output.
class Main:
    @staticmethod
    def main():
        n = int(sys.stdin.readline().strip())  # Read the number of elements in the array from the input.
        arr = list(map(int, sys.stdin.readline().strip().split()))  # Create a list to store the input elements.
        k = int(sys.stdin.readline().strip())  # Read the number of smallest elements to be returned from the array.
        result = Main.get_min_k_nums_by_main(arr, k)  # Get the smallest k elements from the array.
        print(" ".join(map(str, result)))  # Print each element in the result array.

    # The get_min_k_nums_by_main method returns the smallest k elements from the input array.
    @staticmethod
    def get_min_k_nums_by_main(arr, k):
        if k < 1 or k > len(arr):  # Check if the number of elements to be returned is valid.
            return None
        min_kth = Main.get_min_kth_by_main(arr, k)  # Find the kth smallest element in the array.
        res = []  # Create a list to store the smallest k elements.
        for value in arr:  # Iterate through the input array and add the elements smaller than the kth smallest element to the result list.
            if value < min_kth:
                res.append(value)
        res.extend([min_kth] * (k - len(res)))  # Add the kth smallest element to the result list multiple times if needed.
        return res

    # The get_min_kth_by_main method finds the kth smallest element in the input array using the Quickselect algorithm.
    @staticmethod
    def get_min_kth_by_main(arr, k):
        copy_arr = Main.copy_array(arr)  # Create a copy of the input array.
        return Main.bfprt(copy_arr, 0, len(copy_arr) - 1, k - 1)  # Find the kth smallest element in the copy of the array.

    # The copy_array method creates a copy of the input array.
    @staticmethod
    def copy_array(arr):
        return arr[:]  # Return a shallow copy of the array.

    # The bfprt method is a recursive implementation of the Quickselect algorithm to find the kth smallest element in an array.
    @staticmethod
    def bfprt(arr, begin, end, i):
        if begin == end:  # Base case: when the array contains only one element.
            return arr[begin]
        pivot = Main.median_of_medians(arr, begin, end)  # Choose the pivot element as the median of medians.
        pivot_range = Main.partition(arr, begin, end, pivot)  # Partition the array.
        if pivot_range[0] <= i <= pivot_range[1]:  # If the index of the element to be found is within the pivot range.
            return arr[i]
        elif i < pivot_range[0]:  # If the index is before the pivot range.
            return Main.bfprt(arr, begin, pivot_range[0] - 1, i)
        else:  # If the index is after the pivot range.
            return Main.bfprt(arr, pivot_range[1] + 1, end, i)

    # The median_of_medians method finds the median of medians of subarrays of size 5 in the input array.
    @staticmethod
    def median_of_medians(arr, begin, end):
        num = end - begin + 1  # Get the number of elements in the array.
        offset = 1 if num % 5 != 0 else 0  # Determine the number of additional subarrays needed.
        m_arr = [0] * (num // 5 + offset)  # Create an array to store the medians.
        for i in range(len(m_arr)):  # Find the median of each subarray of size 5.
            m_arr[i] = Main.get_median(arr, begin + i * 5, min(end, begin + i * 5 + 4))
        return Main.bfprt(m_arr, 0, len(m_arr) - 1, len(m_arr) // 2)  # Find the median of medians.

    # The partition method partitions the input array into two parts.
    @staticmethod
    def partition(arr, begin, end, num):
        small = begin - 1  # Initialize an index for the beginning of the subarray containing elements smaller than the pivot.
        cur = begin  # Initialize an index for the current position in the array.
        big = end + 1  # Initialize an index for the beginning of the subarray containing elements larger than the pivot.
        while cur != big:  # While there are still elements to be processed.
            if arr[cur] < num:  # If the current element is smaller than the pivot.
                small += 1
                arr[small], arr[cur] = arr[cur], arr[small]  # Swap.
                cur += 1
            elif arr[cur] > num:  # If the current element is larger than the pivot.
                big -= 1
                arr[big], arr[cur] = arr[cur], arr[big]  # Swap.
            else:  # If the current element is equal to the pivot.
                cur += 1
        return [small + 1, big - 1]  # Return the indices of the beginning and end of the subarray.

    # The get_median method finds the median of a subarray of the input array.
    @staticmethod
    def get_median(arr, begin, end):
        Main.insertion_sort(arr, begin, end)  # Sort the subarray to find the median.
        mid = (begin + end) // 2  # Determine the index of the median.
        return arr[mid]  # Return the median.

    # The insertion_sort method sorts a subarray of the input array using the insertion sort algorithm.
    @staticmethod
    def insertion_sort(arr, begin, end):
        if arr is None or len(arr) < 2:  # Base case: when the subarray is empty or contains only one element.
            return
        for i in range(begin + 1, end + 1):  # Iterate through the subarray.
            for j in range(i, begin, -1):
                if arr[j - 1] > arr[j]:  # If the current element is smaller than the previous element, swap them.
                    arr[j - 1], arr[j] = arr[j], arr[j - 1]
                else:
                    break  # Move to the next element.

# Entry point of the application.
if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
