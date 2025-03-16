import sys

def main():
    n = int(input())
    T = {}

    for _ in range(n):
        com, str_ = input().split()
        if com == 'i':
            T[str_] = True
        else:
            if str_ in T:
                print("yes")
            else:
                print("no")

if __name__ == "__main__":
    main()
