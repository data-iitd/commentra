def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    idorder = {}
    
    for i in range(1, N + 1):
        A = int(data[i])
        idorder[A] = i
    
    for i in range(1, N + 1):
        print(idorder[i], end=" ")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
