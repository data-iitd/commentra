
package main

import "fmt"

func main() {
var i,n,tmp int
var min,max,sum int64

fmt.Scan(&n)
	
for i=0;i<n;i++ {
fmt.Scan(&tmp)
if min>tmp {
min=tmp
}
if max<tmp {
max=tmp
}
sum+=tmp
}

fmt.Printf("%d %d %d\n",min,max,sum)

}
