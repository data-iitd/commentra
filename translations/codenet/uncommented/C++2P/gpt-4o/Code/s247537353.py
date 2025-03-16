def main():
    A, B, C, K = map(int, input().split())
    
    if A + B >= K:
        print(min(A, K))
    else:
        print(A - (K - (A + B)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
