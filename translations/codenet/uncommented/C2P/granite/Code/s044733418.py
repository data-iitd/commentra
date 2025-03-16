
import sys

def compare(a, b):
    return b - a

def main():
    array = [int(x) for x in sys.stdin.read().split()]
    array.sort(cmp=compare)
    for i in range(3):
        print(array[i])

if __name__ == "__main__":
    main()

