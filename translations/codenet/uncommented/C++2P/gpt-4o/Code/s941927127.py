W = input().strip()

W = sorted(W)

for i in range(0, len(W), 2):
    if i + 1 >= len(W) or W[i] != W[i + 1]:
        print("No")
        break
else:
    print("Yes")

# <END-OF-CODE>
