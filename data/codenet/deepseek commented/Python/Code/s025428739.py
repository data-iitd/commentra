
A,B = map(int,input().split())  # Step 1: Take two integer inputs A and B, split them by spaces, and convert them into integers.
lst = []  # Step 2: Initialize an empty list called lst.
lst.append(A+B)  # Step 3: Append the sum of A and B to the list lst.
lst.append(A-B)  # Step 4: Append the difference of A and B to the list lst.
lst.append(A*B)  # Step 5: Append the product of A and B to the list lst.
print(max(lst))  # Step 6: Print the maximum value in the list lst.

