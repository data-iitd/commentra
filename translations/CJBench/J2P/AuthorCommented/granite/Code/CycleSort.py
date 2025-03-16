
import sys

class Main:
    def __init__(self):
        self.array = []

    def sort(self, array):
        for cycle_start in range(len(array) - 1):
            item = array[cycle_start]
            pos = self.find_position(array, cycle_start, item)

            if pos == cycle_start:
                continue  # Item is already in the correct position

            item = self.place_item(array, item, pos)

            # Rotate the rest of the cycle
            while pos!= cycle_start:
                pos = self.find_position(array, cycle_start, item)
                item = self.place_item(array, item, pos)

        return array

    def find_position(self, array, cycle_start, item):
        pos = cycle_start
        for i in range(cycle_start + 1, len(array)):
            if array[i] < item:
                pos += 1
        return pos

    def place_item(self, array, item, pos):
        while array[pos] == item:
            pos += 1
        return self.replace(array, pos, item)

    def replace(self, array, pos, item):
        replaced_item = array[pos]
        array[pos] = item
        return replaced_item

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))

    sorter = Main()
    sorted_array = sorter.sort(array)

    print(" ".join(map(str, sorted_array)))

