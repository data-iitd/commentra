
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Job struct {
	a int
	b int
}

func (j Job) CompareTo(otherJob Job) int {
	if otherJob.a == j.a {
		return j.b - otherJob.b
	} else {
		return j.a - otherJob.a
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	sc.Scan()
	line := strings.Split(sc.Text(), " ")
	N, _ := strconv.Atoi(line[0])
	M, _ := strconv.Atoi(line[1])

	q := make([]Job, 0)

	for i := 0; i < N; i++ {
		sc.Scan()
		line = strings.Split(sc.Text(), " ")
		a, _ := strconv.Atoi(line[0])
		b, _ := strconv.Atoi(line[1])
		q = append(q, Job{a, b})
	}

	cnt := 0
	jobQ := make([]int, 0)

	for i := 1; i <= M; i++ {
		for len(q) > 0 && q[0].a <= i {
			jobQ = append(jobQ, q[0].b)
			q = q[1:]
		}

		if len(jobQ) > 0 {
			cnt += jobQ[0]
			jobQ = jobQ[1:]
		}
	}

	fmt.Println(cnt)
}

