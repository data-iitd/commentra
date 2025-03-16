
x = []
i = 0
while True:
    num = input()
    if num == 0:
        break
    x.append(num)

for j, num in enumerate(x):
    print(f"Case {j+1}: {num}")

