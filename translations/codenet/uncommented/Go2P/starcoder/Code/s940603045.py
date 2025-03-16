import sys
import math
import random
import time

# const abcd = "abcdefghijklmnopqrstuvwxyz"
# const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]

inf = 10**18

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         b.append(i)
#     n = 0
#     for i in b:
#         n += int(i)
#     m = int(N)
#     if m%n == 0:
#         print("Yes")
#     else:
#         print("No")

# def main():
#     N = input()
#     b = []
#     for i in N:
#         