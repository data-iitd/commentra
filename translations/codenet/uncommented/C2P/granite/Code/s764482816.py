
import sys

def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
    return arr

if __name__ == "__main__":
    arr = list(map(int, sys.stdin.readline().split()))
    sorted_arr = bubble_sort(arr)
    print(*sorted_arr, sep=" ")

