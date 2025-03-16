import sys

def read_int():
    return int(sys.stdin.readline().strip())

def read_float():
    return float(sys.stdin.readline().strip())

def read_string():
    return sys.stdin.readline().strip()

def main():
    n, m = read_int(), read_int()
    a = []
    total_sum = 0
    
    for _ in range(m):
        value = read_int()
        a.append(value)
        total_sum += value
    
    if total_sum > n:
        print("-1")
        return
    
    print(n - total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
