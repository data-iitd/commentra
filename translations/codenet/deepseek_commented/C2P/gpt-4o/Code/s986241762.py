n = int(input())  # Step 1: Read the value of n, which represents the number of elements in the array.
sum_diff = 0  # Initialize sum to store the total difference.
a = list(map(int, input().split()))  # Step 2: Read n elements into the array 'a'.

for i in range(1, n):  # Step 4: Iterate through the array and calculate the sum of the differences between consecutive elements.
    if a[i - 1] > a[i]:
        sum_diff += a[i - 1] - a[i]  # Add the difference to the sum.
        a[i] = a[i - 1]  # Update the current element to be at least as large as the previous one.

print(sum_diff)  # Step 5: Print the calculated sum.
# <END-OF-CODE>
