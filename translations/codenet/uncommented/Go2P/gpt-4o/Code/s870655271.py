def main():
    N, M = map(int, input().split())
    ans = 0
    
    if N == 1 and M == 1:
        ans += 1
    elif N > 1 and M > 1:
        ans += (N - 2) * (M - 2)
    else:
        ans += (N * M) - 2

    print(ans)

def max_value(*args):
    return max(args)

def min_value(*args):
    return min(args)

def pow_value(x, y):
    return x ** y

def abs_value(x):
    return abs(x)

def floor_value(x):
    return int(x // 1)

class SortBy:
    def __init__(self, data):
        self.data = data

    def __len__(self):
        return len(self.data)

    def swap(self, i, j):
        self.data[i], self.data[j] = self.data[j], self.data[i]

    def less(self, i, j):
        return abs_value(self.data[i]) < abs_value(self.data[j])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
