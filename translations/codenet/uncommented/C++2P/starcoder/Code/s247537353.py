
import sys
import math
import collections
import itertools
import heapq
import time
import random
import bisect
import array
import re
import copy
import os
import string
import functools
import operator
import statistics
import functools
import itertools
import bisect
import math
import sys
import time
import array
import collections
import itertools
import heapq
import re
import copy
import os
import string
import statistics
import functools
import operator

A,B,C,K=map(int,input().split())
if A+B>=K:
  print(min(A,K))
else:
  print(A-(K-(A+B)))

