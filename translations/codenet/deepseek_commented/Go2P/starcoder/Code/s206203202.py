
def min(a, b):
    if a > b:
        return b
    return a

def abs(x):
    if x < 0:
        return -x
    return x

def main():
    N, K = map(int, input().split())
    x = N % K
    x = min(abs(x-K), x)
    print(x)

main()

