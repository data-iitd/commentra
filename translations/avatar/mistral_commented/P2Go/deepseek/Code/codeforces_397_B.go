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
	queries [][]int
}

func (c *CodeforcesTask397BSolution) readInput() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	c.t, _ = strconv.Atoi(scanner.Text())
	for i := 0; i < c.t; i++ {
		scanner.Scan()
		parts := strings.Split(scanner.Text(), " ")
		query := []int{}
		for _, part := range parts {
			num, _ := strconv.Atoi(part)
			query = append(query, num)
		}
		c.queries = append(c.queries, query)
	}
}

func (c *CodeforcesTask397BSolution) processTask() {
	res := []string{}
	for _, query := range c.queries {
		k := query[0] / query[1]
		if k * query[2] >= query[0] {
			res = append(res, "Yes")
		} else {
			res = append(res, "No")
		}
	}
	c.result = strings.Join(res, "\n")
}

func (c *CodeforcesTask397BSolution) getResult() string {
	return c.result
}

func main() {
	Solution := CodeforcesTask397BSolution{}
	Solution.readInput()
	Solution.processTask()
	fmt.Println(Solution.getResult())
}

