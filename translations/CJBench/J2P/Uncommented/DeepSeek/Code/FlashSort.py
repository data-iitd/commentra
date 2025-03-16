class Main:
    def __init__(self, classification_ratio=0.45):
        if not (0 < classification_ratio < 1):
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classification_ratio = classification_ratio

    def set_classification_ratio(self, classification_ratio):
        if not (0 < classification_ratio < 1):
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classification_ratio = classification_ratio

    def sort(self, array):
        self.flash_sort(array)
        return array

    def flash_sort(self, arr):
        if len(arr) == 0:
            return
        min_val = min(arr)
        max_index = arr.index(max(arr))
        if arr[max_index] == min_val:
            return
        m = int(self.classification_ratio * len(arr))
        classification_array = [0] * m
        c1 = (m - 1) / (arr[max_index] - min_val)
        self.classify(arr, classification_array, c1, min_val)
        self.transform(classification_array)
        self.permute(arr, classification_array, c1, min_val, len(arr), m)
        self.insertion_sort(arr)

    def find_min(self, arr):
        return min(arr)

    def find_max_index(self, arr):
        return arr.index(max(arr))

    def classify(self, arr, classification_array, c1, min_val):
        for t in arr:
            k = int(c1 * (t - min_val))
            classification_array[k] += 1

    def transform(self, classification_array):
        for i in range(1, len(classification_array)):
            classification_array[i] += classification_array[i - 1]

    def permute(self, arr, classification_array, c1, min_val, n, m):
        move = 0
        j = 0
        k = m - 1
        while move < n - 1:
            while j > classification_array[k] - 1:
                j += 1
                k = int(c1 * (arr[j] - min_val))
            flash = arr[j]
            while j != classification_array[k]:
                k = int(c1 * (flash - min_val))
                temp = arr[classification_array[k] - 1]
                arr[classification_array[k] - 1] = flash
                flash = temp
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
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    array = list(map(int, data[1:n+1]))
    flash_sort = Main()
    sorted_array = flash_sort.sort(array)
    print(" ".join(map(str, sorted_array)))
