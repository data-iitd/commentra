
# Python 2.7.6
# Author: <NAME>
# Created: 2014-09-21
# Last modified: 2014-09-21
#
# Description:
#   A program to solve the problem of finding the XOR of all the subsets of a set of 7 elements.
#
#   The program reads a number of test cases from standard input. Each test case consists of a number of
#   elements in the set. The program then outputs the XOR of all the subsets of the set.
#
#   The program uses a segment tree to solve the problem.
#
#   The program uses the following functions:
#       - all()
#       - any()
#       - bin()
#       - bool()
#       - cmp()
#       - dict()
#       - float()
#       - frozenset()
#       - int()
#       - list()
#       - long()
#       - map()
#       - max()
#       - min()
#       - object()
#       - set()
#       - str()
#       - sum()
#       - tuple()
#       - type()
#       - zip()
#
#   The program uses the following constants:
#       - inf
#       - INF
#       - EPS
#
#   The program uses the following variables:
#       - n: The number of test cases
#       - t: The current test case
#       - st: The current segment tree state
#       - ans: The answer to the current test case
#
#   The program uses the following data structures:
#       - list
#       - set
#       - dict
#
#   The program uses the following algorithms:
#       - Segment tree
#
#   The program uses the following I/O methods:
#       - cin
#       - cout
#
#   The program uses the following mathematical methods:
#       - all()
#       - any()
#       - bin()
#       - bool()
#       - cmp()
#       - dict()
#       - float()
#       - frozenset()
#       - int()
#       - list()
#       - long()
#       - map()
#       - max()
#       - min()
#       - object()
#       - set()
#       - str()
#       - sum()
#       - tuple()
#       - type()
#       - zip()
#
#   The program uses the following modules:
#       - sys
#       - itertools
#
#   The program uses the following syntax:
#       - for... in...:
#       - if...:
#       - elif...:
#       - else:
#       - while...:
#       - def...():
#       - class...():
#       - import...
#       - from... import...
#       - global...
#       - nonlocal...
#       - try:... except:...
#       - assert...
#       - yield...
#       - with... as...:
#       - exec...
#       - print...
#       - pass
#       - break
#       - continue
#       - return
#       - raise...
#       - True
#       - False
#       - None
#       - Ellipsis
#       - NotImplemented
#       -...
#
#   The program uses the following exceptions:
#       - Exception
#       - StandardError
#       - ArithmeticError
#       - LookupError
#       - EnvironmentError
#       - AssertionError
#       - AttributeError
#       - EOFError
#       - FloatingPointError
#       - IOError
#       - ImportError
#       - IndexError
#       - KeyError
#       - KeyboardInterrupt
#       - MemoryError
#       - NameError
#       - NotImplementedError
#       - OSError
#       - OverflowError
#       - ReferenceError
#       - RuntimeError
#       - StopIteration
#       - SyntaxError
#       - IndentationError
#       - TabError
#       - SystemError
#       - SystemExit
#       - TypeError
#       - UnboundLocalError
#       - UnicodeError
#       - UnicodeEncodeError
#       - UnicodeDecodeError
#       - UnicodeTranslateError
#       - ValueError
#       - ZeroDivisionError
#
#   The program uses the following functions:
#       - all()
#       - any()
#       - bin()
#       - bool()
#       - cmp()
#       - dict()
#       - float()
#       - frozenset()
#       - int()
#       - list()
#       - long()
#       - map()
#       - max()
#       - min()
#       - object()
#       - set()
#       - str()
#       - sum()
#       - tuple()
#       - type()
#       - zip()
#
#   The program uses the following constants:
#       - inf
#       - INF
#       - EPS
#
#   The program uses the following variables:
#       - n: The number of test cases
#       - t: The current test case
#       - st: The current segment tree state
#       - ans: The answer to the current test case
#
#   The program uses the following data structures:
#       - list
#       - set
#       - dict
#
#   The program uses the following algorithms:
#       - Segment tree
#
#   The program uses the following I/O methods:
#       - cin
#       - cout
#
#   The program uses the following mathematical methods:
#       - all()
#       - any()
#       - bin()
#       - bool()
#       - cmp()
#       - dict()
#       - float()
#       - frozenset()
#       - int()
#       - list()
#       - long()
#       - map()
#       - max()
#       - min()
#       - object()
#       - set()
#       - str()
#       - sum()
#       - tuple()
#       - type()
#       - zip()
#
#   The program uses the following modules:
#       - sys
#       - itertools
#
#   The program uses the following syntax:
#       - for... in...:
#       - if...:
#       - elif...:
#       - else:
#       - while...:
#       - def...():
#       - class...():
#       - import...
#       - from... import...
#       - global...
#       - nonlocal...
#       - try:... except:...
#       - assert...
#       - yield...
#       - with... as...:
#       - exec...
#       - print...
#       - pass
#       - break
#       - continue
#       - return
#       - raise...
#       - True
#       - False
#       - None
#       - Ellipsis
#       - NotImplemented
#       -...
#
#   The program uses the following exceptions:
#       - Exception
#       - StandardError
#       - ArithmeticError
#       - LookupError
#       - EnvironmentError
#       - AssertionError
#       - AttributeError
#       - EOFError
#       - FloatingPointError
#       - IOError
#       - ImportError
#       - IndexError
#       - KeyError
#       - KeyboardInterrupt
#       - MemoryError
#       - NameError
#       - NotImplementedError
#       - OSError
#       - OverflowError
#       - ReferenceError
#       - RuntimeError
#       - StopIteration
#       - SyntaxError
#       - IndentationError
#       - TabError
#       - SystemError
#       - SystemExit
#       - TypeError
#       - UnboundLocalError
#       - UnicodeError
#       - UnicodeEncodeError
#       - UnicodeDecodeError
#       - UnicodeTranslateError
#       - ValueError
#       - ZeroDivisionError
#
#   The program uses the following functions:
#       - all()
#       - any()
#       - bin()
#       - bool()
#       - cmp()
#       - dict()
#       - float()
#       - frozenset()
#       - int()
#       - list()
#       - long()
#       - map()
#       - max()
#       - min()
#       - object()
#       - set()
#       - str()
#       - sum()
#       - tuple()
#       - type()
#       - zip()
#
#   The program uses the following constants:
#       - inf
#       - INF
#       - EPS
#
#   The program uses the following variables:
#       - n: The number of test cases
#       - t: The current test case
#       - st: The current segment tree state
#       - ans: The answer to the current test case
#
#   The program uses the following data structures:
#       - list
#       - set
#       - dict
#
#   The program uses the following algorithms:
#       - Segment tree
#
#   The program uses the following I/O methods:
#       - cin
#       - cout
#
#   The program uses the following mathematical methods:
#       - all()
#       - any()
#       - bin()
#       - bool()
#       - cmp()
#       - dict()
#       - float()
#       - frozenset()
#       - int()
#       - list()
#       - long()
#       - map()
#       - max()
#       - min()
#       - object()
#       - set()
#       - str()
#       - sum()
#       - tuple()
#       - type()
#       - zip()
#
#   The program uses the following modules:
#       - sys
#       - itertools
#
#   The program uses the following syntax:
#       - for... in...:
#       - if...:
#       - elif...:
#       - else:
#       - while...:
#       - def...():
#       - class...():
#       - import...
#       - from... import...
#       - global...
#       - nonlocal...
#       - try:... except:...
#       - assert...
#       - yield...
#       - with... as...:
#       - exec...
#       - print...
#       - pass
#       - break
#       - continue
#       - return
#       - raise...
#       - True
#       - False
#       - None
#       - Ellipsis
#       - NotImplemented
#       -...
#
#   The program uses the following exceptions:
#       - Exception
#       - StandardError
#       - ArithmeticError
#       - LookupError
#       - EnvironmentError
#       - AssertionError
#       - AttributeError
#       - EOFError
#       - FloatingPointError
#       - IOError
#       - ImportError
#       - IndexError
#       - KeyError
#       - KeyboardInterrupt
#       - MemoryError
#       - NameError
#       - NotImplementedError
#       - OSError
#       - OverflowError
#       - ReferenceError
#       - RuntimeError
#       - StopIteration
#       - SyntaxError
#       - IndentationError
#       - TabError
#       - SystemError
#       - SystemExit
#       - TypeError
#       - UnboundLocalError
#       - UnicodeError
#       - UnicodeEncodeError
#       - UnicodeDecodeError
#       - UnicodeTranslateError
#       - ValueError
#       - ZeroDivisionError
#
#   The program uses the following functions:
#       - all()
#       - any()
#       - bin()
#       - bool()
#       - cmp()
#       - dict()
#       - float()
#       - frozenset()
#       - int()
#       - list()
#       - long()
#       - map()
#       - max()
#       - min()
#       - object()
#       - set()
#       - str()
#       - sum()
#       - tuple()
#       - type()
#       - zip()
#
#   The program uses the following constants:
#       - inf
#       - INF
#       - EPS
#
#   The program uses the following variables:
#       - n: The number of test cases
#       - t: The current test case
#       - st: The current segment tree state
#       - ans: The answer to the current test case
#
#   The program uses the following data structures:
#       - li