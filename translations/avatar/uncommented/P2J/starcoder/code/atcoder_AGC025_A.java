n = input ( )
a = new String[] { "10", "100", "1000", "10000", "100000" }
new = 0
for i in n :
    new += Integer.parseInt ( i )
if ( n.equals ( a[0] ) ) :
    System.out.println ( "10" )
else :
    System.out.println ( new )

