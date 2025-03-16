
s = input()
for i in range(97,123):
	a = 0
	for j in range(len(s)):
		if chr(i)==s[j]:
			a+=1
	if a==0:
		print(chr(i))
		break
if i==122:
	print("None")

