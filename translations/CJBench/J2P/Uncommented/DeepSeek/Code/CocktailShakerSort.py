class Main:
    def sort(self, array):
        if len(array) == 0:
            return
        left = 0
        right = len(array) - 1
        while left < right:
            right = self.perform_forward_pass(array, left, right)
            left = self.perform_backward_pass(array, left, right)

    def perform_forward_pass(self, array, left, right):
        last_swapped_index = left
        for i in range(left, right):
            if array[i] > array[i + 1]:
                self.swap(array, i, i + 1)
                last_swapped_index = i
        return last_swapped_index

    def perform_backward_pass(self, array, left, right):
        last_swapped_index = right
        for i in range(right, left, -1):
            if array[i] < array[i - 1]:
                self.swap(array, i - 1, i)
                last_swapped_index = i
        return last_swapped_index

    def swap(self, array, i, j):
        array[i], array[j] = array[j], array[i]

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))
    sorter = Main()
    sorter.sort(array)
    print(" ".join(map(str, array)))

# <END-OF-CODE>











