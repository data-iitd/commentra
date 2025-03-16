
in = int(input())

h = in // 3600
in %= 3600

m = in // 60
in %= 60

s = in

print(f"{h}:{m}:{s}")

#