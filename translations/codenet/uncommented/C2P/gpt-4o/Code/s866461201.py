n = int(input())
fd = [0] * 6

for _ in range(n):
    height = float(input())
    if height >= 185.0:
        fd[5] += 1
    elif height >= 180.0:
        fd[4] += 1
    elif height >= 175.0:
        fd[3] += 1
    elif height >= 170.0:
        fd[2] += 1
    elif height >= 165.0:
        fd[1] += 1
    else:
        fd[0] += 1

for i in range(6):
    print(f"{i + 1}:", '*' * fd[i])

# <END-OF-CODE>
