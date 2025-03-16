s, t = input ( ), input ( )
freqs = new HashMap < > ( )
freqt = new HashMap < > ( )
yay, whoops = 0, 0
for ( char letra : s. toCharArray ( ) ) {
    if ( freqs. containsKey ( letra ) ) {
        freqs. put ( letra, freqs. get ( letra ) + 1 ) ;
    } else {
        freqs. put ( letra, 1 ) ;
    }
}
for ( char letra : t. toCharArray ( ) ) {
    if ( freqt. containsKey ( letra ) ) {
        freqt. put ( letra, freqt. get ( letra ) + 1 ) ;
    } else {
        freqt. put ( letra, 1 ) ;
    }
}
for ( char letra : freqs. keySet ( ) ) {
    while ( freqs. get ( letra ) > 0 && freqt. containsKey ( letra ) && freqt. get ( letra ) > 0 ) {
        yay += 1 ;
        freqs. put ( letra, freqs. get ( letra ) - 1 ) ;
        freqt. put ( letra, freqt. get ( letra ) - 1 ) ;
    }
}
for ( char letra : freqs. keySet ( ) ) {
    while ( freqs. get ( letra ) > 0 ) {
        if ( Character. isLowerCase ( letra ) && freqt. containsKey ( Character. toUpperCase ( letra ) ) && freqt. get ( Character. toUpperCase ( letra ) ) > 0 ) {
            whoops += 1 ;
            freqs. put ( letra, freqs. get ( letra ) - 1 ) ;
            freqt. put ( Character. toUpperCase ( letra ), freqt. get ( Character. toUpperCase ( letra ) ) - 1 ) ;
        } else if ( Character. isUpperCase ( letra ) && freqt. containsKey ( Character. toLowerCase ( letra ) ) && freqt. get ( Character. toLowerCase ( letra ) ) > 0 ) {
            whoops += 1 ;
            freqs. put ( letra, freqs. get ( letra ) - 1 ) ;
            freqt. put ( Character. toLowerCase ( letra ), freqt. get ( Character. toLowerCase ( letra ) ) - 1 ) ;
        } else {
            break ;
        }
    }
}
System. out. println ( yay + " " + whoops ) ;

