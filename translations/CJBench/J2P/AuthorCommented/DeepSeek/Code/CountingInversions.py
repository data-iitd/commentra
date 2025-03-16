def count_inversions(arr):
    def merge_sort_and_count(arr, left, right):
        if left >= right:
            return 0

        mid = left + (right - left) // 2
        inversions = 0

        inversions += merge_sort_and_count(arr, left, mid)
        inversions += merge_sort_and_count(arr, mid + 1, right)
        inversions += merge_and_count(arr, left, mid, right)
        return inversions

    def merge_and_count(arr, left, mid, right):
        left_arr = arr[left:mid + 1]
        right_arr = arr[mid + 1:right + 1]

        i = 0
        j = 0
        k = left
        inversions = 0

        while i < len(left_arr) and j < len(right_arr):
            if left_arr[i] <= right_arr[j]:
                arr[k] = left_arr[i]
                i += 1
            else:
                arr[k] = right_arr[j]
                j += 1
                inversions += mid + 1 - left - i
            k += 1

        while i < len(left_arr):
            arr[k] = left_arr[i]
            i += 1
            k += 1

        while j < len(right_arr):
            arr[k] = right_arr[j]
            j += 1
            k += 1

        return inversions

    return merge_sort_and_count(arr, 0, len(arr) - 1)


# Example usage:
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    arr = [int(x) for x in data[1:n+1]]

    result = count_inversions(arr)
    print("Number of inversions:", result)
