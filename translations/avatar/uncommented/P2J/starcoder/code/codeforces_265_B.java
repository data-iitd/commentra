n = Integer.parseInt ( input ( ) )
l = new ArrayList < > ( )
for ( int i = 0 ; i < n ; i ++ )
    l.add ( Integer.parseInt ( input ( ) ) )
int ans = n - 1
int last = 0
for ( int i : l )
    ans += Math.abs ( last - i ) + 1
    last = i
System.out.println ( ans )
// 