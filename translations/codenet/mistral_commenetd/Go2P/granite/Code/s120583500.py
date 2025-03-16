

s = input()

count = 0
counter = []

if s == "":
    exit()

counter.append(0)

li = list(s)

for s in li:
    if s == "A" or s == "C" or s == "G" or s == "T":
        count += 1
    else:
        counter.append(count)
        count = 0

counter.append(count)

counter.sort()

print(counter[-1])

