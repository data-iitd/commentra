in_time = int(input())

h = in_time // 3600
in_time %= 3600

m = in_time // 60
in_time %= 60

s = in_time

print(f"{h}:{m}:{s}")
# <END-OF-CODE>
