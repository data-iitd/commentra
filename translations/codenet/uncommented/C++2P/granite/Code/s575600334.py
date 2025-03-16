
a,b = map(int, input().split())

def binPrint(x, bits):
  for i in range(bits-1, -1, -1):
    print(1 if x&(1<<i) else 0, end='')
  print()

binPrint(a&b, 32)
binPrint(a|b, 32)
binPrint(a^b, 32)

