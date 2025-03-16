
n, a, b = map(int, input().split())
# The first line of the code takes three inputs from the user: `n`, `a`, and `b`. These inputs represent some quantities.

ans = n // (a + b) * a
# The second line calculates the initial number of full cycles of `a` that fit into `n` by dividing `n` by `(a+b)`. It multiplies the result by `a` to get the total number of `a` units.

r = min(n % (a + b), a)
# The third line calculates the remainder of `n` divided by `(a+b)` and finds the minimum of this remainder and `a`. This represents the number of additional `a` units needed if the remainder is less than `a`.

ans += r
# The fourth line adds the result from the third line to the result from the second line to get the final answer.

print(ans)
# The fifth line prints the final answer.

