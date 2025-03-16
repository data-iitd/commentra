class Main:
    @staticmethod
    def main():
        rows = int(input())
        cols = int(input())
        arr = []
        for _ in range(rows):
            arr.append(list(map(int, input().split())))
        target = int(input())
        result = Main.binary_search(arr, target)
        print(result[0], result[1])

    @staticmethod
    def binary_search(arr, target):
        row_count = len(arr)
        col_count = len(arr[0])
        if row_count == 1:
            return Main.binary_search_single_row(arr, target, 0, 0, col_count - 1)
        
        start_row = 0
        end_row = row_count - 1
        mid_col = col_count // 2
        
        while start_row < end_row - 1:
            mid_row = start_row + (end_row - start_row) // 2
            if arr[mid_row][mid_col] == target:
                return [mid_row, mid_col]
            elif arr[mid_row][mid_col] < target:
                start_row = mid_row
            else:
                end_row = mid_row
        
        if arr[start_row][mid_col] == target:
            return [start_row, mid_col]
        if arr[end_row][mid_col] == target:
            return [end_row, mid_col]
        
        if target <= arr[start_row][mid_col - 1]:
            return Main.binary_search_single_row(arr, target, start_row, 0, mid_col - 1)
        if target >= arr[start_row][mid_col + 1] and target <= arr[start_row][col_count - 1]:
            return Main.binary_search_single_row(arr, target, start_row, mid_col + 1, col_count - 1)
        if target <= arr[end_row][mid_col - 1]:
            return Main.binary_search_single_row(arr, target, end_row, 0, mid_col - 1)
        
        return Main.binary_search_single_row(arr, target, end_row, mid_col + 1, col_count - 1)

    @staticmethod
    def binary_search_single_row(arr, target, row, col_start, col_end):
        while col_start <= col_end:
            mid_index = col_start + (col_end - col_start) // 2
            if arr[row][mid_index] == target:
                return [row, mid_index]
            elif arr[row][mid_index] < target:
                col_start = mid_index + 1
            else:
                col_end = mid_index - 1
        return [-1, -1]

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
