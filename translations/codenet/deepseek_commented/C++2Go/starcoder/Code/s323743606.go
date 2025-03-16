<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
    m := make(map[int]int)
    for i := 0; i*200 < 5001; i++ { // Loop through possible values of i
        for j := 0; j*300 < 5001; j++ { // Loop through possible values of j
            for k := 0; k*500 < 5001; k++ { // Loop through possible values of k
                w := i*200 + j*300 + k*500 // Calculate the weight
                p := i/5*5*380*0.8 + i%5*380 // Calculate the price for i
                     + j/4*4*550*0.85 + j%4*550 // Calculate the price for j
                     + k/3*3*850*0.88 + k%3*850 // Calculate the price for k
                if m[w] > 0 {
                    m[w] = min(m[w], p) // Update the map with the minimum price
                } else {
                    m[w] = p // Add new weight and price to the map
                }
            }
        }
    }
    var n int
    for {
        fmt.Scanf("%d", &n)
        if n == 0 {
            break
        }
        fmt.Println(m[n])
    }
}

