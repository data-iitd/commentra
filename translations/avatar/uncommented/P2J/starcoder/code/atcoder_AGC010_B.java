n, a = Integer.parseInt ( sc.nextLine ( ) ), Arrays.stream ( sc.nextLine ( ).split ( " " ) ).mapToInt ( Integer::parseInt ).toArray ( )
if ( Arrays.stream ( a ).sum ( ) % ( n * ( n + 1 ) / 2 ) )!= 0 :
    System.out.println ( "NO" )
else :
    k = Arrays.stream ( a ).sum ( ) / ( n * ( n + 1 ) / 2 )
    a = Arrays.copyOf ( a, a.length + 1 )
    a [ a.length - 1 ] = a [ 0 ]
    if ( Arrays.stream ( IntStream.range ( 1, a.length ).mapToObj ( i -> ( k - a [ i ] + a [ i - 1 ] ) % n ).toArray ( ) ).sum ( )!= 0 ) or ( Arrays.stream ( IntStream.range ( 1, a.length ).mapToObj ( i -> ( k - a [ i ] + a [ i - 1 ] ) / n >= 0 ).toArray ( ) ).filter ( i -> i ).count ( )!= n ) :
        System.out.println ( "NO" )
    else :
        System.out.println ( "YES" )

