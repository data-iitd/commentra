# Enter your code here. Read input from STDIN. Print output to STDOUT
A,B=map(int,input().split())
C=A+B
if A%3!=0 and B%3!=0 and C%3!=0:
    print("Impossible")
else:
    print("Possible")

