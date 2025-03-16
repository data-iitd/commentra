import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

class Main:
    # Private constructor to prevent instantiation of the Main class
    def __init__(self):
        pass

    @staticmethod
    def main(args):
        # Create a Scanner object to read input from the user
        scanner = Scanner(System.in)
        
        # Read the size of the array
        n = scanner.nextInt()
        array = [None] * n
        
        # Populate the array with user input
        for i in range(n):
            array[i] = scanner.nextInt()
        
        # Read the indices to swap in the array
        i = scanner.nextInt()
        j = scanner.nextInt()
        
        # Swap the elements at the specified indices
        Main.swap(array, i, j)
        
        # Print the array after the swap operation
        Main.print(array)
        
        # Check if the array is sorted and print the result
        sorted = Main.isSorted(array)
        print(sorted)
        
        # Read the indices for the flip operation
        left = scanner.nextInt()
        right = scanner.nextInt()
        
        # Flip the elements in the array between the specified indices
        Main.flip(array, left, right)
        
        # Print the array after the flip operation
        Main.print(array)
        
        # Close the scanner to prevent resource leaks
        scanner.close()

    # Method to swap two elements in an array
    @staticmethod
    def swap(array, i, j):
        if i!= j:
            temp = array[i]
            array[i] = array[j]
            array[j] = temp

    # Method to compare if the first element is less than the second
    @staticmethod
    def less(firstElement, secondElement):
        return firstElement.compareTo(secondElement) < 0

    # Method to compare if the first element is greater than the second
    @staticmethod
    def greater(firstElement, secondElement):
        return firstElement.compareTo(secondElement) > 0

    # Method to compare if the first element is greater than or equal to the second
    @staticmethod
    def greaterOrEqual(firstElement, secondElement):
        return firstElement.compareTo(secondElement) >= 0

    # Method to print a list of elements
    @staticmethod
    def print(listToPrint):
        result = listToPrint.stream().map(Object::toString).collect(Collectors.joining(" "))
        print(result)

    # Method to print an array of elements
    @staticmethod
    def print(array):
        print(Arrays.toString(array))

    # Method to flip elements in an array between two indices
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

    # Overloaded method to check if a list is sorted
    @staticmethod
    def isSorted(list):
        for i in range(1, len(list)):
            if Main.less(list.get(i), list.get(i - 1)):
                return False
        return True

# 