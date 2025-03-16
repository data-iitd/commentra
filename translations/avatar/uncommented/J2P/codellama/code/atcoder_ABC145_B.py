
import sys
import math

def cout(str):
    print(str)

def main():
    cin = sys.stdin
    n = int(cin.readline())
    str = cin.readline()
    a = ""
    b = ""
    for i in range(0, n//2):
        a = a + str[i]
    if str == a + a:
        cout("Yes")
    else:
        cout("No")

if __name__ == "__main__":
    main()

