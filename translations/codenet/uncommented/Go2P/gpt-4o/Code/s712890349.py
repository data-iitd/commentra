def run_length(s):
    r = []
    if len(s) == 0:
        return r
    t = (s[0], 1)
    for v in s[1:]:
        if t[0] == v:
            t = (t[0], t[1] + 1)
        else:
            r.append(t)
            t = (v, 1)
    r.append(t)
    return r

def max_value(a, b):
    return b if b > a else a

def main():
    N, K = map(int, input().split())
    S = input().strip()
    blocks = run_length(S)
    sum_len, zero, l = 0, 0, 0
    ans = 0
    
    for r in range(len(blocks)):
        sum_len += blocks[r][1]
        if blocks[r][0] == "0":
            zero += 1
        while zero > K:
            sum_len -= blocks[l][1]
            if blocks[l][0] == "0":
                zero -= 1
            l += 1
        ans = max_value(ans, sum_len)
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
