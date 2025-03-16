# Step 1: Read the number of test cases.
n=int(input())
# Step 2: Read the number of elements in the array.
for i in range(n):
    # Step 3: Read the elements of the array.
    a=int(input())
    # Step 4: Sort the array.
    a.sort()
    # Step 5: Remove duplicates from the array.
    for j in range(len(a)-1):
        if a[j]==a[j+1]:
            a.pop(j)
            j-=1
    # Step 6: Print the product of the two largest distinct elements.
    print(a[-1]*a[-2])
# 