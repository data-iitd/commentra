s = input ( )
res = new ArrayList < > ( )
punctuation = new ArrayList < > ( Arrays.asList ( ',', '.', '!', '?' ) )
for ( int i = 0 ; i < s.length ( ) ; i++ ) {
    if ( i >= 1 ) {
        if ( s.charAt ( i ) =='' ) {
            if ( res.get ( res.size ( ) - 1 )!='' ) {
                res.add ( s.charAt ( i ) )
            } else {
                continue
            }
        } else {
            if ( punctuation.contains ( s.charAt ( i ) ) ) {
                if ( res.get ( res.size ( ) - 1 ) =='' ) {
                    res.remove ( res.size ( ) - 1 )
                }
                res.add ( s.charAt ( i ) )
                res.add ('' )
            } else {
                res.add ( s.charAt ( i ) )
            }
        }
    } else {
        if ( s.charAt ( i ) =='' ) {
            continue
        }
        if ( punctuation.contains ( s.charAt ( i ) ) ) {
            continue
        } else {
            res.add ( s.charAt ( i ) )
        }
    }
}
System.out.println ( String.valueOf ( res ) )

