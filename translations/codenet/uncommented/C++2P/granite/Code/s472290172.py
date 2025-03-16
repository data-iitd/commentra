
str = input()

max = 0
cnt = 0
for sc in str:
    if sc in ['A', 'C', 'G', 'T']:
        cnt += 1
    else:
        cnt = 0
    max = max if max > cnt else cnt

print(max)
