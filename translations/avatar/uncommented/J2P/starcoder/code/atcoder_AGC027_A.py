
import sys

def main():
    N = int(raw_input())
    x = int(raw_input())
    sweet = []
    for i in range(N):
        a = int(raw_input())
        sweet.append(a)
    sweet.sort()
    num = 0
    for i in range(N):
        if x - sweet[num] >= 0:
            x = x - sweet[num]
            num += 1
        else:
            break
    if (num == N) and (x > 0):
        num -= 1
    print num

if __name__ == "__main__":
    main()

