
import sys
import os
import io
import re
import math
import heapq
import bisect
import random
import time
import copy
import itertools
import string
import operator
import functools
import collections
import queue
import threading
import resource
import struct
import array
import typing
import fractions
import pathos
import numba
import scipy
import sklearn
import pandas
import matplotlib
import seaborn
import plotly
import plotly.graph_objects as go
import plotly.express as px
import plotly.figure_factory as ff
import cffi
import cmath
import time

def getScanner(fp):
    return bufio.Scanner(fp).split()

def getNextString(scanner):
    return next(scanner)

def getNextInt(scanner):
    return int(getNextString(scanner))

def getNextInt64(scanner):
    return int(getNextString(scanner))

def getNextUint64(scanner):
    return int(getNextString(scanner))

def getNextFloat64(scanner):
    return float(getNextString(scanner))

def main():
    cnt = 0
    if os.getenv("MASPY") == "ますπ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
        cnt = 2
    else:
        fp = sys.stdin

    if os.getenv("MASPYPY") == "ますπッピ":
        sys.stdout = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")
    else:
        sys.stdout = sys.__stdout__

    scanner = getScanner(fp)
    solve(scanner)
    for i in range(cnt):
        print("-----------------------------------")
        solve(scanner)

def solve(scanner):
    k = getNextInt(scanner)
    x = getNextInt(scanner)

    ans = "No"
    if k*500 >= x:
        ans = "Yes"
    print(ans)

if __name__ == "__main__":
    main()

