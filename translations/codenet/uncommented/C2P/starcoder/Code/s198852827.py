
#include<stdio.h>

#define ABS(x) (((x)<(0))?(-(x)):(x))

def main():
    N=int(input())
    for i in range(N):
        t,x,y=map(int,input().split())
        tmp=t-nt-(ABS(x-nx)+ABS(y-ny))
        if(tmp<0 or tmp%2):
            print("No")
            return 0
    print("Yes")
    return 0

if __name__ == "__main__":
    main()

