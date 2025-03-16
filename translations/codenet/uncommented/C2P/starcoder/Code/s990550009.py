n = int(input())
a = [int(x) for x in input().split()]
cnt = 1
isup = a[0] < a[1]
issame = a[0] == a[1]
for i in range(1, n - 1):
	if issame:
		if a[i]!= a[i + 1]:
			issame = False
			if a[i] < a[i + 1]:
				isup = True
			else:
				isup = False
	else:
		if isup and a[i] <= a[i + 1]:
			;
		elif not isup and a[i] >= a[i + 1]:
			;
		else:
			if i + 2 < n:
				if a[i + 1] < a[i + 2]:
					isup = True
				elif a[i + 1] > a[i + 2]:
					isup = False
				else:
					issame = True
				cnt += 1
			else:
				cnt += 1
				break
print(cnt)
#