
# Python code to sort the array using Quicksort and Merge Sort

# Function to partition the array and find the pivot index
def partition(arr, low, high):
    i = (low - 1)
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] <= pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)

# Function to sort the array using Quicksort
def quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)

# Function to merge two sorted subarrays
def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    L = [0] * (n1 + 1)
    R = [0] * (n2 + 1)

    for i in range(0, n1):
        L[i] = arr[left + i]

    for j in range(0, n2):
        R[j] = arr[mid + 1 + j]

    L[n1] = 1000000000
    R[n2] = 1000000000

    i = 0
    j = 0

    k = left

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

# Function to sort the array using Merge Sort
def mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)
        merge(arr, left, mid, right)

# Read the number of elements
n = int(input("Enter the number of elements: "))

# Read the characters and their corresponding numbers
arr = []
for i in range(n):
    char, num = input("Enter the character and number (separated by space): ").split()
    arr.append((char, int(num)))

# Copy the array to another array for Merge Sort
arr_copy = arr[:]

# Sort the copied array using Merge Sort
mergeSort(arr_copy, 0, n - 1)

# Sort the original array using Quicksort
quickSort(arr, 0, n - 1)

# Check if the sorting results are stable
stable = True
for i in range(n - 1):
    if arr[i][1] == arr[i + 1][1] and arr[i][0] > arr[i + 1][0]:
        stable = False
        break

# Print the stability result
if stable:
    print("Stable")
else:
    print("Not stable")

# Print the sorted characters and their corresponding numbers
for i in range(n):
    print(arr[i][0], arr[i][1])

