
#include<stdio.h>

def compare(a, b):
    return (b - a)

def main():
    array = [0] * 10
    for i in range(0, 10):
        array[i] = int(input())
    array.sort(key=compare)
    for i in range(0, 3):
        print(array[i])

if __name__ == "__main__":
    main()

