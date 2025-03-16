
import sys
def CountingSort(a,b,k):
    c=[0]*10001
    for i in range(k):
        c[a[i]]+=1
    for i in range(1,10001):
        c[i]+=c[i-1]
    for j in range(k-1,-1,-1):
        b[c[a[j]]-1]=a[j]
        c[a[j]]-=1
def main():
    n=int(input())
    a=[0]*(n+1)
    b=[0]*(n+1)
    for i in range(n):
        a[i+1]=int(input())
    CountingSort(a,b,n)
    print(b[1],end="")
    for i in range(2,n+1):
        print(" "+str(b[i]),end="")
    print()
if __name__ == "__main__":
    main()
