
import sys

def main():
    x = [0, 0, 0]
    max = 0

    # Step 1: Read input values for the array x and find the maximum value in x.
    for i in range(3):
        x[i] = int(sys.stdin.readline())
        max = max if max > x[i] else x[i]

    k = int(sys.stdin.readline())
    a = [[], [], []]

    # Step 2: Initialize a list of lists to store the input values for each sub-array.
    for i in range(3):
        a[i] = []

    # Step 3: Read input values for each sub-array, sort them, and store them in the list of lists.
    for i in range(3):
        for j in range(x[i]):
            a[i].append(int(sys.stdin.readline()))
        a[i].sort()

    ans = []

    # Step 5: Initialize an empty list to store the results.
    # Step 6: Use nested loops to iterate through all possible combinations of elements from the three sub-arrays,
    # and add the sum of the selected elements to the result list if the product of their indices is less than or equal to k.
    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                if ((i + 1) * (j + 1) * (m + 1) <= k):
                    tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1]
                    ans.append(tmp)

    # Step 7: Sort the result list in ascending order.
    ans.sort()

    n = len(ans)

    # Step 8: Print the top k values from the result list in descending order.
    for i in range(k):
        print(ans[n - i - 1])

if __name__ == "__main__":
    main()

