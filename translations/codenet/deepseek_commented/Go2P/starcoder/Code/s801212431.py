import sys

def main():
    S = sys.stdin.readline().strip()

    # Initialize counters for '0's and '1's
    l0, l1 = 0, 0
    for i in range(len(S)):
        if S[i] == '0':
            l0 += 1
        else:
            l1 += 1
    print(2 * min(l0, l1))

if __name__ == "__main__":
    main()

