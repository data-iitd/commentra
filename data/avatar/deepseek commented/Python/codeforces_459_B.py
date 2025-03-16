# Step 1: Take an integer input `n` which represents the number of elements in the list `l1`.
n = int(input())

# Step 2: Take a space-separated string of integers, convert them into a list of integers, and store it in `l1`.
l1 = list(map(int, input().split()))

# Step 3: Sort the list `l1` in ascending order.
l1.sort()

# Step 4: Assign the last element of the sorted list `l1` to `a`, which is the maximum value in the list.
a = l1[-1]

# Step 5: Assign the first element of the sorted list `l1` to `b`, which is the minimum value in the list.
b = l1[0]

# Step 6: Check if `a` is equal to `b`.
if a == b:
    # Step 7: If `a` is equal to `b`, print the difference `a - b` and the number of ways to choose 2 elements from `n` elements.
    print(a - b, n * (n - 1) // 2)
else:
    # Step 8: If `a` is not equal to `b`, calculate the count of occurrences of `a` and `b` in the list `l1`.
    ac = l1.count(a)
    bc = l1.count(b)
    # Step 9: Print the difference `a - b` and the product of the counts of `a` and `b`.
    print(a - b, ac * bc)
