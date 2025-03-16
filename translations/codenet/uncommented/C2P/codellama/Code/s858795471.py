#include<stdio.h>
def search(A,n,key):
    i=0
    A[n]=key
    while A[i]!=key: i+=1
    return i!=n

def main():
    n,A=[],[]
    q,key,sum=0,0,0
    i=0
    
    n=int(input())
    for i in range(n):
        A.append(int(input()))
    q=int(input())
    for i in range(q):
        key=int(input())
        if search(A,n,key): sum+=1
    print(sum)

if __name__ == "__main__":
    main()
