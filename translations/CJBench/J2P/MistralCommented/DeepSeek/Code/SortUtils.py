class Main:
    @staticmethod
    def swap(array, i, j):
        if i != j:
            # Temporary variable to store the element at index i
            temp = array[i]
            # Assigns the element at index j to index i
            array[i] = array[j]
            # Assigns the element stored in the temporary variable to index j
            array[j] = temp

    @staticmethod
    def less(first_element, second_element):
        return first_element < second_element

    @staticmethod
    def greater(first_element, second_element):
        return first_element > second_element

    @staticmethod
    def greater_or_equal(first_element, second_element):
        return first_element >= second_element

    @staticmethod
    def print_list(lst):
        print(" ".join(map(str, lst)))

    @staticmethod
    def print_array(array):
        print(array)

    @staticmethod
    def flip(array, left, right):
        while left <= right:
            # Swaps the elements at the given indices
            Main.swap(array, left, right)
            left += 1
            right -= 1

    @staticmethod
    def is_sorted(array):
        for i in range(1, len(array)):
            # Checks if the current element is less than the previous one
            if Main.less(array[i], array[i - 1]):
                return False
        return True

    @staticmethod
    def main():
        # Initializes a Scanner object to read input from the standard input stream
        n = int(input())

        # Creates an Integer array with the given size
        array = [int(input()) for _ in range(n)]

        # Reads the indices i and j of the two elements to be swapped from the standard input
        i = int(input())
        j = int(input())

        # Swaps the elements at the given indices in the array
        Main.swap(array, i, j)

        # Prints the swapped array
        Main.print_array(array)

        # Checks if the array is sorted in ascending order
        sorted_array = Main.is_sorted(array)

        # Prints whether the array is sorted or not
        print(sorted_array)

        # Reads the left and right indices of the subarray to be flipped from the standard input
        left = int(input())
        right = int(input())

        # Flips the subarray from left to right in the array
        Main.flip(array, left, right)

        # Prints the flipped array
        Main.print_array(array)

# Entry point of the program
if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>











