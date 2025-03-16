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
    def print_list(list_to_print):
        print(" ".join(map(str, list_to_print)))

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
        n = int(input())
        array = list(map(int, input().split()))

        # Example 1: Swap elements
        i, j = map(int, input().split())
        Main.swap(array, i, j)
        Main.print_array(array)

        # Example 2: Check if the array is sorted
        sorted_status = Main.is_sorted(array)
        print(sorted_status)

        # Example 3: Flip the array between two indices
        left, right = map(int, input().split())
        Main.flip(array, left, right)
        Main.print_array(array)

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
