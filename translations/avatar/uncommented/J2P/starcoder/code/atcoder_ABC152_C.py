
import java.util.PriorityQueue ; import java.util.Queue ; import java.util.Scanner ; def solve ( ): N = int ( raw_input ( ) ) ; arr = [ int ( raw_input ( ) ) for i in range ( N ) ] ; sum = 0 ; q = PriorityQueue ( ) ; for i in range ( N ): q.add ( arr [ i ] ) ; if ( arr [ i ] <= q.peek ( ) ): sum += 1 ; return sum ; print ( solve ( ) )

