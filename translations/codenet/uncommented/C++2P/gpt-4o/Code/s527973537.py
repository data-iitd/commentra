N = input()
S = sum(int(digit) for digit in N)
if int(N) % S == 0:
    print("Yes")
else:
    print("No")
# <END-OF-CODE>
