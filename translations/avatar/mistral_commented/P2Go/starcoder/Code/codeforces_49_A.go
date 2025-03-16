// Define a list containing all the vowels in upper and lower case
var vo = []string{ "a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y" }

// Take an input string 'a' from the user
var a string
fmt.Scanln( &a )

// Iterate through the string 'a' from the end to the beginning
for i := len( a ) - 1 ; i >= 0 ; i-- {
    // If the current character is a space or a question mark, skip it and move on to the next character
    if a[ i ] =='' || a[ i ] == '?' {
        continue
    }
    // If the current character is not a space or a question mark, check if it is a vowel or not
    if a[ i ] == vo[ i ] {
        // If it is, print "YES" and break out of the loop
        fmt.Println( "YES" )
        break
    }
    // If it is not, print "NO" and break out of the loop
    fmt.Println( "NO" )
    break
}
