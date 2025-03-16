import sys

def main():
    N = int(input().strip())
    v = [0] * N

    for _ in range(1, N):
        a = int(input().strip())
        v[a - 1] += 1

    for e in v:
        print(e)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
