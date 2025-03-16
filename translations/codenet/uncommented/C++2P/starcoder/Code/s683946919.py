
#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
import sys
import math
import string
import itertools
import collections
import heapq
import time
import random
import bisect
import re
import copy
import os
import sys
import itertools
import collections
import heapq
import time
import random
import bisect
import re
import copy
import os
import sys

def time2min(month,day,hour,min):
  total_day_of_month = [31,28,31,30,31,30,31,31,30,31,30,31]
  total = 0
  for i in range(1,month):
    total += total_day_of_month[i]*24*60
  for i in range(1,day):
    total += 24*60
  total += hour * 60 + min

  return total

if __name__ == "__main__":
  while True:
    N = int(input())
    if N == 0: break

    log = collections.defaultdict(list)
    for i in range(N):
      month,day,hour,min,action,id = map(int,input().split())
      t = time2min(month,day,hour,min)
      log[id].append(t)

    total = [0]*1000
    for i in range(len(log[0])-1):
      god_start = log[0][i]
      god_end = log[0][i+1]

      for id,schedule in log.items():
	if id == 0: continue
	for j in range(len(schedule)-1):
	  ppl_start = schedule[j]
	  ppl_end = schedule[j+1]
	  start = max(god_start,ppl_start)
	  end = min(god_end,ppl_end)
	  total[id] += max(0,end-start)

    print(max(total))

