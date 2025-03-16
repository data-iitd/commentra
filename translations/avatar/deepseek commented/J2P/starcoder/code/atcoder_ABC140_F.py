import sys

def main():
    N = int(sys.stdin.readline())
    S = [int(sys.stdin.readline()) for _ in range(1 << N)]
    S.sort()
    active = [S[-1]]
    spawned = [False] * (1 << N)
    spawned[-1] = True

    for _ in range(N):
        active.sort(reverse=True)
        activated = []
        next = (1 << N) - 1

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

if __name__ == "__main__":
    main()

