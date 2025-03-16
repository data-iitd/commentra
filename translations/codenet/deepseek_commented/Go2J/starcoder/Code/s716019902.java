package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			if (i % 3 == 0 || i % 5 == 0) {
				continue;
			}
			sum += i;
		}
		System.out.println(sum);
	}
}

// fmt.Println("Yes")
// fmt.Println("No")

// I/O
class scanner {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			if (i % 3 == 0 || i % 5 == 0) {
				continue;
			}
			sum += i;
		}
		System.out.println(sum);
	}
}

//const mod = 998244353
const facNum = 300001

// 階乗: factorial
// コンビネーションを計算する際に前もって計算しておく
// fac[k] => k! (mod M)
// ifac[k] => k!^(M-2) (mod M)
// n: ex. 2 * 10^5 => 200001
// fac, ifac := factorial()
func factorial() (fac []int, ifac []int) {
	fac = new int[facNum];
	fac[0] = 1;
	ifac = new int[facNum];
	ifac[0] = 1;
	for (int i = 1; i < facNum; i++) {
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod;
	}
	return
}

// vs: sorted slice int value
func lowerBound(vs []int, v int) (index int) {
	int n = vs.length / 2;
	int m = vs.length;
	while (m!= n) {
		if (vs[n] < v) {
			n = (m-n+1)/2 + n;
			//m = m
		} else {
			m = n;
			n = n / 2;
		}
	}
	return n;
}

func IntSlice(n, init int) []int {
	int[] r = new int[n];
	for (int i = 0; i < n; i++) {
		r[i] = init;
	}
	return r;
}

// Translate the above Java code to C++ and end with comment "