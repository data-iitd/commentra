#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#ifdef __cplusplus
#include <bits/stdc++.h>
#endif

def nextint():
	c=getchar_unlocked()
	while c!='-' and (c<'0' or '9'<c):
		c=getchar_unlocked()
	s=False
	if c=='-':
		s=True
		c=getchar_unlocked()
	x=0
	while '0'<=c and c<='9':
		x=x*10+c-'0'
		c=getchar_unlocked()
	return -x if s else x

n=nextint()

def p(a, b):
	if a<b:
		return a+b*n
	else:
		return b+a*n

a=[[0]*(n-1) for i in range(n)]

e1=[0]*1000000
e2=[0]*1000000
d=[0]*1000000
b=[False]*1000000

def f(from):
	if b[from]:
		return -1
	if d[from]:
		return d[from]
	b[from]=True
	to=e1[from]
	max=0
	if to!=0:
		now=f(to)
		if now<0:
			return now
		if now>max:
			max=now
	to=e2[from]
	if to!=0:
		now=f(to)
		if now<0:
			return now
		if now>max:
			max=now
	b[from]=False
	return d[from]=max+1

ans=0
for i in range(n):
	from=p(i, a[i][0])
	now=f(from)
	if now<0:
		ans=-1
		break
	if now>ans:
		ans=now
print(ans)

