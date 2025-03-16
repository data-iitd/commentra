import java. util. Collections ; import java. util. PriorityQueue ; import java. util. Queue ; import java. util. Scanner ; class Job ( ) :
    def __init__ ( self, a, b ) :
        self. a = a
        self. b = b
    def compareTo ( self, otherJob ) :
        if ( otherJob. a == self. a ) :
            return self. b - otherJob. b
        else :
            return self. a - otherJob. a

def main ( ) :
    sc = Scanner ( System. in )
    line = sc. nextLine ( ). split ( " \u2581 " )
    N = int ( line [ 0 ] )
    M = int ( line [ 1 ] )
    q = PriorityQueue ( )
    for i in range ( N ) :
        line = sc. nextLine ( ). split ( " \u2581 " )
        q. add ( Job ( int ( line [ 0 ] ), int ( line [ 1 ] ) ) )
    cnt = 0
    jobQ = PriorityQueue ( )
    for i in range ( 1, M + 1 ) :
        while ( not q. isEmpty ( ) ) :
            job = q. peek ( )
            if ( job. a <= i ) :
                jobQ. add ( q. poll ( ). b )
            else :
                break
        if ( not jobQ. isEmpty ( ) ) :
            cnt += jobQ. poll ( )
    print ( cnt )

main ( )
# 