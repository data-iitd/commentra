# Python3 program to find nCk % MOD

# Returns value of Binomial Coefficient C(n, k)
def binomialCoeff(n, k):
    # since C(n, k) = C(n, n - k)
    if (k > n - k):
        k = n - k

    # initialize result
    res = 1

    # Calculate value of
    # [n * (n-1) *---* (n-k + 1)] / [k * (k-1) *----* 1]
    for i in range(k):
        res = res * (n - i)
        res = res // (i + 1)

    return res

# Driver Code
if __name__ == '__main__':
    n = 10
    k = 2
    print(binomialCoeff(n, k))

