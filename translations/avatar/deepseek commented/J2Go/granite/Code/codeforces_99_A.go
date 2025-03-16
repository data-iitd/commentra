

package main 

import ( 
    "bufio" 
    "fmt" 
    "os" 
    "strconv" 
    "math/big" 
) 

func main ( ) { 
    // Read input string from the user
    reader := bufio.NewReader ( os.Stdin ) 
    str, _ := reader.ReadString ( '\n' ) 
    str = str [ : len ( str ) - 1 ] 

    // Find the index of the dot ('.') in the string
    dotIndex := 0 
    for i := 0 ; i < len ( str ) ; i ++ { 
        if str [ i ] == '.' { 
            dotIndex = i 
            break 
        } 
    } 

    // Check if the character before the dot is '9'
    if str [ dotIndex - 1 ] == '9' { 
        fmt.Println ( "GOTO Vasilisa." ) 
    } 
    // If the character before the dot is not '9', check the digit after the dot
    else if int ( str [ dotIndex + 1 ] [ 0 ] ) > 4 { 
        // Increment the number before the dot by 1 and print the result
        _str := "" 
        for i := 0 ; i < dotIndex ; i ++ { 
            _str += string ( str [ i ] ) 
        } 
        fmt.Println ( new ( big.Int ).Add ( new ( big.Int ).SetInt64 ( int64 ( 0 ) ), new ( big.Int ).SetInt64 ( int64 ( 1 ) ) ) ) 
    } 
    // If the digit after the dot is 4 or less, print the number before the dot without any changes
    else { 
        for i := 0 ; i < dotIndex ; i ++ { 
            fmt.Print ( string ( str [ i ] ) ) 
        } 
        fmt.Println ( ) 
    } 
} 
