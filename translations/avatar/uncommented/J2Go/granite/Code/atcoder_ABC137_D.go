
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Job struct {
	a int
	b int
}

type ByA []Job

func (a ByA) Len() int           { return len(a) }
func (a ByA) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByA) Less(i, j int) bool { return a[i].a < a[j].a }

type ByB []Job

func (a ByB) Len() int           { return len(a) }
func (a ByB) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByB) Less(i, j int) bool { return a[i].b < a[j].b }

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	line = strings.Replace(line, "\r", "", -1)
	line = strings.Replace(line, "\n", "", -1)
	parts := strings.Split(line, " ")
	N, _ := strconv.Atoi(parts[0])
	M, _ := strconv.Atoi(parts[1])
	jobs := make([]Job, N)
	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		line = strings.Replace(line, "\r", "", -1)
		line = strings.Replace(line, "\n", "", -1)
		parts = strings.Split(line, " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		jobs[i] = Job{a, b}
	}
	sort.Sort(ByA(jobs))
	var jobQ []int
	var cnt int
	for i := 1; i <= M; i++ {
		for len(jobs) > 0 && jobs[0].a <= i {
			jobQ = append(jobQ, jobs[0].b)
			jobs = jobs[1:]
		}
		if len(jobQ) > 0 {
			sort.Sort(sort.Reverse(ByB(jobQ)))
			cnt += jobQ[0]
			jobQ = jobQ[1:]
		}
	}
	fmt.Println(cnt)
}
