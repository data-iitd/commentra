
#<START-OF-CODE>

while True:
	n=int(raw_input())
	if not n:break
	st=[0]*7
	for i in xrange(n):
		t=int(raw_input())
		ans=[0]*8
		for i in xrange(7):
			ans[i]=st[i]^seg[t][i]
			st[i]=seg[t][i]
		print ''.join(map(str,ans))

#