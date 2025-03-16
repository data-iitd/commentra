
io = [int(x) for x in raw_input().split()]
for i in range(5):
    max = io[i]
    max_j = i
    for j in range(i+1,5):
        if max < io[j]:
            max = io[j]
            max_j = j
    buf = io[i]
    io[i] = io[max_j]
    io[max_j] = buf
    if i < 4:
        print io[i],
    else:
        print io[i]

