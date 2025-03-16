
n = int(input())
as_ = [int(input()) for _ in range(n+1)]
bs_ = [int(input()) for _ in range(n)]

sum_ = 0
for i in range(n):
    a = as_[i]
    b = bs_[i]
    if a <= b:
        sum_ += a
        b -= a
        if i+1 < n:
            an = as_[i+1]
            if an <= b:
                sum_ += an
                as_[i+1] = 0
            else:
                sum_ += b
                as_[i+1] -= b
    else:
        sum_ += b

print(sum_)
