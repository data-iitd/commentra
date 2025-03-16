MAX_V = 999999
prime = [1] * (MAX_V + 1)

def sieve():
    prime[0] = 0
    prime[1] = 0
    for i in range(2, int(MAX_V**0.5) + 1):
        if prime[i]:
            for k in range(2 * i, MAX_V + 1, i):
                prime[k] = 0

sieve()

count = 0
while True:
    try:
        n = int(input())
        count += 1
        cnt = 0
        for i in range(n, 0, -1):
            if prime[i]:
                cnt += 1
        print(cnt)
        if count == 30:
            break
    except EOFError:
        break
