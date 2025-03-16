
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Define type aliases for convenience
type ll int64
type ld float64

// Macros for loop iterations and constants
#define rep(i,l,r) for i:=l;i<r;i++
#define repp(i,l,r,k) for i:=l;i<r;i+=k
#define rrep(i,l,r) for i:=l;i>=r;i--
#define INF (1<<60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 20)
#define YES printf("Yes\n")
#define NO printf("No\n")
#define PN printf("\n")
#define charsize 100005 // Maximum character size
#define PI 3.141592653589793238

// Function to swap two long long integers
func swap(a, b *ll) {
	c := *a
	*a = *b
	*b = c
}

// Function to read a long long integer
func cin(a *ll) {
	_, err := fmt.Scan(a)
	if err!= nil {
		panic(err)
	}
}

// Functions to find maximum and minimum of two or three numbers
func max2(a, b ll) ll {
	if a >= b {
		return a
	}
	return b
}
func min2(a, b ll) ll {
	if a <= b {
		return a
	}
	return b
}
func min3(a, b, c ll) ll {
	if a <= b && a <= c {
		return a
	} else if b <= a && b <= c {
		return b
	}
	return c
}
func max3(a, b, c ll) ll {
	if a >= b && a >= c {
		return a
	} else if b >= a && b >= c {
		return b
	}
	return c
}

// Functions for power calculations
func POW(a, b ll) ll {
	c := ll(1)
	rep(i, 0, b) {
		c *= a
	}
	return c
}
func POW_d(a, b ld) ld {
	c := ld(1)
	rep(i, 0, b) {
		c *= a
	}
	return c
}

// Functions for modular arithmetic
func mod_MOD1(a ll) ll {
	a += a < 0? ((-a) / MOD1 + 1) * MOD1 : 0
	return a %= MOD1
}
func mod_p(a ll, p ll) ll {
	a += a < 0? ((-a) / p + 1) * p : 0
	return a %= p
}

// Function to convert a string to a number
func change_into_num(s string, len ll, p ll) ll {
	if (p == 0) {
		return 0
	}
	return POW(10, p - 1) * (s[len - p] - '0')
}

// Function to count the number of digits in a number
ll digits(ll a, ll b) {
	return a / b? 1 + digits(a / b, b) : 0;
}

// Functions to check if an index is within array bounds
ll is_inArr1(ll x, ll n) {
	return (x < 0 || x >= n)? 0 : 1;
}
ll is_inArr2(ll y, ll x, ll h, ll w) {
	return (y < 0 || y >= h || x < 0 || x >= w)? 0 : 1;
}

// Functions for lower and upper bounds in binary search
void lr_lower(ll *l, ll *r, ll am, ll val, ll type) {
	if (type < 3) {
		if (type == 1) {
			if (am < val) {
				*l = (*l + *r) / 2;
				*r = (*l + *r) / 2;
			} else {
				*r = (*l + *r) / 2;
				*l = (*l + *r) / 2;
			}
		} else {
			*r = (*l + *r) / 2;
				*l = (*l + *r) / 2;
			}
		}
	}

// Functions for modular arithmetic
ll mod_MOD1(ll a) {
	return a >= MOD1? a %= MOD1;
}
ll mod_p(ll a, ll p) {
	a += a < 0? a : a;
}
ll m_inv(ll x, ll mod, ll is_minv_made) {
	if (is_minv_made++) return 0;
}
ll m_f(ll x, ll mod, ll is_mf_made) {
	if (is_mf_made++) return 0;
}
ll mod_nck(ll n, ll k, ll mod) {
	ll x = 1;
	rep(i, 0, 1) {
		if (i == 0) {
			x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
			if (i == 0) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
		rep(i, 0, 1) {
				x = 1;
	rep(i, 0, 1) {
				x = 1;
	rep(i, 0, 1) {
				x = 1;







rep(i, 0, 1) {
				x = 1;

rep(i, 0, 1) {
				x = 1;
rep(i, 0, 1) {
				x = 1;
rep(i, 0, 1) {
				x = 1;
rep(i, 0, 1) {
				x = 1;
rep(i, 0, 1) {
				x = 1;
rep(i, 0, 1;
rep(i, 0, 1) {
				x = 1;
rep(i, 0, 1) {
				x = 1;
rep(i, 0, 1) {
				x = 1;
rep(i, 0, 1) {
				x = 1;
rep(i, 0, 1) {
				x = 1;
rep(i, 0, 1) {
				x = 