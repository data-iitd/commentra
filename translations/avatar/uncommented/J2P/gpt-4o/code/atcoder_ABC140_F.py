import sys

def main():
    N = int(input())
    size = 1 << N
    S = [int(input()) for _ in range(size)]
    S.sort()
    spawned = [False] * size
    spawned[size - 1] = True
    active = [S[size - 1]]

    for i in range(N):
        active.sort(reverse=True)
        activated = []
        next_index = size - 1
        
        for slime in active:
            while next_index >= 0 and (S[next_index] >= slime or spawned[next_index]):
                next_index -= 1
            if next_index < 0:
                print("No")
                return
            spawned[next_index] = True
            activated.append(S[next_index])
        
        active.extend(activated)

    print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
