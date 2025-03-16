

ABC = list(map(int,input().split()))  # Taking input from the user and converting it into a list of integers

A = ABC[0]  # Assigning the first element of the list to variable A
B = ABC[1]  # Assigning the second element of the list to variable B
C = ABC[2]  # Assigning the third element of the list to variable C

print (max([ 10*A+B+C , 10*B+C+A , 10*C+A+B ]))  # Printing the maximum value among the three possible combinations of A, B, and C

