s = input()

if s.find("C") < s.rfind("F"):
    print("Yes")
elif s.find("C") < 0:
    print("No")
else:
    print("No")

