
source = ""

try:
	source = raw_input()
except:
	pass

if len(source) > 10 or len(source) < 1:
	print -1
	exit()

max_i = 2 ** (len(source) - 1)

sum = 0

for i in range(max_i):
	plus = bitset(i)
	number = 0
	working = source
	while plus.any():
		i = 0
		while not plus[i]:
			i += 1
		sum += float(working[:i + 1])
		plus >>= i + 1
		working = working[i + 1:]
	sum += float(working)

print round(sum, 0)

#