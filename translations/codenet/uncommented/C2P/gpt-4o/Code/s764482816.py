io = list(map(int, input().split()))
for i in range(5):
    max_value = io[i]
    max_j = i
    for j in range(i + 1, 5):
        if max_value < io[j]:
            max_value = io[j]
            max_j = j
    # Swap the elements
    buf = io[i]
    io[i] = io[max_j]
    io[max_j] = buf
    print(io[i], end=' ' if i < 4 else '\n')

# <END-OF-CODE>
