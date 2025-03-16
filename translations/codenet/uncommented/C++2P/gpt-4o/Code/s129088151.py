n = int(input())
T = {}

for _ in range(n):
    com, str_value = input().split()
    if com[0] == 'i':
        T[str_value] = True
    else:
        if str_value in T and T[str_value]:
            print("yes")
        else:
            print("no")

# <END-OF-CODE>
