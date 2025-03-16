
package main

import "fmt"
import "bufio"
import "os"

func main() {
	reader := bufio.NewReader(os.Stdin)

	t, _ := reader.ReadString('\n')
	t = t[:len(t)-1]
	t_num, _ := strconv.Atoi(t)

	for i := 0; i < t_num; i++ {
		a, _ := reader.ReadString('\n')
		a = a[:len(a)-1]
		a_num, _ := strconv.Atoi(a)

		b, _ := reader.ReadString('\n')
		b = b[:len(b)-1]
		b_num, _ := strconv.Atoi(b)

		c, _ := reader.ReadString('\n')
		c = c[:len(c)-1]
		c_num, _ := strconv.Atoi(c)

		max := a_num
		k := 0
		if max <= b_num {
			max = b_num
			k = 1
		}
		if max <= c_num {
			max = c_num
			k = 2
		}

		max = max * max
		a_num = a_num * a_num
		b_num = b_num * b_num
		c_num = c_num * c_num
		if k == 0 && max == b_num+c_num {
			fmt.Println("YES")
		} else if k == 1 && max == a_num+c_num {
			fmt.Println("YES")
		} else if k == 2 && max == a_num+b_num {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

