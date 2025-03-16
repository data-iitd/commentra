import sys

def main():
    input = sys.stdin.readline
    x = [0] * 3
    max_val = 0

    # Step 1: Read input values for the array x and find the maximum value in x.
    for i in range(3):
        x[i] = int(input())
        max_val = max(max_val, x[i])

    k = int(input())
    a = [[] for _ in range(3)]

    # Step 2: Initialize a list of lists to store the input values for each sub-array.
    for i in range(3):
        a[i] = list(map(lambda y: int(y), input().split()))
        a[i].sort(reverse=True)

    ans = []

    # Step 6: Use nested loops to iterate through all possible combinations of elements from the three sub-arrays,
    # and add the sum of the selected elements to the result list if the product of their indices is less than or equal to k.
    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                if (i + 1) * (j + 1) * (m + 1) <= k:
                    tmp = a[0][i] + a[1][j] + a[2][m]
                    ans.append(tmp)

    # Step 7: Sort the result list in ascending order.
    ans.sort()

    # Step 8: Print the top k values from the result list in descending order.
    for i in range(k):
        print(ans[-i-1])

if __name__ == "__main__":
    main()
