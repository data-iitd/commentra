
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

class Main:
    def __init__(self):
        pass
    @staticmethod
    def main():
        # Initialize Scanner to read input
        scanner = Scanner(System.in)
        # Read the number of elements
        n = scanner.nextInt()
        # Create an array to hold the integers
        array = [None] * n
        # Read the integers into the array
        for i in range(n):
            array[i] = scanner.nextInt()
        # Read the indices for swapping
        i = scanner.nextInt()
        j = scanner.nextInt()
        # Swap the elements at indices i and j
        Main.swap(array, i, j)
        # Print the array before and after swapping
        Main.print(array)
        # Check if the array is sorted and print the result
        sorted = Main.isSorted(array)
        print(sorted)
        # Read the indices for flipping
        left = scanner.nextInt()
        right = scanner.nextInt()
        # Flip the subarray between the given indices
        Main.flip(array, left, right)
        # Print the array after flipping
        Main.print(array)
        # Close the Scanner
        scanner.close()
    # Generic method to swap elements in an array
    @staticmethod
    def swap(array, i, j):
        if i!= j:
            temp = array[i]
            array[i] = array[j]
            array[j] = temp
    # Generic method to check if the first element is less than the second
    @staticmethod
    def less(firstElement, secondElement):
        return firstElement.compareTo(secondElement) < 0
    # Generic method to check if the first element is greater than the second
    @staticmethod
    def greater(firstElement, secondElement):
        return firstElement.compareTo(secondElement) > 0
    # Generic method to check if the first element is greater than or equal to the second
    @staticmethod
    def greaterOrEqual(firstElement, secondElement):
        return firstElement.compareTo(secondElement) >= 0
    # Method to print elements of a list
    @staticmethod
    def print(listToPrint):
        result = listToPrint.stream().map(Object::toString).collect(Collectors.joining(" "))
        print(result)
    # Method to print elements of an array
    @staticmethod
    def print(array):
        print(Arrays.toString(array))
    # Method to flip a subarray in the array
    @staticmethod
    def flip(array, left, right):
        while left <= right:
            Main.swap(array, left, right)
            left += 1
            right -= 1
    # Method to check if an array is sorted
    @staticmethod
    def isSorted(array):
        for i in range(1, len(array)):
            if Main.less(array[i], array[i - 1]):
                return False
        return True
    # Method to check if a list is sorted
    @staticmethod
    def isSorted(list):
        for i in range(1, len(list)):
            if Main.less(list.get(i), list.get(i - 1)):
                return False
        return True

# 