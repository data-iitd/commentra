
package main

import "fmt"

func main() {
	var t, m int
	fmt.Scan(&t, &m)
	alocuente := make([]int, m)
	ind := 1
	for i := 0; i < t; i++ {
		op := make([]string, 2)
		fmt.Scan(&op[0], &op[1])
		if op[0] == "alloc" {
			pos := 0
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					pos++
					if pos == int(op[1]) {
						alocuente[j-int(op[1])+1 : j+1] = make([]int, int(op[1]))
						for k := 0; k < int(op[1]); k++ {
							alocuente[j-int(op[1])+1+k] = ind
						}
						ind++
						break
					}
				} else {
					pos = 0
				}
			}
			if pos == 0 {
				fmt.Println("NULL")
			}
		}
		if op[0] == "erase" {
			pos := 0
			if int(op[1]) == 0 || int(op[1]) > m {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			} else {
				for j := 0; j < m; j++ {
					if int(op[1]) > 0 && alocuente[j] == int(op[1]) {
						alocuente[j] = 0
					}
				}
			}
		}
		if op[0] == "defragment" {
			cnt := 0
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					cnt++
				}
			}
			alocuente = alocuente[:m-cnt]
			for j := 0; j < cnt; j++ {
				alocuente = append(alocuente, 0)
			}
		}
	}
}

