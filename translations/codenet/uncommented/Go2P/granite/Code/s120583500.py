
s = input()

count = 0
counter = [0]

if s == "":
    exit()

for c in s:
    if c in "ACGT":
        count += 1
    else:
        counter.append(count)
        count = 0

counter.append(count)
counter.sort()
print(counter[-1])
