MAX_V = 999999
prime = [1] * (MAX_V + 1)

for i in range(2, MAX_V + 1):
    prime[i] = 1

for i in range(2, int(MAX_V**0.5) + 1):
    if prime[i]:
        for k in range(2 * i, MAX_V + 1, i):
            prime[k] = 0

prime[0] = 0
prime[1] = 0
count = 0

try:
    while True:
        n = int(input())
        count += 1
        cnt = 0
        for i in range(n, 0, -1):
            if prime[i] == 1:
                cnt += 1
        print(cnt)
        if count == 30:
            break
except EOFError:
    pass

# <END-OF-CODE>
