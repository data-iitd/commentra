s = input()
for i in range(97,123):
	a = 0
	for j in s:
		if chr(i)==j:
			a+=1
	if a==0:
		print(chr(i))
		break
if i==122:
	print("None")

