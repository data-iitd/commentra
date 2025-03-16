
import sys

# Implementation of Flash Sort algorithm that implements the SortAlgorithm interface.
#
# Sorts an array using the Flash Sort algorithm.
#
# Flash Sort is a distribution sorting algorithm that partitions the data into
# different classes based on a classification array. It performs the sorting by
# first distributing the data elements into different buckets (or classes) and
# then permuting these buckets into the sorted order.
#
# The method works as follows:
#
#     <ol>
#         <li>Finds the minimum and maximum values in the array.</li>
#         <li>Initializes a classification array `L` to keep track of the number of elements in each class.</li>
#         <li>Computes a normalization constant `c1` to map elements into classes.</li>
#         <li>Classifies each element of the array into the corresponding bucket in the classification array.</li>
#         <li>Transforms the classification array to compute the starting indices of each bucket.</li>
#         <li>Permutes the elements of the array into sorted order based on the classification.</li>
#         <li>Uses insertion sort for the final arrangement to ensure complete sorting.</li>
#     </ol>

class FlashSort:
    def __init__(self, classification_ratio=0.45):
        if classification_ratio <= 0 or classification_ratio >= 1:
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classification_ratio = classification_ratio

    def sort(self, array):
        self.flash_sort(array)
        return array

    def flash_sort(self, arr):
        if len(arr) == 0:
            return

        min = self.find_min(arr)
        max_index = self.find_max_index(arr)

        if arr[max_index] == min:
            return # All elements are the same

        m = int(self.classification_ratio * len(arr))
        classification_array = [0] * m
        c1 = (m - 1) / arr[max_index]

        self.classify(arr, classification_array, c1, min)
        self.transform(classification_array)
        self.permute(arr, classification_array, c1, min, len(arr), m)
        self.insertion_sort(arr)

    def find_min(self, arr):
        min = arr[0]
        for t in arr:
            if t < min:
                min = t
        return min

    def find_max_index(self, arr):
        max_index = 0
        for i in range(1, len(arr)):
            if arr[i] > arr[max_index]:
                max_index = i
        return max_index

    def classify(self, arr, classification_array, c1, min):
        for t in arr:
            k = int(c1 * t)
            classification_array[k] += 1

    def transform(self, classification_array):
        for i in range(1, len(classification_array)):
            classification_array[i] += classification_array[i - 1]

    def permute(self, arr, classification_array, c1, min, n, m):
        move = 0
        j = 0
        k = m - 1
        flash = arr[j]
        while move < n - 1:
            while j > classification_array[k] - 1:
                j += 1
                k = int(c1 * arr[j])
            flash = arr[j]
            while j != classification_array[k]:
                k = int(c1 * flash)
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


# Main function
if __name__ == "__main__":
    # Input array size
    n = int(input())
    array = list(map(int, input().split()))

    flash_sort = FlashSort()
    flash_sort.sort(array)

    # Print sorted array
    for num in array:
        print(num, end=" ")

    # END-OF-CODE
