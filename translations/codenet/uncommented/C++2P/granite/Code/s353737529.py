
# -*- coding: utf-8 -*-

# <START-OF-CODE>

import sys
import math
import collections
import bisect
import heapq
import random
import re
import itertools
import statistics

def read_int():
    return int(sys.stdin.readline().strip())

def read_int_n():
    return list(map(int, sys.stdin.readline().split()))

def read_float():
    return float(sys.stdin.readline().strip())

def read_float_n():
    return list(map(float, sys.stdin.readline().split()))

def read_str():
    return input().strip()

def read_str_n():
    return list(map(str, sys.stdin.readline().split()))

def error_exit(message):
    sys.stderr.write(str(message) + '\n')
    sys.exit()

# 