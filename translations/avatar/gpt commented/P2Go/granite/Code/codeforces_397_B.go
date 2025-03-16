
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
	t      int
	queries [][3]int
}

func (solution *CodeforcesTask397BSolution) read_input() {
	reader := bufio.NewReader(os.Stdin)
	t, _ := strconv.Atoi(reader.ReadLine()[2:])
	solution.queries = make([][3]int, t)
	for i := 0; i < t; i++ {
		query := strings.Split(reader.ReadLine()[2:], " ")
		var a, b, c int
		a, _ = strconv.Atoi(query[0])
		b, _ = strconv.Atoi(query[1])
		c, _ = strconv.Atoi(query[2])
		solution.queries[i] = [3]int{a, b, c}
	}
}

func (solution *CodeforcesTask397BSolution) process_task() {
	res := make([]string, solution.t)
	for i, query := range solution.queries {
		k := query[0] / query[1]
		if k * query[2] >= query[0] {
			res[i] = "Yes"
		} else {
			res[i] = "No"
		}
	}
	solution.result = strings.Join(res, "\n")
}

func (solution *CodeforcesTask397BSolution) get_result() string {
	return solution.result
}

func main() {
	solution := CodeforcesTask397BSolution{}
	solution.read_input()
	solution.process_task()
	fmt.Println(solution.get_result())
}

