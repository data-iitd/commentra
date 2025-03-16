#include<stdio.h>

def you(x,y):
    z=0
    while(1):
        z=x%y
        x=y
        y=z
        if(y<=0):
            break
    return x

def main():
    x=int(input("Enter the first number: "))
    y=int(input("Enter the second number: "))
    if(x>=y):
        z=you(x,y)
    else:
        z=you(y,x)
    print(z)

main()

