
s = input()

ans = "No"

if s.index("C") < s.rindex("F"):
    ans = "Yes"

if s.index("C") < 0:
    ans = "No"

print(ans)

