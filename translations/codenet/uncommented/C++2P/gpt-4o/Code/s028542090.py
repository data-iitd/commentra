a = [0] * 100100

k = int(input())

for i in range(k):
    a[i] = int(input())

max_val = 3
min_val = 2

if a[k - 1] != 2:
    print(-1)
else:
    for i in range(k - 2, -1, -1):
        if a[i] > max_val:
            print(-1)
            break
        else:
            max_val = ((max_val // a[i]) + 1) * a[i] - 1
            if min_val % a[i] != 0:
                min_val = ((min_val // a[i]) + 1) * a[i]

        if max_val <= min_val:
            print(-1)
            break
    else:
        print(min_val, max_val)

# <END-OF-CODE>
