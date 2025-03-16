class Main:
    @staticmethod
    def count_inversions(arr):
        return Main.merge_sort_and_count(arr, 0, len(arr) - 1)

    @staticmethod
    def merge_sort_and_count(arr, left, right):
        if left >= right:
            return 0  # No inversions

        mid = left + (right - left) // 2
        inversions = 0

        inversions += Main.merge_sort_and_count(arr, left, mid)
        inversions += Main.merge_sort_and_count(arr, mid + 1, right)
        inversions += Main.merge_and_count(arr, left, mid, right)

        return inversions

    @staticmethod
    def merge_and_count(arr, left, mid, right):
        left_arr = arr[left:mid + 1]
        right_arr = arr[mid + 1:right + 1]

        i = 0  # Pointer for left_arr
        j = 0  # Pointer for right_arr
        k = left  # Pointer for the main array
        inversions = 0  # Count of inversions

        while i < len(left_arr) and j < len(right_arr):
            if left_arr[i] <= right_arr[j]:
                arr[k] = left_arr[i]
                i += 1
            else:
                arr[k] = right_arr[j]
                inversions += (mid + 1) - left - i  # Count inversions
                j += 1
            k += 1

        while i < len(left_arr):
            arr[k] = left_arr[i]
            i += 1
            k += 1

        while j < len(right_arr):
            arr[k] = right_arr[j]
            j += 1
            k += 1

        return inversions

if __name__ == "__main__":
    n = int(input("Enter the number of elements in the array: "))
    arr = list(map(int, input("Enter the elements of the array: ").split()))

    result = Main.count_inversions(arr)
    print("Number of inversions:", result)

# <END-OF-CODE>
