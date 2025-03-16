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
    def print_array(array):
        print(" ".join(map(str, array)))

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
    def main():
        # Initialize input reading
        n = int(input())
        # Read the integers into the array
        array = list(map(int, input().split()))
        # Read the indices for swapping
        i, j = map(int, input().split())
        # Swap the elements at indices i and j
        Main.swap(array, i, j)
        # Print the array after swapping
        Main.print_array(array)
        # Check if the array is sorted and print the result
        sorted_status = Main.is_sorted(array)
        print(sorted_status)
        # Read the indices for flipping
        left, right = map(int, input().split())
        # Flip the subarray between the given indices
        Main.flip(array, left, right)
        # Print the array after flipping
        Main.print_array(array)

# Run the main function
if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>











