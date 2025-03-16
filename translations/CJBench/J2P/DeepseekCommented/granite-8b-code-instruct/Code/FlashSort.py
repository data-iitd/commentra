
import random
import math

class Main:
    def __init__(self, classification_ratio=0.45):
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

    def flash_sort(self, array):
        if len(array) == 0:
            return
        min_element = min(array)
        max_index = array.index(max(array))
        if array[max_index] == min_element:
            return
        m = math.floor(self.classification_ratio * len(array))
        classification_array = [0] * m
        c1 = (m - 1) / (array[max_index] - min_element)
        self.classify(array, classification_array, c1, min_element)
        self.transform(classification_array)
        self.permute(array, classification_array, c1, min_element, len(array), m)
        self.insertion_sort(array)

    def classify(self, array, classification_array, c1, min_element):
        for element in array:
            k = math.floor(c1 * (element - min_element))
            classification_array[k] += 1

    def transform(self, classification_array):
        for i in range(1, len(classification_array)):
            classification_array[i] += classification_array[i - 1]

    def permute(self, array, classification_array, c1, min_element, n, m):
        move = 0
        j = 0
        k = m - 1
        flash = None
        while move < n - 1:
            while j > classification_array[k] - 1:
                j += 1
                k = math.floor(c1 * (array[j] - min_element))
            flash = array[j]
            while j!= classification_array[k]:
                k = math.floor(c1 * (flash - min_element))
                array[classification_array[k] - 1], flash = flash, array[classification_array[k] - 1]
                classification_array[k] -= 1
                move += 1

    def insertion_sort(self, array):
        for i in range(1, len(array)):
            key = array[i]
            j = i - 1
            while j >= 0 and array[j] > key:
                array[j + 1] = array[j]
                j -= 1
            array[j + 1] = key

    def main():
        n = int(input("Enter the size of the array: "))
        array = [int(x) for x in input("Enter the elements of the array: ").split()]
        flash_sort = Main()
        sorted_array = flash_sort.sort(array)
        print("Sorted array:", sorted_array)

Main().main()

