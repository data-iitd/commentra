train = list(map(int, input().split()))
bus = list(map(int, input().split()))

result = (min(train[0], train[1]) + min(bus[0], bus[1]))
print(result)

# <END-OF-CODE>
