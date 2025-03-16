s = input()
s = s.replace("dream", "D")
s = s.replace("erase", "E")
s = s.replace("Der", "")
s = s.replace("Er", "")
s = s.replace("D", "")
s = s.replace("E", "")
s = s.strip()

if s == "":
    print("YES")
else:
    print("NO")

