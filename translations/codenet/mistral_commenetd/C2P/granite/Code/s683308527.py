

n = int(input())

while n > 0:
  s = input()
  while "Hoshino" in s:
    s = s.replace("Hoshino", "aana", 1)
  print(s)
  n -= 1

