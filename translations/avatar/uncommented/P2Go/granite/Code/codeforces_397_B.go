
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type CodeforcesTask397BSolution struct {
    reader *bufio.Reader
    writer *bufio.Writer
}

func ( solution *CodeforcesTask397BSolution ) read_input( ) {
    solution.reader = bufio.NewReader ( os.Stdin )
}

func ( solution *CodeforcesTask397BSolution ) process_task( ) {
    var t int
    fmt.Fscanf ( solution.reader, "%d\n", &t )
    queries := make ( [][]int, t )
    for i := 0; i < t; i++ {
        query := make ( []int, 3 )
        fmt.Fscanf ( solution.reader, "%d %d %d\n", &query[0], &query[1], &query[2] )
        queries[i] = query
    }
    res := make ( []string, t )
    for i, query := range queries {
        k := query[0] / query[1]
        if k * query[2] >= query[0] {
            res[i] = "Yes"
        } else {
            res[i] = "No"
        }
    }
    solution.writer = bufio.NewWriter ( os.Stdout )
    for _, r := range res {
        fmt.Fprintln ( solution.writer, r )
    }
}

func ( solution *CodeforcesTask397BSolution ) get_result( ) {
    solution.writer.Flush ( )
}

func main( ) {
    solution := CodeforcesTask397BSolution{}
    solution.read_input( )
    solution.process_task( )
    solution.get_result( )
}

