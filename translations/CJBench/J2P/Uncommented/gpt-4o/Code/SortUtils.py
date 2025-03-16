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

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))
    i = int(input())
    j = int(input())
    Main.swap(array, i, j)
    Main.print_array(array)
    sorted_status = Main.is_sorted(array)
    print(sorted_status)
    left = int(input())
    right = int(input())
    Main.flip(array, left, right)
    Main.print_array(array)

# <END-OF-CODE>
