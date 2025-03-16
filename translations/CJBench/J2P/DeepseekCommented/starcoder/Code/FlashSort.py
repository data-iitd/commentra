import java.util.Scanner;
import java.util.Arrays;
class Main:
    def __init__(self, classificationRatio=0.45):
        if classificationRatio <= 0 or classificationRatio >= 1:
            raise Exception("Classification ratio must be between 0 and 1 (exclusive).")
        self.classificationRatio = classificationRatio
    def setClassificationRatio(self, classificationRatio):
        if classificationRatio <= 0 or classificationRatio >= 1:
            raise Exception("Classification ratio must be between 0 and 1 (exclusive).")
        self.classificationRatio = classificationRatio
    def sort(self, array):
        self.flashSort(array)
        return array
    def flashSort(self, arr):
        if len(arr) == 0:
            return
        min = self.findMin(arr)
        maxIndex = self.findMaxIndex(arr)
        if arr[maxIndex] == min:
            return
        m = int(self.classificationRatio * len(arr))
        classificationArray = [0] * m
        c1 = (m - 1) / (arr[maxIndex] - min)
        self.classify(arr, classificationArray, c1, min)
        self.transform(classificationArray)
        self.permute(arr, classificationArray, c1, min, len(arr), m)
        self.insertionSort(arr)
    def findMin(self, arr):
        min = arr[0]
        for t in arr:
            if t < min:
                min = t
        return min
    def findMaxIndex(self, arr):
        maxIndex = 0
        for i in range(1, len(arr)):
            if arr[i] > arr[maxIndex]:
                maxIndex = i
        return maxIndex
    def classify(self, arr, classificationArray, c1, min):
        for t in arr:
            k = int(c1 * (t - min))
            classificationArray[k] += 1
    def transform(self, classificationArray):
        for i in range(1, len(classificationArray)):
            classificationArray[i] += classificationArray[i - 1]
    def permute(self, arr, classificationArray, c1, min, n, m):
        move = 0
        j = 0
        k = m - 1
        flash = None
        while move < n - 1:
            while j > classificationArray[k] - 1:
                j += 1
                k = int(c1 * (arr[j] - min))
            flash = arr[j]
            while j!= classificationArray[k]:
                k = int(c1 * (flash - min))
                temp = arr[classificationArray[k] - 1]
                arr[classificationArray[k] - 1] = flash
                flash = temp
                classificationArray[k] -= 1
                move += 1
    def insertionSort(self, arr):
        for i in range(1, len(arr)):
            key = arr[i]
            j = i - 1
            while j >= 0 and arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = key
    def main(self):
        scanner = Scanner(System.in)
        n = scanner.nextInt()
        array = [0] * n
        for i in range(n):
            array[i] = scanner.nextInt()
        flashSort = Main()
        flashSort.sort(array)
        for num in array:
            print(num, end=" ")
        scanner.close()

