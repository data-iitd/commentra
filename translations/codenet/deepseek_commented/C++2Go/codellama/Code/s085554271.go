
package main

import (
	"fmt"
	"math"
	"math/bits"
	"sort"
	"strings"
)

func main() {
	//COMinit()
	//IOS;
	//prec;
	//Int a,b,c,n,m,k,x,y=0,ans=0;
	//string str,s,t,u;
	//cin>>k>>a>>b;
	//for (int i = a; i <=b; ++i) {
	//	if(i%k==0){
	//		cout<<"OK"<<endl;
	//		return 0;
	//	}
	//}
	//cout<<"NG";

	//cout<<endl;
	//return 0;
}

func isPrime(num int) bool {
	if num < 2 {
		return false
	} else if num == 2 {
		return true
	} else if num%2 == 0 {
		return false // 偶数はあらかじめ除く
	}

	sqrtNum := math.Sqrt(float64(num))
	for i := 3; i <= int(sqrtNum); i += 2 {
		if num%i == 0 {
			// 素数ではない
			return false
		}
	}

	// 素数である
	return true
}

func gcd(a, b int) int {
	return b / gcd(b, a%b)
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

func Max(a, b, c int) int {
	temp := max(a, b)
	return max(temp, c)
}

func Min(a, b, c int) int {
	temp := min(a, b)
	return min(temp, c)
}

func integer(num float64) bool {
	return math.Floor(num) == num
}

func fact(num int) int {
	if num == 0 {
		return 1
	} else {
		return num * fact(num-1)
	}
}

func yakusu(n int) int {
	cnt := 0
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			cnt++
			if i*i != n {
				cnt++
			}
		}
	}
	return cnt
}

func fact_mod(n, mod int) int {
	f := 1
	for i := 2; i <= n; i++ {
		f = f * (i % mod) % mod
	}
	return f
}

func mod_pow(x, n, mod int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}

func combination_mod(n, r, mod int) int {
	if r > n-r {
		r = n - r
	}
	if r == 0 {
		return 1
	}
	a := 1
	for i := 0; i < r; i++ {
		a = a * ((n - i) % mod) % mod
	}
	b := mod_pow(fact_mod(r, mod), mod-2, mod)
	return a % mod * b % mod
}

func rev(s string) bool {
	t := s
	sort.Slice([]byte(s), func(i, j int) bool {
		return s[i] < s[j]
	})
	return s == t
}

// 