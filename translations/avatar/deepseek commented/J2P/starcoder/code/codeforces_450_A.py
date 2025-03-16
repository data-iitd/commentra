
import sys

def main():
    n = int(input())
    m = int(input())
    q1 = []
    q2 = []
    for i in range(n):
        q1.append(int(input()))
        q2.append(i+1)
    ans = 0
    while len(q1) > 0:
        if q1[0] <= m:
            q1.pop(0)
            ans = q2.pop(0)
        elif q1[0] > m:
            x = q1.pop(0)
            val = x - m
            q1.append(val)
            val2 = q2.pop(0)
            q2.append(val2)
    print(ans)

if __name__ == "__main__":
    main()

