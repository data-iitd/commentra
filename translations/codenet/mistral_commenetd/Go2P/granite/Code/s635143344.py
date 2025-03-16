

in = []
for _ in range(3):
    in.append(int(input()))
in.sort()
print(in[2] * 10 + in[1] + in[0])
