import sys

def main():
    n = int(sys.stdin.readline())
    array = list(map(int, sys.stdin.readline().split()))
    sorter = Main()
    sorted_array = sorter.sort(array)
    for num in sorted_array:
        print(num, end=" ")

class Main:
    def sort(self, array):
        length = len(array)
        for cycle_start in range(length - 1):
            item = array[cycle_start]
            pos = self.find_position(array, cycle_start, item)
            if pos == cycle_start:
                continue
            item = self.place_item(array, item, pos)
            while pos != cycle_start:
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
        while item == array[pos]:
            pos += 1
        return self.replace(array, pos, item)

    def replace(self, array, pos, item):
        replaced_item = array[pos]
        array[pos] = item
        return replaced_item

if __name__ == "__main__":
    main()

