def mul(s, idx):
    res = int(s[idx])
    while idx + 1 < len(s) and s[idx + 1] == '*':
        idx += 2
        res *= int(s[idx])
    return res

def add(s, idx):
    res = mul(s, idx)
    while idx + 1 < len(s) and s[idx + 1] == '+':
        idx += 2
        res += mul(s, idx)
    return res

def bob(s, idx):
    res = int(s[idx])
    while idx + 1 < len(s):
        if s[idx + 1] == '+':
            res += int(s[idx + 2])
        else:
            res *= int(s[idx + 2])
        idx += 2
    return res

if __name__ == "__main__":
    while True:
        try:
            s, d = input().split()
            d = int(d)
            idx = 0
            a = add(s, idx)  # Calculate the result using the add function
            idx = 0
            b = bob(s, idx)  # Calculate the result using the bob function
            if a == d:
                print("U" if b == d else "M")  # Output based on both results
            else:
                print("L" if b == d else "I")  # Output based on both results
        except EOFError:
            break  # Exit the loop on end of input
# <END-OF-CODE>
