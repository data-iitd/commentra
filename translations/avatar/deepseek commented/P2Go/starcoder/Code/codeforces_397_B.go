
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// CodeforcesTask397BSolution implements the solution to the problem
type CodeforcesTask397BSolution struct {
    result string
    t      int
    queries [][3]int
}

// NewCodeforcesTask397BSolution returns a new solution for the problem
func NewCodeforcesTask397BSolution ( ) *CodeforcesTask397BSolution {
    return &CodeforcesTask397BSolution { }
}

// Read the number of test cases and the queries from input
func ( solution *CodeforcesTask397BSolution ) readInput ( ) {
    solution.t, _ = strconv.Atoi ( readLine ( ) )  // Read the number of test cases
    for _ := range solution.queries {
        solution.queries = append ( solution.queries, [3]int { } )
        solution.queries [ len ( solution.queries ) - 1 ] [ 0 ], _ = strconv.Atoi ( readLine ( ) )  // Read the first number of each query
        solution.queries [ len ( solution.queries ) - 1 ] [ 1 ], _ = strconv.Atoi ( readLine ( ) )  // Read the second number of each query
        solution.queries [ len ( solution.queries ) - 1 ] [ 2 ], _ = strconv.Atoi ( readLine ( ) )  // Read the third number of each query
}

// Processes each query to determine if the condition is met
func ( solution *CodeforcesTask397BSolution ) processTask ( ) {
    res := [ ]
    for _, query := range solution.queries {
        k := query [ 0 ] / query [ 1 ]  // Calculate k as the integer division of query[0] by query[1]
        res = append ( res, "Yes" if k * query [ 2 ] >= query [ 0 ] else "No" )  // Append "Yes" or "No" based on the condition
}
    solution.result = strings.Join ( res, "\n" )  // Join the results into a single string with newline characters
}

// Returns the final result
func ( solution *CodeforcesTask397BSolution ) getResult ( ) string {
    return solution.result
}

// Reads a line of input from stdin
func readLine ( ) string {
    reader := bufio.NewReader ( os.Stdin )
    line, _, err := reader.ReadLine ( )
    if err!= nil {
        panic ( err )
}
    return strings.TrimSpace ( string ( line ) )
}

// Main function
func main ( ) {
    solution := NewCodeforcesTask397BSolution ( )
    solution.readInput ( )
    solution.processTask ( )
    fmt.Println ( solution.getResult ( ) )  // Print the final result
}

