n = int(input())
for i in range(1, n + 1):
    a = i
    if a % 3 == 0:
        print(i, end=' ')
    else:
        while a:
            if a % 10 == 3:
                print(i, end=' ')
                a = 0
            a //= 10
print()  # To print a newline at the end
# <END-OF-CODE>
