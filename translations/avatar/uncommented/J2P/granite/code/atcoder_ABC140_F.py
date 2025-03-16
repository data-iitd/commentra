
import sys
import array
import bisect

def main():
    N = int(input())
    size = 1 << N
    S = array.array('i', (int(input()) for _ in range(size)))
    spawned = [False] * size
    spawned[-1] = True
    S.sort()
    active = [S[-1]]
    spawned[-1] = True
    for i in range(N):
        active.sort(reverse=True)
        activated = []
        next = size - 1
        for slime in active:
            while next >= 0 and (S[next] >= slime or spawned[next]):
                next -= 1
            if next < 0:
                print("No")
                return
            spawned[next] = True
            activated.append(S[next])
        active.extend(activated)
    print("Yes")

if __name__ == '__main__':
    main()

