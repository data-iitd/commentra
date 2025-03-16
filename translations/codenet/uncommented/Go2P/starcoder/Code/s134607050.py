def search_range(text, start, limit):
	middle = -1

	for i in range(start, limit):
		if text[i]!= 'R':
			middle = i
			break

	end = limit

	for i in range(middle, limit):
		if text[i]!= 'L':
			end = i
			break

	return start, middle, end

def answer():
	text = raw_input()
	limit = len(text)

	start = 0
	middle = 0
	end = 0
	first_printed = False

	for end < limit:
		start, middle, end = search_range(text, start, limit)
		len1 = middle - start
		len2 = end - middle

		for i in range(start, middle-1):
			if first_printed:
				print " ",
			print "0",
			first_printed = True

		count1 = (len1+1)/2 + len2/2
		count2 = len1/2 + (len2+1)/2

		if first_printed:
			print " ",
		print count1, count2,
		first_printed = True

		for i in range(middle + 1, end):
			if first_printed:
				print " ",
			print "0",
			first_printed = True
		start = end
		first_printed = True
	print

answer()
# 