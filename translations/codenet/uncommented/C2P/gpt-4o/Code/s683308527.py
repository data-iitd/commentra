n = int(input())
for _ in range(n):
    s = input()
    while "Hoshino" in s:
        index = s.index("Hoshino") + 6
        s = s[:index] + 'a' + s[index + 1:]
    print(s)
# <END-OF-CODE>
