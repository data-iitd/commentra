
import sys

def main():
    sys.stdin.readline()
    str = sys.stdin.readline().strip()
    sum = 0
    for x in str:
        sum += int(x)
    if sum % 9 == 0:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

