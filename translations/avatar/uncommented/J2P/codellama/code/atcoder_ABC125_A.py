import sys

sc = sys.stdin
sec = int(sc.readline())
per_num = int(sc.readline())
max_sec = float(sc.readline()) + 0.5
ans_num = 0

for i in range(sec, max_sec, sec):
    ans_num += per_num

print(ans_num)

