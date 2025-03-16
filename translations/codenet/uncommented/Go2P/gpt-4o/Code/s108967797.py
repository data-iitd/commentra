import sys

def ri():
    return int(sys.stdin.readline().strip())

def ave(s):
    return sum(s) / len(s)

def diff(a, b):
    return abs(a - b)

def main():
    n = ri()
    a = [float(ri()) for _ in range(n)]
    
    average = ave(a)

    min_diff = float('inf')
    ans_index = -1
    for i, v in enumerate(a):
        d = diff(v, average)
        if d < min_diff:
            min_diff = d
            ans_index = i
            
    print(ans_index)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
