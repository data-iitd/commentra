def abs_value(x):
    if x < 0:
        return -x
    return x

def min_value(a, b):
    if a > b:
        return b
    return a

def main():
    N, K = map(int, input().split())
    
    x = N % K
    x = min_value(abs_value(x - K), x)
    print(x)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
