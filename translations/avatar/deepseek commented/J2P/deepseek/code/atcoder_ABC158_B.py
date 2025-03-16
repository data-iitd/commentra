import sys

def main():
    n = int(sys.stdin.readline().strip())
    a = int(sys.stdin.readline().strip())
    b = int(sys.stdin.readline().strip())
    
    # Check if the values of N, A, and B are within the specified ranges
    if 1 <= n <= 10**18 and 0 <= a <= 10**18 and 0 <= b <= 10**18 and 0 < a + b <= 10**18:
        # Calculate the number of complete cycles (k) of A and B that fit into N
        k = n // (a + b)
        if n - k * (a + b) > a:
            print(a * k + (n - k * (a + b)) - (n - (k * (a + b) + a)))
        else:
            print(a * k + (n - k * (a + b)))

if __name__ == "__main__":
    main()

