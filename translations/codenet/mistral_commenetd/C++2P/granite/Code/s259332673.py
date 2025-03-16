
h1, m1 = map(int, input("Enter hours and minutes for the first time: ").split())
h2, m2 = map(int, input("Enter hours and minutes for the second time: ").split())
k = int(input("Enter the difference in minutes: "))

ans = h2 * 60 + m2
print("The total minutes of the second time are:", ans)

ans -= (h1 * 60 + m1)
print("The difference in minutes is:", ans)

ans -= k
print("The difference in minutes after subtracting", k, "is:", ans)

hours = ans // 60
minutes = ans % 60

print(hours, "hours and", minutes, "minutes")

