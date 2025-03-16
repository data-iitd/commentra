s = input()

for i in range(ord('a'), ord('z') + 1):
    a = 0
    for j in s:
        if chr(i) == j:
            a += 1
    if a == 0:
        print(chr(i))
        break
    if i == ord('z'):
        print("None")
        break
