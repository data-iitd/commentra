# Step 3: Create a Scanner object to read input from the user
# Note: In Python, we use the input() function to read input from the user

# Step 4: Read the values of n, a, and b
n, a, b = map(int, input().split())

# Step 5: Create two list objects to store the lists of integers
list1 = []
list2 = []

# Step 6: Read the elements of list1 and list2 from the user
list1 = list(map(int, input().split()))
list2 = list(map(int, input().split()))

# Step 7: Iterate through the range from 1 to n and print the appropriate list number
for i in range(1, n + 1):
    if i in list1:
        print(1, end=" ")
    else:
        print(2, end=" ")
