
# ACM-ICPCアジア地区予選2014 B. Miscalculation

def mul(str, idx):
    res = int(str[idx])
    while idx+1 < len(str) and str[idx+1]=='*':
        idx += 2
        res *= int(str[idx])
    return res

def add(str, idx):
    res = mul(str, idx)
    while idx+1 < len(str) and str[idx+1] == '+':
        idx += 2
        res += mul(str, idx)
    return res

def bob(str, idx):
    res = int(str[idx])
    while idx+1 < len(str):
        if str[idx+1] == '+':
            res += int(str[idx+2])
        else:
            res *= int(str[idx+2])
        idx += 2
    return res

while True:
    try:
        s, d = input().split()
        idx = 0
        a = add(s, idx)  # Calculate the result using the add function
        idx = 0
        b = bob(s, idx)  # Calculate the result using the bob function
        if a == int(d):
            print("U" if b == int(d) else "M")  # Output based on both results
        else:
            print("L" if b == int(d) else "I")  # Output based on both results
    except:
        break

