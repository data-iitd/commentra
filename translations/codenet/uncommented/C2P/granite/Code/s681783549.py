
S = input()
for i in range(len(S)):
    if S[i] == 'A' and S[i + 1] == 'C':
        print("Yes")
        exit(0)
print("No")
