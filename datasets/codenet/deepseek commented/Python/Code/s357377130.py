
A,B,K = map(int,input().split())
# Taking three integer inputs A, B, and K.

if A+K-1 >= B-K+1:
    # Checking if the condition A+K-1 >= B-K+1 is true.
    while A<=B:
        # Entering a loop where it prints the values of A from A to B.
        print(A)
        A+=1
else:
    i=0
    while i<=K-1:
        # First loop to print the values of A+i for i from 0 to K-1.
        print(A+i)
        i+=1
    while B-K+1<=B:
        # Second loop to print the values of B-K+1 down to B.
        print(B-K+1)
        K-=1

