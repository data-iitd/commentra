import sys

def min(x, y):
    return y if x > y else x

def main():
    S = sys.stdin.read().strip()

    l0, l1 = 0, 0
    for char in S:
        if char == '0':
            l0 += 1
        else:
            l1 += 1

    print(2 * min(l0, l1))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
