
import sys

class Main:
    def __init__(self):
        self.array = []

    def sort(self):
        if len(self.array) == 0:
            return

        left = 0
        right = len(self.array) - 1

        while left < right:
            right = self.perform_forward_pass(left, right)
            left = self.perform_backward_pass(left, right)

    def perform_forward_pass(self, left, right):
        last_swapped_index = left

        for i in range(left, right):
            if self.array[i] > self.array[i + 1]:
                self.swap(i, i + 1)
                last_swapped_index = i

        return last_swapped_index

    def perform_backward_pass(self, left, right):
        last_swapped_index = right

        for i in range(right, left, -1):
            if self.array[i] < self.array[i - 1]:
                self.swap(i - 1, i)
                last_swapped_index = i

        return last_swapped_index

    def swap(self, i, j):
        self.array[i], self.array[j] = self.array[j], self.array[i]

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))

    sorter = Main()
    sorter.array = array
    sorter.sort()

    print(" ".join(map(str, sorter.array)))

