

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	vTemp := strings.Split(readLine(reader), " ")

	v := make([]int32, n)

	for i := 0; i < int(n); i++ {
		vTempI, err := strconv.ParseInt(vTemp[i], 10, 64)
		checkError(err)
		v[i] = int32(vTempI)
	}

	vo := make(map[int32]int32)
	ve := make(map[int32]int32)
	vt := make(map[int32]int32)

	for i := 0; i < int(n); i++ {
		if i%2 == 0 {
			vo[v[i]]++
		} else {
			ve[v[i]]++
		}
		vt[v[i]]++
	}

	voKeys := make([]int32, 0)
	for k := range vo {
		voKeys = append(voKeys, k)
	}
	veKeys := make([]int32, 0)
	for k := range ve {
		veKeys = append(veKeys, k)
	}
	vtKeys := make([]int32, 0)
	for k := range vt {
		vtKeys = append(vtKeys, k)
	}

	sort.Slice(voKeys, func(i, j int) bool {
		return vo[voKeys[i]] > vo[voKeys[j]]
	})
	sort.Slice(veKeys, func(i, j int) bool {
		return ve[veKeys[i]] > ve[veKeys[j]]
	})
	sort.Slice(vtKeys, func(i, j int) bool {
		return vt[vtKeys[i]] > vt[vtKeys[j]]
	})

	ans := int32(0)

	if vo[voKeys[0]]+ve[veKeys[0]] == vt[vtKeys[0]] {
		ans = int32(min(n-vo[voKeys[0]]-ve[veKeys[1]], n-vo[voKeys[1]]-ve[veKeys[0]]))
	} else {
		ans = n - vo[voKeys[0]] - ve[veKeys[0]]
	}

	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func min(x, y int) int {
	if x < y {
		return x
	}

	return y
}

