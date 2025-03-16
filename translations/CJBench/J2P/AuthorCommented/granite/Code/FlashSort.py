
import random

class FlashSort:
    def __init__(self, classification_ratio=0.45):
        if classification_ratio <= 0 or classification_ratio >= 1:
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classification_ratio = classification_ratio

    def set_classification_ratio(self, classification_ratio):
        if classification_ratio <= 0 or classification_ratio >= 1:
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classification_ratio = classification_ratio

    def sort(self, array):
        flash_sort(array)
        return array

def flash_sort(array):
    if len(array) == 0:
        return

    min_val = min(array)
    max_index = array.index(max(array))

    if array[max_index] == min_val:
        return  # All elements are the same

    m = int(self.classification_ratio * len(array))
    classification_array = [0] * m
    c1 = (m - 1) / (array[max_index] - min_val)

    classify(array, classification_array, c1, min_val)
    transform(classification_array)
    permute(array, classification_array, c1, min_val, len(array), m)
    insertion_sort(array)

def find_min(array):
    min_val = array[0]
    for val in array:
        if val < min_val:
            min_val = val
    return min_val

def find_max_index(array):
    max_index = 0
    for i in range(1, len(array)):
        if array[i] > array[max_index]:
            max_index = i
    return max_index

def classify(array, classification_array, c1, min_val):
    for val in array:
        k = int(c1 * (val - min_val))
        classification_array[k] += 1

def transform(classification_array):
    for i in range(1, len(classification_array)):
        classification_array[i] += classification_array[i - 1]

def permute(array, classification_array, c1, min_val, n, m):
    move = 0
    j = 0
    k = m - 1
    flash = None
    while move < n - 1:
        while j > classification_array[k] - 1:
            j += 1
            k = int(c1 * (array[j] - min_val))
        flash = array[j]
        while j!= classification_array[k]:
            k = int(c1 * (flash - min_val))
            temp = array[classification_array[k] - 1]
            array[classification_array[k] - 1] = flash
            flash = temp
            classification_array[k] -= 1
            move += 1

def insertion_sort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key

if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    array = [int(x) for x in input("Enter the elements of the array: ").split()]

    flash_sort = FlashSort()
    sorted_array = flash_sort.sort(array)

    print("Sorted array:", sorted_array)

