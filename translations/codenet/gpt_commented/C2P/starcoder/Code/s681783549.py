# <START-OF-CODE>

S = input()

for i in range(len(S)):
    if S[i] == 'A' and S[i + 1] == 'C':
        print("Yes")
        break
else:
    print("No")

# 