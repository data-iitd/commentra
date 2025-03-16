import sys

# Step 1: Define the Not function
def Not(x):
    return 2 - x

# Step 2: Define the And function
def And(x, y):
    if x * y == 0:
        return 0
    if x == 2 and y == 2:
        return 2
    return 1

# Step 3: Define the Or function
def Or(x, y):
    if x == 2 or y == 2:
        return 2
    if x == 1 or y == 1:
        return 1
    return 0

# Step 4: Implement the parse function
def parse(ss, it):
    c = ss[it]
    it += 1
    if '0' <= c and c <= '2':
        return ord(c) - ord('0')
    if c == '-':
        return Not(parse(ss, it))

    x = parse(ss, it)
    c = ss[it]
    y = parse(ss, it)
    it += 1
    return And(x, y) if c == '*' else Or(x, y)

# Step 5: Implement the main function
def main():
    while True:
        input_line = sys.stdin.readline().strip()
        if input_line == ".":
            break
        a = [0, 1, 2]
        cnt = 0
        for i in a:
            for j in a:
                for k in a:
                    ss = input_line
                    ss = ss.replace('P', str(i))
                    ss = ss.replace('Q', str(j))
                    ss = ss.replace('R', str(k))
                    it = 0
                    if parse(ss, it) == 2:
                        cnt += 1
        print(cnt)

# Step 6: Output the count
main()
