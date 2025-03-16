
# Read input until a negative number is encountered
while(True):
	n = int(raw_input())
	if ~n:
		# Initialize segment states to 0
		st = [0] * 7

		# Process each digit input
		for i in range(n):
			t = int(raw_input())

			# Determine the segment states based on the input digit
			ans = ['0'] * 8
			for i in range(7):
				# Calculate the current segment state and store it in ans
				ans[i] = str(st[i] ^ seg[t][i])
				st[i] = seg[t][i]

			# Output the segment states for the current digit
			print ''.join(ans)
	else:
		break

