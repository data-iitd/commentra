
# <START-OF-CODE>

while True:
    try:
        s = raw_input()
        if s == "0":
            break
        sum = 0
        for i in range(len(s)):
            sum += int(s[i])
        print sum
    except EOFError:
        break

# 