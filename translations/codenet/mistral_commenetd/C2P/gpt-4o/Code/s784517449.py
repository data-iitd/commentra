A = []  # initialize an empty list A
n = 0  # initialize an integer n

# Binary search function
def binary_search(key):
    left = 0  # initialize left index to 0
    right = n  # initialize right index to the last index of the array

    while left < right:  # while left index is less than right index
        mid = (left + right) // 2  # calculate middle index
        if key == A[mid]:  # if key is equal to the middle element
            return 1  # return 1 to indicate key is found
        if key > A[mid]:  # if key is greater than the middle element
            left = mid + 1  # update left index to search in the right half
        else:  # if key is less than the middle element
            right = mid  # update right index to search in the left half
    return 0  # if key is not found, return 0

# Main function
if __name__ == "__main__":
    n = int(input())  # read the number of elements in the array from the standard input
    A = list(map(int, input().split()))  # read and store the elements of the array
    q = int(input())  # read the number of queries from the standard input
    sum = 0  # initialize sum

    for _ in range(q):  # for loop to perform binary search for each query
        k = int(input())  # read the query key
        if binary_search(k):  # if key is found in the array
            sum += 1  # increment sum by 1

    print(sum)  # print the number of queries with a matching element in the array

# <END-OF-CODE>
