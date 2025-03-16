import sys

def main():
    inp = sys.stdin.readline
    N = int(inp())
    A = list(map(int, inp().split()))
    A.sort()
    min_val = A[0]
    max_val = A[-1]
    min_count = A.count(min_val)
    max_count = A.count(max_val)
    
    if min_val == max_val:
        print(f"{max_val - min_val} {min_count * (min_count - 1) // 2}")
    else:
        print(f"{max_val - min_val} {min_count * max_count}")

if __name__ == "__main__":
    main()
