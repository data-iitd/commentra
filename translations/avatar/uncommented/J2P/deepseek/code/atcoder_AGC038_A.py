import sys

def main():
    H = int(input().strip())
    W = int(input().strip())
    A = int(input().strip())
    B = int(input().strip())
    
    if W < 2 * A or H < 2 * B:
        print(-1)
        return
    
    for i in range(H):
        for j in range(W):
            if (i < B and j < A) or (i >= B and j >= A):
                sys.stdout.write('0')
            else:
                sys.stdout.write('1')
        print()

if __name__ == "__main__":
    main()
