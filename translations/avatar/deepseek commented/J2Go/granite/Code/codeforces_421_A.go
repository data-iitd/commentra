

package main 

import ( 
    "bufio" 
    "fmt" 
    "os" 
    "strconv" 
    "strings" 
) 

func main ( ) { 
    // Step 3: Create a Scanner object to read input from the user
    reader := bufio.NewReader ( os.Stdin ) 
    // Step 4: Read the values of n, a, and b
    var n, a, b int 
    var err error 
    var input string 
    if input, err = reader.ReadString ( '\ n' ) ; err!= nil { 
        panic ( err ) 
    } 
    n, err = strconv.Atoi ( strings.TrimSpace ( input ) ) 
    if input, err = reader.ReadString ( '\ n' ) ; err!= nil { 
        panic ( err ) 
    } 
    a, err = strconv.Atoi ( strings.TrimSpace ( input ) ) 
    if input, err = reader.ReadString ( '\ n' ) ; err!= nil { 
        panic ( err ) 
    } 
    b, err = strconv.Atoi ( strings.TrimSpace ( input ) ) 
    // Step 5: Create two ArrayList objects to store the lists of integers
    list1 := make ( [] int, a ) 
    list2 := make ( [] int, b ) 
    // Step 6: Read the elements of list1 and list2 from the user
    for i := 0 ; i < a ; i ++ { 
        if input, err = reader.ReadString ('' ) ; err!= nil { 
            panic ( err ) 
        } 
        list1 [ i ], err = strconv.Atoi ( strings.TrimSpace ( input ) ) 
        if err!= nil { 
            panic ( err ) 
        } 
    } 
    for i := 0 ; i < b ; i ++ { 
        if input, err = reader.ReadString ('' ) ; err!= nil { 
            panic ( err ) 
        } 
        list2 [ i ], err = strconv.Atoi ( strings.TrimSpace ( input ) ) 
        if err!= nil { 
            panic ( err ) 
        } 
    } 
    // Step 7: Iterate through the range from 1 to n and print the appropriate list number
    for i := 0 ; i < n ; i ++ { 
        if contains ( list1, i + 1 ) { 
            fmt.Print ( 1, " " ) 
        } else { 
            fmt.Print ( 2, " " ) 
        } 
    } 
    fmt.Println ( ) 
} 

func contains ( list [] int, element int ) bool { 
    for _, value := range list { 
        if value == element { 
            return true 
        } 
    } 
    return false 
} 

