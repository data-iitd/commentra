<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"
func main() {
	var input [4][4]int
	var tc int
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			fmt.Scanf("%d", &input[i][j])
		}
	}
	fmt.Scanf("%d", &tc)
	for i := 0; i < tc; i++ {
		var testcase int
		fmt.Scanf("%d", &testcase)
		for m := 0; m < 3; m++ {
			for n := 0; n < 3; n++ {
				if input[m][n] == testcase {
					input[m][n] = 0
				}
			}
		}
	}
	if input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
	} else if input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0 {
		fmt.Println("Yes")
	} else if input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0 {
		fmt.Println("Yes")
	} else if input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0 {
		fmt.Println("Yes")
	} else if input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
	} else if input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0 {
		fmt.Println("Yes")
	} else if input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0 {
		fmt.Println("Yes")
	} else if input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
