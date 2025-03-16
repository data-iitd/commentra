

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type CodeforcesTask397BSolution struct {
    t       int
    queries [][]int
    result  string
}

func ( solution *CodeforcesTask397BSolution ) read_input ( ) {
    reader := bufio.NewReader ( os.Stdin )
    
    fmt.Fscanf ( reader, "%d\n", &solution.t )
    solution.queries = make ( [][]int, solution.t )
    for i := 0; i < solution.t; i++ {
        query := make ( []int, 3 )
        fmt.Fscanf ( reader, "%d %d %d\n", &query[0], &query[1], &query[2] )
        solution.queries[i] = query
    }
}

func ( solution *CodeforcesTask397BSolution ) process_task ( ) {
    res := make ( []string, solution.t )
    for i, query := range solution.queries {
        k := query[0] / query[1]
        if k * query[2] >= query[0] {
            res[i] = "Yes"
        } else {
            res[i] = "No"
        }
    }
    solution.result = strings.Join ( res, "\n" )
}

func ( solution *CodeforcesTask397BSolution ) get_result ( ) {
    return solution.result
}

func main ( ) {
    solution := CodeforcesTask397BSolution{}
    solution.read_input()
    solution.process_task()
    fmt.Println ( solution.get_result() )
}

