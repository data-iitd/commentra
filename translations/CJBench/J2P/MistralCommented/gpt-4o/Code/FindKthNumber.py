import random

class Main:
    @staticmethod
    def find_kth_max(array, k):
        if k <= 0 or k > len(array):
            raise ValueError("k must be between 1 and the size of the array")
        return Main.quick_select(array, 0, len(array) - 1, len(array) - k)

    @staticmethod
    def quick_select(array, left, right, k_smallest):
        if left == right:
            return array[left]
        pivot_index = left + random.randint(0, right - left)
        pivot_index = Main.partition(array, left, right, pivot_index)
        if k_smallest == pivot_index:
            return array[k_smallest]
        elif k_smallest < pivot_index:
            return Main.quick_select(array, left, pivot_index - 1, k_smallest)
        else:
            return Main.quick_select(array, pivot_index + 1, right, k_smallest)

    @staticmethod
    def partition(array, left, right, pivot_index):
        pivot_value = array[pivot_index]
        Main.swap(array, pivot_index, right)
        store_index = left
        for i in range(left, right):
            if array[i] < pivot_value:
                Main.swap(array, store_index, i)
                store_index += 1
        Main.swap(array, store_index, right)
        return store_index

    @staticmethod
    def swap(array, i, j):
        array[i], array[j] = array[j], array[i]

if __name__ == "__main__":
    try:
        n = int(input("Enter the size of the array: "))
        if n <= 0:
            print("Array size must be positive.")
            exit()
        array = list(map(int, input("Enter the elements of the array: ").split()))
        k = int(input("Enter the value of k: "))
        if k <= 0 or k > n:
            print("Error: k must be between 1 and the size of the array.")
            exit()
        result = Main.find_kth_max(array, k)
        print(f"The {k}-th largest element is: {result}")
    except Exception as e:
        print(f"An error occurred: {e}")
