

package main 

import ( 
    "bufio" 
    "fmt" 
    "os" 
    "strconv" 
    "strings" 
    "time" 
) 

func main ( ) { 
    // Step 1: Read two times from the user, split by colon and convert to LocalTime objects
    reader := bufio.NewReader ( os.Stdin ) 
    fmt.Print ( "Enter the first time (HH:MM): " ) 
    s, _ := reader.ReadString ( '\n' ) 
    s = strings.TrimSpace ( s ) 
    t, _ := reader.ReadString ( '\n' ) 
    t = strings.TrimSpace ( t ) 
    s = strings.Split ( s, ":" ) 
    t = strings.Split ( t, ":" ) 
    x, _ := time.Parse ( "15:04", s [ 0 ] + ":" + s [ 1 ] ) 
    y, _ := time.Parse ( "15:04", t [ 0 ] + ":" + t [ 1 ] ) 

    // Step 2: Calculate the difference between the two times
    fmt.Println ( x.Sub ( y ) ) 
} 

