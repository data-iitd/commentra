

s = input()
s = s.replace("dream", "D")
s = s.replace("erase", "E")
s = s.replace("Der", "")
s = s.replace("Er", "")
s = s.strip()
if s == "":
    print("YES")
else:
    print("NO")

