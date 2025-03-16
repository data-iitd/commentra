
import sys

def main ( ):
    inputStream = sys.stdin
    outputStream = sys.stdout
    in = InputReader ( inputStream )
    out = PrintWriter ( outputStream )

    solver = CColoringColorfully ( )
    solver.solve ( 1 , in , out )

    out.close ( )

class InputReader:
    def __init__ ( self , inputStream ):
        self.reader = inputStream
        self.tokenizer = None

    def next ( self ):
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens ( ):
            try:
                self.tokenizer = StringTokenizer ( self.reader.readLine ( ) )
            except IOException as e:
                raise RuntimeException ( e )
        return self.tokenizer.nextToken ( )

class CColoringColorfully:
    def solve ( self , testNumber , in , out ):
        x = in.next ( )
        a = StringBuilder ( x )
        b = StringBuilder ( x )
        a1 = 0
        a2 = 0

        for i in range ( 1 , len ( x ) ):
            if a.charAt ( i ) == a.charAt ( i - 1 ):
                if a.charAt ( i ) == '1':
                    a.setCharAt ( i , '0' )
                else:
                    a.setCharAt ( i , '1' )
                a1 += 1

        for i in range ( len ( x ) - 1 , 0 , -1 ):
            if b.charAt ( i ) == b.charAt ( i - 1 ):
                if b.charAt ( i - 1 ) == '1':
                    b.setCharAt ( i - 1 , '0' )
                else:
                    b.setCharAt ( i - 1 , '1' )
                a2 += 1

        out.println ( min ( a1 , a2 ) )

class StringBuilder:
    def __init__ ( self , x ):
        self.x = x

    def charAt ( self , i ):
        return self.x [ i ]

    def setCharAt ( self , i , c ):
        self.x [ i ] = c

class PrintWriter:
    def __init__ ( self , outputStream ):
        self.writer = outputStream

    def println ( self , x ):
        self.writer.write ( str ( x ) + '\n' )

    def close ( self ):
        self.writer.close ( )

if __name__ == '__main__':
    main ( )

