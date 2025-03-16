n = int(input())

ac_count = 0
wa_count = 0
tle_count = 0
re_count = 0

for _ in range(n):
    s = input()
    if s == "AC":
        ac_count += 1
    elif s == "WA":
        wa_count += 1
    elif s == "TLE":
        tle_count += 1
    elif s == "RE":
        re_count += 1

print(f"AC x {ac_count}")
print(f"WA x {wa_count}")
print(f"TLE x {tle_count}")
print(f"RE x {re_count}")

# <END-OF-CODE>
