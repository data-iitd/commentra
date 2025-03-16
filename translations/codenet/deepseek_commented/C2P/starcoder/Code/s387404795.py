#include <stdio.h>
#include <string.h>

def main():
	str = raw_input()
	p = raw_input()
	tmp = str + str
	str = str + tmp
	slen = len(str)
	plen = len(p)
	flag = 0
	for i in range(0, slen - plen):
		if str[i:i+plen] == p:
			flag = 1
	if flag:
		print "Yes"
	else:
		print "No"

main()

