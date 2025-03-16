N, D, X = map(int, input().split())
A = list(map(int, input().split()))

num_of_chocolate = 0

for i in range(N):
    days = 0
    counter = 0
    j = 0
    while True:
        days = j * A[i] + 1
        if days <= D:
            counter += 1
        else:
            break
        j += 1
    num_of_chocolate += counter

num_of_chocolate += X

print(num_of_chocolate)

# <END-OF-CODE>
