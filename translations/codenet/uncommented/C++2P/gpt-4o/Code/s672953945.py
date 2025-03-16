# Python translation of the given C++ code

N, L = map(int, input().split())
v = []

for _ in range(N):
    s = input()
    v.append(s)

v.sort()

for string in v:
    print(string, end='')

print()  # To add a newline at the end

# <END-OF-CODE>
