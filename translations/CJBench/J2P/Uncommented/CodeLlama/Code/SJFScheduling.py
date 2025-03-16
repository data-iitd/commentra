import sys
import math
import itertools
import collections
import statistics
import heapq
import array
import bisect
import functools
import operator
import re
import queue
from collections import deque
from itertools import permutations, combinations, accumulate, product
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from fractions import gcd
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, match, sub
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from collections import Counter, defaultdict
from heapq import heappush, heappop
from array import array
from bisect import bisect_left, bisect_right
from operator import itemgetter
from copy import deepcopy
from functools import reduce
from math import ceil, floor, log, log2, sqrt, pow, factorial
from re import findall, m