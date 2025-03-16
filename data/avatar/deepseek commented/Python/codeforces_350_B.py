
n = int(input())  # Taking an integer input `n` which represents the number of elements.
t = [0] + list(map(int, input().split()))  # Taking a list of integers `t` as input.
a = [0] + list(map(int, input().split()))  # Taking another list of integers `a` as input.
ans, cnt = [], [0 for i in range(n + 1)]  # Initializing an empty list `ans` and a list `cnt` with zeros.

# Counting the occurrences of each element in `a` and storing them in `cnt`.
for i in a:
    cnt[i] += 1

# Iterating over the range from 1 to `n` to find cycles starting from each element.
for i in range(1, n + 1):
    if t[i] == 1:  # Checking if `t[i]` is 1, indicating the start of a potential cycle.
        crt = [i]  # Starting a list `crt` with `i`.
        x = a[i]  # Initializing `x` with the value at index `i` in `a`.
        # Finding the cycle by following the `a` list until reaching an element whose count is not 1.
        while cnt[x] == 1:
            crt.append(x)
            x = a[x]
        # Updating `ans` if the length of `crt` is greater than the length of `ans`.
        if len(crt) > len(ans):
            ans = crt[:]

# Reversing `ans` to get the correct order of elements in the cycle.
ans.reverse()

# Printing the length of `ans` and the elements of `ans`.
print(len(ans))
print(' '.join(map(str, ans)))
