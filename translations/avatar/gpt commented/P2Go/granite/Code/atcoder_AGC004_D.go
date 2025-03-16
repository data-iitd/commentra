
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut++
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int)
	dfs = func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			h, c := dfs(u, v)
			hgt = max(hgt, h)
			cut += c
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut += 1
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(r, "%d", &a)
		a--
		links[a] = append(links[a], i)
	}
	var dfs func(v, p int) (int, int) {
		hgt, cut := 0, 0
		for _, u := range links[v] {
			if u == 0 {
				continue
			}
			hgt += 1
			cut += 1
		}
		hgt += 1
		if p!= 0 && hgt == k {
			hgt = 0
			cut += 1
		}
		return hgt, cut
	}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	w := bufio.NewWriter(&buf)
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		var dfs func(v, p int) (int, int) {
			hgt, cut := 0, 0
			for _, u := range links[v] {
				if u == 0 {
					continue
				}
				hgt += 1
				cut += 1
			}
			return hgt, cut
		}
	ans := dfs(0, 0)
	if links[0][0]!= 1 {
		ans[1]++
	}
	fmt.Fprintln(w, ans[1])
	w.Flush()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main1() {
	r := bu