str_input = input()

max_count = 0
cnt = 0
for sc in str_input:
    if sc in 'ACGT':
        cnt += 1
    else:
        cnt = 0
    max_count = max(max_count, cnt)

print(max_count)

# <END-OF-CODE>
