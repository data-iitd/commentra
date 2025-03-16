
import math
import sys

try:
    input = float(sys.stdin.readline())
    count_odd = math.floor(input / 2)
    result = count_odd / input
    print(round(result, 10))
except ValueError:
    print("ValueError")
except ZeroDivisionError:
    print("ZeroDivisionError")
except Exception as e:
    print(e)

