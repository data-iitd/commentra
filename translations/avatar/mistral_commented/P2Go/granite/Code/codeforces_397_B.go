
###
# Codeforces Task 397 B Solution
###

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type CodeforcesTask397BSolution struct {
    result string
}

func ( solution *CodeforcesTask397BSolution ) read_input() {
    reader := bufio.NewReader( os.Stdin )
    var t int
    var queries [] [] int
    input_string, _ := reader.ReadString('\n')
    t, _ = strconv.Atoi( strings.TrimSpace(input_string) )
    for i := 0; i < t; i++ {
        input_string, _ = reader.ReadString('\n')
        query := strings.Split( strings.TrimSpace(input_string), " " )
        var k int
        k, _ = strconv.Atoi( query[0] )
        k /= strconv.Atoi( query[1] )
        if k * strconv.Atoi( query[2] ) >= strconv.Atoi( query[0] ) {
            queries = append( queries, [] int { 1, i } )
        } else {
            queries = append( queries, [] int { 0, i } )
        }
    }
    solution.queries = queries
}

func ( solution *CodeforcesTask397BSolution ) process_task() {
    res := make([] string, len(solution.queries) )
    for i, query := range solution.queries {
        if query[0] == 1 {
            res[ query[1] ] = "Yes"
        } else {
            res[ query[1] ] = "No"
        }
    }
    solution.result = strings.Join( res, "\n" )
}

func ( solution *CodeforcesTask397BSolution ) get_result() string {
    return solution.result
}

func main() {
    solution := CodeforcesTask397BSolution{}
    solution.read_input()
    solution.process_task()
    fmt.Println( solution.get_result() )
}

