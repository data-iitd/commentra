
import math
import sys
import os
import random
import re
import itertools
import datetime


def main():
    n = int(input())
    a = int(input())
    b = int(input())
    list1 = []
    list2 = []
    for i in range(a):
        list1.append(int(input()))
    for i in range(b):
        list2.append(int(input()))
    for i in range(n):
        if i+1 in list1:
            print(1, end=" ")
        else:
            print(2, end=" ")


if __name__ == "__main__":
    main()


