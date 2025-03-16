import bisect , collections , copy , heapq , itertools , math , numpy , string
import sys
def S ( ) : return sys.stdin.readline ( ).rstrip ( )
def I ( ) : return int ( sys.stdin.readline ( ).rstrip ( ) )
def LI ( ) : return list ( map ( int , sys.stdin.readline ( ).rstrip ( ).split ( ) ) )
def LS ( ) : return list ( sys.stdin.readline ( ).rstrip ( ).split ( ) )
# 1. The code starts by importing several modules, including `sys` for system-related operations.
a , b = LI ( )
# 2. It reads two integers `a` and `b`.
if a > 0 :
    # 3. It then checks if `a` is greater than 0, and if so, it prints 'Positive'.
    print ( 'Positive' )
elif a <= 0 and b >= 0 :
    # 4. If `a` is less than or equal to 0 and `b` is greater than or equal to 0, it prints 'Zero'.
    print ( 'Zero' )
else :
    # 5. If neither of the above conditions is met, it checks if the sum of `a` and `b` is even or odd.
    if ( a + b ) % 2 == 0 :
        # 6. If it's even, it prints 'Negative'; if odd, it prints 'Positive'.
        print ( 'Negative' )
    else :
        print ( 'Positive' )
