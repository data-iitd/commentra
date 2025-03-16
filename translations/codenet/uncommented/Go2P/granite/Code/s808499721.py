
x = int(input())

ans = 0
if x >= 400 and x <= 599:
    ans = 8
if x >= 600 and x <= 799:
    ans = 7
if x >= 800 and x <= 999:
    ans = 6
if x >= 1000 and x <= 1199:
    ans = 5
if x >= 1200 and x <= 1399:
    ans = 4
if x >= 1400 and x <= 1599:
    ans = 3
if x >= 1600 and x <= 1799:
    ans = 2
if x >= 1800 and x <= 9999:
    ans = 1

print(ans)
