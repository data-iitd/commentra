
# solution function takes an integer n and a list a as input.
# It initializes a memoization array memo with a size of 1e5 + 2.
# It iterates over the elements of a, incrementing the counts in memo for each element and its neighbors.
# It then iterates over the memo array to find the maximum count, which represents the most frequent element or its neighbors.
# The max function is a helper function to find the maximum of two integers.
# The main function reads the input values, calls the solution function, and prints the result.
def solution(n, a):
    memo = [0] * (1e5 + 2)
    for num in a:
        memo[num] += 1
        memo[num + 1] += 1
        memo[num + 2] += 1
    out = 0
    for num in memo:
        if num > 0:
            out = max(out, num)
    return out

# max function returns the maximum of two integers.
def max(x, y):
    if x > y:
        return x
    return y

# main function reads the input values, calls the solution function, and prints the result.
def main():
    n = int(input())
    a = list(map(int, input().split()))
    print(solution(n, a))

