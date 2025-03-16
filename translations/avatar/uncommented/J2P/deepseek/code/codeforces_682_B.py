import sys

def main():
    n = int(input().strip())
    list_ = list(map(int, input().strip().split()))
    list_.sort()
    c = 1
    for i in range(n):
        if list_[i] >= c:
            c += 1
    print(c)

if __name__ == "__main__":
    main()
