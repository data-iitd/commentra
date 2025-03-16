class Main:
    def __init__(self, classification_ratio=0.45):
        # Initialize the classification ratio with the given value
        if classification_ratio <= 0 or classification_ratio >= 1:
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classification_ratio = classification_ratio

    def set_classification_ratio(self, classification_ratio):
        if classification_ratio <= 0 or classification_ratio >= 1:
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classification_ratio = classification_ratio

    def sort(self, array):
        self.flash_sort(array)
        return array

    def flash_sort(self, arr):
        if len(arr) == 0:
            return

        min_elem = self.find_min(arr)
        max_index = self.find_max_index(arr)

        if arr[max_index] == min_elem:
            return

        m = int(self.classification_ratio * len(arr))
        classification_array = [0] * m
        c1 = (m - 1) / (arr[max_index] - min_elem)

        self.classify(arr, classification_array, c1, min_elem)
        self.transform(classification_array)
        self.permute(arr, classification_array, c1, min_elem, len(arr), m)
        self.insertion_sort(arr)

    def find_min(self, arr):
        return min(arr)

    def find_max_index(self, arr):
        return arr.index(max(arr))

    def classify(self, arr, classification_array, c1, min_elem):
        for t in arr:
            k = int(c1 * (t - min_elem))
            classification_array[k] += 1

    def transform(self, classification_array):
        for i in range(1, len(classification_array)):
            classification_array[i] += classification_array[i - 1]

    def permute(self, arr, classification_array, c1, min_elem, n, m):
        move = 0
        j = 0
        k = m - 1
        flash = None

        while move < n - 1:
            while j > classification_array[k] - 1:
                j += 1
                k = int(c1 * (arr[j] - min_elem))

            flash = arr[j]
            while j != classification_array[k]:
                k = int(c1 * (flash - min_elem))
                arr[classification_array[k] - 1], flash = flash, arr[classification_array[k] - 1]
                classification_array[k] -= 1
                move += 1

    def insertion_sort(self, arr):
        for i in range(1, len(arr)):
            key = arr[i]
            j = i - 1
            while j >= 0 and arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = key

if __name__ == "__main__":
    import sys

    # Read the number of elements in the array from the standard input
    n = int(sys.stdin.readline().strip())

    # Create an array of integers with the given size
    array = list(map(int, sys.stdin.readline().strip().split()))

    # Create a Main object and call the sort method to sort the array
    flash_sort = Main()
    flash_sort.sort(array)

    # Print the sorted array to the standard output
    print(" ".join(map(str, array)))

# <END-OF-CODE>
