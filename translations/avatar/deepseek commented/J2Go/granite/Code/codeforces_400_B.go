

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var nTemp string
	n, err := reader.ReadString('\n')
	checkError(err)
	n = strings.TrimSpace(nTemp)
	nVal, err := strconv.ParseInt(n, 10, 64)
	checkError(err)
	mTemp := ""
	m, err := reader.ReadString('\n')
	checkError(err)
	m = strings.TrimSpace(mTemp)
	mVal, err := strconv.ParseInt(m, 10, 64)
	checkError(err)

	arrs := make([]string, int(nVal))

	for i := 0; i < int(nVal); i++ {
		arrsTemp, err := reader.ReadString('\n')
		checkError(err)
		arrsTemp = strings.TrimSpace(arrsTemp)
		arrs[i] = arrsTemp
	}

	length := make([]int, int(nVal))

	index := 0
	returnDex := 0

	for _, tmp := range arrs {
		dexG := strings.Index(tmp, "G")
		dexS := strings.Index(tmp, "S")
		if dexG > dexS {
			returnDex = -1
		}
		length[index] = dexS - dexG
		index++
	}

	set := make(map[int]bool)

	for _, len := range length {
		set[len] = true
	}

	if returnDex == -1 {
		fmt.Println(returnDex)
	} else {
		fmt.Println(len(set))
	}
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

