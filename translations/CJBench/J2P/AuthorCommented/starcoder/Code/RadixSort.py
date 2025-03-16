import sys

class Main:

    BASE = 10

    def __init__(self):
        pass

    def sort(self, array):
        if len(array) == 0:
            return array

        self.checkForNegativeInput(array)
        self.radixSort(array)
        return array

    def checkForNegativeInput(self, array):
        for number in array:
            if number < 0:
                raise Exception("Array contains negative integers.")

    def radixSort(self, array):
        max = max(array)
        for exp in range(1, int(max / self.BASE) + 1):
            self.countingSortByDigit(array, exp)

    def countingSortByDigit(self, array, exp):
        count = [0] * self.BASE
        output = [0] * len(array)

        for i in range(len(array)):
            count[(array[i] / exp) % self.BASE] += 1

        for i in range(1, self.BASE):
            count[i] += count[i - 1]

        for i in range(len(array) - 1, -1, -1):
            digit = (array[i] / exp) % self.BASE
            output[count[digit] - 1] = array[i]
            count[digit] -= 1

        for i in range(len(array)):
            array[i] = output[i]


if __name__ == "__main__":
    main = Main()
    array = [int(x) for x in sys.stdin.readline().split()]
    print(" ".join(str(x) for x in main.sort(array)))

