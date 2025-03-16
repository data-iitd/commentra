class Main:
    @staticmethod
    def swap(array, i, j):
        if i != j:
            array[i], array[j] = array[j], array[i]

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
            Main.swap(array, left, right)
            left += 1
            right -= 1

    @staticmethod
    def is_sorted(array):
        for i in range(1, len(array)):
            if Main.less(array[i], array[i - 1]):
                return False
        return True

    @staticmethod
    def is_sorted_list(lst):
        for i in range(1, len(lst)):
            if Main.less(lst[i], lst[i - 1]):
                return False
        return True

    @staticmethod
    def main():
        # Read the size of the array
        n = int(input())
        array = list(map(int, input().split()))

        # Read the indices to swap in the array
        i, j = map(int, input().split())

        # Swap the elements at the specified indices
        Main.swap(array, i, j)

        # Print the array after the swap operation
        Main.print_array(array)

        # Check if the array is sorted and print the result
        sorted_status = Main.is_sorted(array)
        print(sorted_status)

        # Read the indices for the flip operation
        left, right = map(int, input().split())

        # Flip the elements in the array between the specified indices
        Main.flip(array, left, right)

        # Print the array after the flip operation
        Main.print_array(array)

# Entry point of the program
if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
