
import sys

def sort(array):
    if len(array) == 0:
        return array
    checkForNegativeInput(array)
    radixSort(array)
    return array

def checkForNegativeInput(array):
    for number in array:
        if number < 0:
            raise Exception("Array contains negative integers.")

def radixSort(array):
    max = max(array)
    for exp in range(1, int(max / 10) + 1):
        countingSortByDigit(array, exp)

def countingSortByDigit(array, exp):
    count = [0] * 10
    output = [0] * len(array)
    for i in range(len(array)):
        count[(array[i] / exp) % 10] += 1
    for i in range(1, 10):
        count[i] += count[i - 1]
    for i in range(len(array) - 1, -1, -1):
        digit = (array[i] / exp) % 10
        output[count[digit] - 1] = array[i]
        count[digit] -= 1
    for i in range(len(array)):
        array[i] = output[i]

if __name__ == '__main__':
    n = int(sys.stdin.readline().strip())
    array = [int(sys.stdin.readline().strip()) for _ in range(n)]
    print(" ".join(map(str, sort(array))))

