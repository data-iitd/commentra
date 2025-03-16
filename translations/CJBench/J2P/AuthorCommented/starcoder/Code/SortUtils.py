import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

final class Main {

    private Main() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        # Input: Array elements
        n = scanner.nextInt()
        array = [0] * n
        for i in range(n):
            array[i] = scanner.nextInt()

        # Perform operations
        # Example 1: Swap elements
        i = scanner.nextInt()
        j = scanner.nextInt()
        swap(array, i, j)
        print(array)

        # Example 2: Check if the array is sorted
        sorted = isSorted(array)
        print(sorted)

        # Example 3: Flip the array between two indices
        left = scanner.nextInt()
        right = scanner.nextInt()
        flip(array, left, right)
        print(array)

        scanner.close()
    }

    # Swaps two elements at the given positions in an array.
    @staticmethod
    def swap(array, i, j):
        if i!= j:
            temp = array[i]
            array[i] = array[j]
            array[j] = temp

    # Compares two elements to see if the first is less than the second.
    @staticmethod
    def less(firstElement, secondElement):
        return firstElement.compareTo(secondElement) < 0

    # Compares two elements to see if the first is greater than the second.
    @staticmethod
    def greater(firstElement, secondElement):
        return firstElement.compareTo(secondElement) > 0

    # Compares two elements to see if the first is greater than or equal to the second.
    @staticmethod
    def greaterOrEqual(firstElement, secondElement):
        return firstElement.compareTo(secondElement) >= 0

    # Prints the elements of a list to standard output.
    @staticmethod
    def print(listToPrint):
        result = " ".join(map(str, listToPrint))
        print(result)

    # Prints the elements of an array to standard output.
    @staticmethod
    def print(array):
        print(array)

    # Flips the order of elements in the specified range of an array.
    @staticmethod
    def flip(array, left, right):
        while left <= right:
            swap(array, left, right)
            left += 1
            right -= 1

    # Checks whether the array is sorted in ascending order.
    @staticmethod
    def isSorted(array):
        for i in range(1, len(array)):
            if less(array[i], array[i - 1]):
                return False
        return True

    # Checks whether the list is sorted in ascending order.
    @staticmethod
    def isSorted(list):
        for i in range(1, len(list)):
            if less(list[i], list[i - 1]):
                return False
        return True
}

