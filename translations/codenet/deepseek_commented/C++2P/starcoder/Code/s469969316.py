# Step 1: Define the Not function
def Not(x):
    return 2-x

# Step 2: Define the And function
def And(x, y):
    if x*y == 0: return 0
    if x == 2 and y == 2: return 2
    return 1

# Step 3: Define the Or function
def Or(x, y):
    if x == 2 or y == 2: return 2
    if x == 1 or y == 1: return 1
    return 0

# Step 4: Implement the parse function
def parse():
    c = ss[it]
    if '0' <= c and c <= '2': return ord(c)-ord('0')
    if c == '-': return Not(parse())

    x = parse()
    c = ss[it+1]
    y = parse()
    it += 2
    return c == '*' and And(x, y) or Or(x, y)

# Step 5: Implement the main function
while True:
    input = raw_input()
    if input == '.': break
    cnt = 0
    for i in range(3):
        for j in range(3):
            for k in range(3):
                a = [i, j, k]
                ss = input
                for c in ss:
                    if c == 'P': c = a[0]+'0'
                    if c == 'Q': c = a[1]+'0'
                    if c == 'R': c = a[2]+'0'
                it = 0
                if parse() == 2: cnt += 1
    print cnt

# Step 6: Output the count

