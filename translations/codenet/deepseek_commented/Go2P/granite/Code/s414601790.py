
n, s = map(int, input().split())
max_cnt = 0
cnt = 0
for r in s:
    if r == 'I':
        cnt += 1
    else:
        cnt -= 1
    if cnt > max_cnt:
        max_cnt = cnt
print(max_cnt)
