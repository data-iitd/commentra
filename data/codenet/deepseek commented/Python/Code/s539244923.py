
n,k=map(int,input().split())
# Taking two inputs n and k from the user and converting them to integers
print(n+k if k%n ==0 else k-n)
# If k modulo n equals 0, print the sum of n and k, otherwise print k-n

