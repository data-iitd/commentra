
# Including necessary header files
from sys import stdin,stdout
from collections import defaultdict
from bisect import bisect_left,bisect_right
from math import *
from itertools import *
from functools import *
from operator import *
from heapq import *
import sys
import bisect
import math
import itertools
import functools
import operator
import heapq
import time
import random
import string
import re
import copy
import os

# Macros for iteration
# End of Macros

# Function prototypes and necessary definitions
def read():
	return int(stdin.readline().strip())
def write(x):
	stdout.write(str(x)+'\n')
def writeln(x):
	stdout.write(str(x)+'\n')

# Main function
if __name__=='__main__':
	# Reading input
	n=read()

	# Reading array 'a'
	a=[0]*(n+1)
	for i in range(1,n+1):
		a[i]=read()

	# Sorting array 'a' in ascending order
	a.sort()

	# Finding duplicate elements and storing them in 'q'
	q=[]
	for i in range(1,n+1):
		if a[i]==a[i+1]:
			q.append(a[i])
			i+=1

	# Outputting the result
	write(q[len(q)-1]*q[len(q)-2])

	# End of main function

