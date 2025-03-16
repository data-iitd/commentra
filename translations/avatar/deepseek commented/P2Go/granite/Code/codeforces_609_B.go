

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the values of n and m
    reader := bufio.NewReader ( os.Stdin )
    n, _ := strconv.Atoi ( strings.TrimSpace ( reader.ReadLine ( ) )
    m, _ := strconv.Atoi ( strings.TrimSpace ( reader.ReadLine ( ) )
    // Read the list of elements
    lst := make ( []int, n )
    for i := 0 ; i < n ; i ++ {
        var tmp int
        tmp, _ = strconv.Atoi ( strings.TrimSpace ( reader.ReadLine ( ) )
        lst [ i ] = tmp
    }
    // Initialize a dictionary to store the frequency of elements
    l := make ( map [ int ] int )
    // Populate the dictionary with the frequency of each element in the list
    for i := 0 ; i < n ; i ++ {
        if l [ lst [ i ] ] == 0 {
            l [ lst [ i ] ] = 1
        } else {
            l [ lst [ i ] ] += 1
        }
    }
    // Initialize the result variable to store the final result
    res := 0
    // Iterate over the list to calculate the result
    for i := 0 ; i < n ; i ++ {
        if l [ lst [ i ] ] > 1 {
            // Calculate the number of pairs that can be formed with the current element
            res += n - i - l [ lst [ i ] ]
            // Decrement the frequency of the current element in the dictionary
            l [ lst [ i ] ] -= 1
        } else {
            // If the frequency is not greater than 1, calculate the number of pairs
            res += n - i - 1
        }
    }
    // Print the final result
    fmt.Println ( res )
}
