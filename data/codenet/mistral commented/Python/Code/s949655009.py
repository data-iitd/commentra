
strn = input("Take a string as input from the user.")
n = int(strn)
"Convert the string to an integer."

shichigolist = ["3","5","7"]
"Create a list of digits that we want to check for in the string."

shichigo = [[] for _ in range(len(strn))]
"Create an empty list for each index in the string."

for i in range(len(strn)):
	if i == 0:
		for j in shichigolist:
			shichigo[i].append(j)
			"Add all digits from shichigolist to the first index of shichigo."
	else:
		for j in shichigo[i-1]:
			for k in shichigolist:
				shichigo[i].append(j+k)
				"Add all possible combinations of the last digit and the digits from shichigolist to the current index of shichigo."

target = len(strn)-1
"Set the last index of the string as the target."

for i in range(len(strn)):
	for j in shichigo[i][:]:
		if i == target:
			if int(j) > n:
				shichigo[target].remove(j)
				"If the integer value of the string is greater than the given number, remove it from the target index."
			elif j.count("3")==0 or j.count("5")==0 or j.count("7")==0:
				shichigo[target].remove(j)
				"If the string does not contain the required digits, remove it from the target index."
		else:
			if j.count("3")==0 or j.count("5")==0 or j.count("7")==0:
				shichigo[i].remove(j)
				"If the string does not contain the required digits at the current index, remove it."

print(sum([len(shichigo[i]) for i in range(len(strn))]))
"Print the total number of strings in the shichigo list."