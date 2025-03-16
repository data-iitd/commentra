n = int(input())
s = input()

max_count = 0
cnt = 0
for r in s:
    if r == 'I':
        cnt += 1
    else:
        cnt -= 1

    if cnt > max_count:
        max_count = cnt

print(max_count)

# <END-OF-CODE>
