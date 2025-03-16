
N = input()
S = sum(int(n) for n in N)
if int(N) % S == 0:
    print("Yes")
else:
    print("No")
