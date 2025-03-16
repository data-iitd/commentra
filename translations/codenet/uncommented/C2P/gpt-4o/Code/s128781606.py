A, B = map(int, input().split())
C = A + B
D = A - B
E = A * B
max_value = C
if max_value < D:
    max_value = D
if max_value < E:
    max_value = E
print(max_value)
# <END-OF-CODE>
