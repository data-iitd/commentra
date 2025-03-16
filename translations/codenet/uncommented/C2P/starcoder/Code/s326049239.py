
#include <stdio.h>
#include <stdlib.h>

def main():
    a=0
    while(a!=-1):
        a=int(input())
        if(a!=-1):
            if(a<3):
                print("0")
            else:
                c=0
                k=0
                b=a
                while(a>0):
                    b=b-1
                    c=c+1
                    if(c==3):
                        k=k+1
                        c=0
                print(k)

main()

