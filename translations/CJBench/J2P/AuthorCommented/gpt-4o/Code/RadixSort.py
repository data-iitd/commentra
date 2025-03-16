import sys

class Main:
    BASE = 10

    @staticmethod
    def main():
        # Input: Size of the array
        n = int(input())
        array = list(map(int, input().split()))

        # Perform Radix Sort
        Main.sort(array)

        # Output: Sorted array
        print(" ".join(map(str, array)))

    @staticmethod
    def sort(array):
        if len(array) == 0:
            return array

        Main.check_for_negative_input(array)
        Main.radix_sort(array)
        return array

    @staticmethod
    def check_for_negative_input(array):
        for number in array:
            if number < 0:
                raise ValueError("Array contains negative integers.")

    @staticmethod
    def radix_sort(array):
        max_value = max(array)
        exp = 1
        while max_value // exp > 0:
            Main.counting_sort_by_digit(array, exp)
            exp *= Main.BASE

    @staticmethod
    def counting_sort_by_digit(array, exp):
        count = [0] * Main.BASE
        output = [0] * len(array)

        for i in range(len(array)):
            count[(array[i] // exp) % Main.BASE] += 1

        for i in range(1, Main.BASE):
            count[i] += count[i - 1]

        for i in range(len(array) - 1, -1, -1):
            digit = (array[i] // exp) % Main.BASE
            output[count[digit] - 1] = array[i]
            count[digit] -= 1

        for i in range(len(array)):
            array[i] = output[i]

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
