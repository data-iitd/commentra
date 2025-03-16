import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

class Main:
    def __init__(self):
        pass
    @staticmethod
    def main(args):
        scanner = Scanner(System.in)
        n = scanner.nextInt()
        array = [0] * n
        for i in range(n):
            array[i] = scanner.nextInt()
        i = scanner.nextInt()
        j = scanner.nextInt()
        swap(array, i, j)
        print(array)
        sorted = isSorted(array)
        print(sorted)
        left = scanner.nextInt()
        right = scanner.nextInt()
        flip(array, left, right)
        print(array)
        scanner.close()
    @staticmethod
    def swap(array, i, j):
        if i!= j:
            temp = array[i]
            array[i] = array[j]
            array[j] = temp
    @staticmethod
    def less(firstElement, secondElement):
        return firstElement.compareTo(secondElement) < 0
    @staticmethod
    def greater(firstElement, secondElement):
        return firstElement.compareTo(secondElement) > 0
    @staticmethod
    def greaterOrEqual(firstElement, secondElement):
        return firstElement.compareTo(secondElement) >= 0
    @staticmethod
    def print(listToPrint):
        result = listToPrint.stream().map(Object::toString).collect(Collectors.joining(" "))
        print(result)
    @staticmethod
    def print(array):
        print(Arrays.toString(array))
    @staticmethod
    def flip(array, left, right):
        while left <= right:
            swap(array, left, right)
            left += 1
            right -= 1
    @staticmethod
    def isSorted(array):
        for i in range(1, len(array)):
            if less(array[i], array[i - 1]):
                return False
        return True
    @staticmethod
    def isSorted(list):
        for i in range(1, len(list)):
            if less(list.get(i), list.get(i - 1)):
                return False
        return True

if __name__ == "__main__":
    Main.main(None)

