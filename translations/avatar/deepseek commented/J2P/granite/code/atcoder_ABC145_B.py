

import sys

def cout(str):
    print(str)

def main():
    cin = sys.stdin
    n = int(cin.readline())
    str = cin.readline().strip()
    a = str[:n//2]
    if str == a + a:
        cout("Yes")
    else:
        cout("No")

if __name__ == "__main__":
    main()

