
def solution(n, m):
    n = n - 2
    m = m - 2
    if n < 0:
        n = 1
    if m < 0:
        m = 1
    return n * m

def main():
    n, m = map(int, input().split())
    print(solution(n, m))

