
s = input()
ans = "No"
if s.find("C") < s.rfind("F"):
  ans = "Yes"
if s.find("C") < 0:
  ans = "No"
print(ans)
