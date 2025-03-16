
# Include necessary headers for the program

import sys
import math
import collections
import itertools
import functools
import operator
import heapq
import array
import bisect
import time
import random
import re
import string
import copy
import os

# Include necessary headers for the program

from sys import stdin, stdout
from math import *
from collections import *
from itertools import *
from functools import *
from operator import *
from heapq import *
from array import *
from bisect import *
from time import *
from random import *
from re import *
from string import *
from copy import *
from os import *

# Define aliases for common data types and containers

# Define helper functions for gcd and lcm

def getPrimeFactor(n):
	res = {}
	# Initialize an empty map to store prime factors and their exponents

	for i in range(2, int(sqrt(n)) + 1):
		while n % i == 0:
			res[i] = res.get(i, 0) + 1
			# If the number is divisible by 'i', add it to the map with its exponent incremented

			n /= i
		if n == 1: break
	if n!= 1: res[n] = 1
	# If the number is not 1, add it to the map with exponent 1

	return res

# Function to get prime factors of a number

def IsPrimeNumber(num):
	if num <= 2: return True
	else if num % 2 == 0: return False

	sqrtNum = sqrt(num)
	# Check if the number is prime by checking divisibility up to its square root

	for i in range(3, int(sqrtNum) + 1, 2):
		if num % i == 0:
			return False
	return True

# Function to check if a number is prime

def modinv(a, m):
	b = m, u = 1, v = 0
	# Extended Euclidean Algorithm to find modular multiplicative inverse

	while b:
		t = a / b
		a -= t * b; a, b = b, a
		u -= t * v; u, v = v, u
	u %= m
	# Make the result positive and less than'm'

	if u < 0: u += m
	return u

# Function to find modular multiplicative inverse

# Define macros for for loops

# Main function to solve the problem

# 