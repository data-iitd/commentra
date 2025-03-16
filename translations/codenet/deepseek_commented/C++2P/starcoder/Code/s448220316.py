n,m=map(int,input().split())
# Read the number of nodes and operations.
fa=[i for i in range(n+1)]
# Initialize the union-find structure with each node as its own parent.
v=[0 for i in range(n+1)]
# Initialize the value array with each node as 0.
for i in range(m):
	l,r,vi=map(int,input().split())
	# Read the left node, right node, and value increment for each operation.
	li=get(l)
	# Find the root of l.
	ri=get(r)
	# Find the root of r.
	if li!=ri:
		v[ri]=vi-v[r]+v[l]
		# Update the value of ri based on the values of l and r.
		fa[ri]=li
		# Set the parent of ri to li.
	else:
		if v[r]-v[l]!=vi:
			print("No")
			# If the values are inconsistent, print "No" and exit.
print("Yes")
# If all operations are consistent, print "Yes".

