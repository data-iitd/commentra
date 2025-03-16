import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    H = int(data[0])
    W = int(data[1])
    A = int(data[2])
    B = int(data[3])
    
    if W < 2 * A or H < 2 * B:
        print(-1)
        return
    
    for i in range(H):
        for j in range(W):
            if (i < B and j < A) or (i >= B and j >= A):
                print("0", end="")
            else:
                print("1", end="")
        print()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
