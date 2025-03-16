
import math

n, m = map(int, input().split())
x = m*1900 + (n-m)*100
print(x * int(math.pow(2.0, m)))

