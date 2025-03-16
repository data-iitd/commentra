
import sys

def main():
    str = input()
    k = int(input())
    c = list(str)
    n = len(str)

    for i in range(k):
        if c[i] == '1':
            if i == k - 1:
                print(1)
                sys.exit()
        else:
            print(c[i])
            sys.exit()

if __name__ == "__main__":
    main()

