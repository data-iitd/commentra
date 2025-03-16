S = input()
for i in range(len(S)):
    if S[i] == 'A' and i + 1 < len(S) and S[i + 1] == 'C':
        print("Yes")
        break
else:
    print("No")
# <END-OF-CODE>
