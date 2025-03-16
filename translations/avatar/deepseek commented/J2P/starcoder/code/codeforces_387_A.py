
import datetime

x = datetime.time(int(input().split(':')[0]), int(input().split(':')[1]))
y = datetime.time(int(input().split(':')[0]), int(input().split(':')[1]))

print(x - y)

