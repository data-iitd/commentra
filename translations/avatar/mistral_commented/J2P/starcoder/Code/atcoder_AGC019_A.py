import sys

# <START-OF-CODE>

def main():
    input = sys.stdin.read().splitlines()
    Q = int(input[0])
    H = int(input[1])
    S = int(input[2])
    D = int(input[3])
    N = int(input[4])

    onePrice = min(min(Q*4, H*2), S)

    if onePrice <= D/2:
        print(N*onePrice)
    else:
        print((N/2)*D + (N%2)*onePrice)

if __name__ == '__main__':
    main()

# 