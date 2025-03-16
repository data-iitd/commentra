
str = raw_input()
p = raw_input()

str = str + str

flag = 0
for i in range(len(str) - len(p)):
	if str[i:i+len(p)] == p:
		flag = 1

if flag:
	print "Yes"
else:
	print "No"

#