
source = input()

if len(source) > 10 or len(source) < 1:
    exit(-1)

max_i = 2 ** (len(source) - 1)

sum = 0

for i in range(max_i):
    plus = bin(i)[2:].zfill(len(source) - 1)

    number = 0
    working = source

    for j in range(len(plus)):
        if plus[j] == '1':
            sum += float(working[:j + 1])
            working = working[j + 1:]

    sum += float(working)

print(int(sum))

