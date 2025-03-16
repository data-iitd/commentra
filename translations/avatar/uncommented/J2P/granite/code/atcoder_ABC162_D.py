
n = int(input())
s = input()
rc = 0
gc = 0
bc = 0
for i in range(n):
    if s[i] == 'R':
        rc += 1
    elif s[i] == 'G':
        gc += 1
    else:
        bc += 1
result = rc * gc * bc
for i in range(1, n + 1):
    for k in range(i + 1, n + 1):
        if (i + k) % 2 == 0:
            is_ = s[i - 1]
            ks_ = s[k - 1]
            js_ = s[((i + k) // 2) - 1]
            if is_!= ks_ and ks_!= js_ and js_!= is_:
                result -= 1
print(result)

