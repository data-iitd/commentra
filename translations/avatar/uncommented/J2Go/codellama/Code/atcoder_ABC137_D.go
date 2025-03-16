
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Job struct {
	a, b int
}

type Jobs []Job

func (j Jobs) Len() int {
	return len(j)
}

func (j Jobs) Less(i, j int) bool {
	if j[i].a == j[j].a {
		return j[i].b < j[j].b
	}
	return j[i].a < j[j].a
}

func (j Jobs) Swap(i, j int) {
	j[i], j[j] = j[j], j[i]
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var N, M int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	M, _ = strconv.Atoi(sc.Text())
	jobs := make(Jobs, 0, N)
	for i := 0; i < N; i++ {
		sc.Scan()
		line := strings.Split(sc.Text(), " ")
		jobs = append(jobs, Job{a: strconv.Atoi(line[0]), b: strconv.Atoi(line[1])})
	}
	sort.Sort(jobs)
	cnt := 0
	jobQ := make([]int, 0, M)
	for i := 1; i <= M; i++ {
		for len(jobs) > 0 && jobs[0].a <= i {
			jobQ = append(jobQ, jobs[0].b)
			jobs = jobs[1:]
		}
		if len(jobQ) > 0 {
			cnt += jobQ[0]
			jobQ = jobQ[1:]
		}
	}
	fmt.Println(cnt)
}

