
import sys
import random

class Main:
    def __init__(self, classificationRatio=0.45):
        if classificationRatio <= 0 or classificationRatio >= 1:
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classificationRatio = classificationRatio

    def setClassificationRatio(self, classificationRatio):
        if classificationRatio <= 0 or classificationRatio >= 1:
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classificationRatio = classificationRatio

    def sort(self, array):
        self.flashSort(array)
        return array

    def flashSort(self, array):
        if len(array) == 0:
            return
        min_val = min(array)
        max_index = array.index(max(array))
        if array[max_index] == min_val:
            return
        m = int(self.classificationRatio * len(array))
        classification_array = [0] * m
        c1 = (m - 1) / (array[max_index] - min_val)
        self.classify(array, classification_array, c1, min_val)
        self.transform(classification_array)
        self.permute(array, classification_array, c1, min_val, len(array), m)
        self.insertionSort(array)

    def classify(self, array, classification_array, c1, min_val):
        for num in array:
            k = int(c1 * (num - min_val))
            classification_array[k] += 1

    def transform(self, classification_array):
        for i in range(1, len(classification_array)):
            classification_array[i] += classification_array[i - 1]

    def permute(self, array, classification_array, c1, min_val, n, m):
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
                array[classification_array[k] - 1], flash = flash, array[classification_array[k] - 1]
                classification_array[k] -= 1
                move += 1

    def insertionSort(self, array):
        for i in range(1, len(array)):
            key = array[i]
            j = i - 1
            while j >= 0 and array[j] > key:
                array[j + 1] = array[j]
                j -= 1
            array[j + 1] = key

    @staticmethod
    def main():
        n = int(input())
        array = [int(num) for num in input().split()]
        flash_sort = Main()
        flash_sort.sort(array)
        print(*array)

if __name__ == "__main__":
    Main.main()

