
import sys

def main():
    x = int(sys.stdin.readline())
    i = 1
    sum = 0
    while True:
        sum += i
        if sum >= x:
            break
        i += 1
    print(i)

if __name__ == "__main__":
    main()

