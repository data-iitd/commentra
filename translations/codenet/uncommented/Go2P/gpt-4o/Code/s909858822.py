A, B = map(int, input().split())

if 6 <= A <= 12:
    ans = B // 2
elif A > 12:
    ans = B
else:
    ans = 0  # Assuming we want to handle cases where A < 6

print(ans)
# <END-OF-CODE>
