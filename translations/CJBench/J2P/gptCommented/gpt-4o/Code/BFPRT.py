import sys

class Main:
    @staticmethod
    def main():
        # Read the size of the array
        n = int(input())
        arr = list(map(int, input().split()))
        
        # Read the value of k
        k = int(input())
        
        # Get the k smallest numbers from the array
        result = Main.get_min_k_nums(arr, k)
        
        # Print the result
        print(" ".join(map(str, result)))
    
    @staticmethod
    def get_min_k_nums(arr, k):
        # Check if k is within valid range
        if k < 1 or k > len(arr):
            return None  # Return None if k is invalid
        
        # Find the k-th smallest number
        min_kth = Main.get_min_kth(arr, k)
        res = [0] * k  # List to hold the k smallest numbers
        index = 0
        
        # Populate the result list with numbers smaller than the k-th smallest
        for value in arr:
            if value < min_kth:
                res[index] = value
                index += 1
        
        # Fill the remaining slots in the result list with the k-th smallest number
        for _ in range(index, k):
            res[index] = min_kth
            index += 1
        
        return res  # Return the list of k smallest numbers
    
    @staticmethod
    def get_min_kth(arr, k):
        copy_arr = Main.copy_array(arr)  # Create a copy of the original array
        return Main.bfprt(copy_arr, 0, len(copy_arr) - 1, k - 1)  # Use Main algorithm to find the k-th smallest
    
    @staticmethod
    def copy_array(arr):
        return arr[:]  # Return a shallow copy of the array
    
    @staticmethod
    def bfprt(arr, begin, end, i):
        # Base case: if the range has only one element
        if begin == end:
            return arr[begin]  # Return that element
        
        # Find the pivot using the median of medians method
        pivot = Main.median_of_medians(arr, begin, end)
        pivot_range = Main.partition(arr, begin, end, pivot)  # Partition the array around the pivot
        
        # Check if the i-th smallest is in the pivot range
        if pivot_range[0] <= i <= pivot_range[1]:
            return arr[i]  # Return the i-th smallest number
        elif i < pivot_range[0]:
            return Main.bfprt(arr, begin, pivot_range[0] - 1, i)  # Search in the left partition
        else:
            return Main.bfprt(arr, pivot_range[1] + 1, end, i)  # Search in the right partition
    
    @staticmethod
    def median_of_medians(arr, begin, end):
        num = end - begin + 1  # Number of elements in the range
        offset = 1 if num % 5 != 0 else 0  # Determine if there's an extra group
        m_arr = [0] * (num // 5 + offset)  # List to hold medians
        
        # Calculate the median of each group of 5
        for i in range(len(m_arr)):
            m_arr[i] = Main.get_median(arr, begin + i * 5, min(end, begin + i * 5 + 4))
        
        # Recursively find the median of the medians
        return Main.bfprt(m_arr, 0, len(m_arr) - 1, len(m_arr) // 2)
    
    @staticmethod
    def partition(arr, begin, end, num):
        small = begin - 1  # Pointer for smaller elements
        cur = begin  # Current pointer
        big = end + 1  # Pointer for larger elements
        
        # Partitioning logic
        while cur != big:
            if arr[cur] < num:
                small += 1
                arr[small], arr[cur] = arr[cur], arr[small]  # Swap
                cur += 1
            elif arr[cur] > num:
                big -= 1
                arr[cur], arr[big] = arr[big], arr[cur]  # Swap
            else:
                cur += 1  # Move current pointer forward
        
        return [small + 1, big - 1]  # Return the range of the pivot
    
    @staticmethod
    def get_median(arr, begin, end):
        Main.insertion_sort(arr, begin, end)  # Sort the subarray
        mid = (begin + end) // 2  # Find the middle index
        return arr[mid]  # Return the median value
    
    @staticmethod
    def insertion_sort(arr, begin, end):
        if arr is None or len(arr) < 2:
            return  # Return if the array is None or has less than 2 elements
        
        # Insertion sort logic
        for i in range(begin + 1, end + 1):
            for j in range(i, begin, -1):
                if arr[j - 1] > arr[j]:
                    arr[j - 1], arr[j] = arr[j], arr[j - 1]  # Swap
                else:
                    break  # Break if the order is correct
    
if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
