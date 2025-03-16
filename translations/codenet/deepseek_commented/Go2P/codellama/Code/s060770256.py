
# solution function takes two integers, n and m, as input.
# It adjusts both n and m by subtracting 2 from each.
# It then checks if the adjusted values are less than 0, and if so, it sets them to 1.
# Finally, it returns the product of the adjusted n and m.
def solution(n, m):
    n = n - 2
    m = m - 2
    if n < 0:
        n = 1
    if m < 0:
        m = 1
    return n * m

# main function takes two integers, n and m, as input.
# It then calls the solution function with n and m as input.
# Finally, it prints the result of the solution function.
def main():
    n = int(input())
    m = int(input())
    print(solution(n, m))

# call main function
main()

