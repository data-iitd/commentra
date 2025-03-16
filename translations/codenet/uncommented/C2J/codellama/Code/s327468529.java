#if 0
cat <<EOF >mistaken-paste
#endif
// thx Ebi-chan!

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.Vector;

public class Main {
	static int n, m;
	static int h, w;
	static int k;
	static int q;
	static int va, vb, vc, vd, ve, vf;
	static long ua, ub, uc, ud, ue, uf;
	static double vra, vrb, vrc;
	static double vda, vdb, vdc;
	static char ch, dh;

	static long umin (long x, long y) {
		return (x < y) ? x : y;
	}

	static long umax (long x, long y) {
		return (x > y) ? x : y;
	}

	static long smin (long x, long y) {
		return (x < y) ? x : y;
	}

	static long smax (long x, long y) {
		return (x > y) ? x : y;
	}

	static long gcd (long x, long y) {
		if (y == 0) {
			return x;
		} else {
			return gcd(y, x % y);
		}
	}

	static long bitpow (long a, long x, long modulo) {
		long result = 1;
		while (x > 0) {
			if (x % 2 == 1) {
				result *= a;
				result %= modulo;
			}
			x /= 2;
			a = (a * a) % modulo;
		}
		return result;
	}

	static long divide (long a, long b, long modulo) {
		return (a * bitpow(b, modulo - 2, modulo)) % modulo;
	}

	static long udiff (long a, long b) {
		if (a >= b) {
			return a - b;
		} else {
			return b - a;
		}
	}

	static long sdiff (long a, long b) {
		if (a >= b) {
			return a - b;
		} else {
			return b - a;
		}
	}

	static int bitcount (long n) {
		int result = 0;
		while (n > 0) {
			if (n % 2 == 1) result++;
			n /= 2;
		}
		return result;
	}

	static class hwll {
		long a;
		long b;
	}

	static class hwllc {
		long a;
		long b;
		long c;
	}

	static class linell {
		hwll a;
		hwll b;
	}

	static class hwreal {
		double a;
		double b;
	}

	static class pullcomp implements Comparator<Long> {
		public int compare(Long l, Long r) {
			if (l < r) {
				return -1;
			} else if (l > r) {
				return +1;
			} else {
				return 0;
			}
		}
	}

	static class prevcomp implements Comparator<Long> {
		public int compare(Long l, Long r) {
			if (r < l) {
				return -1;
			} else if (r > l) {
				return +1;
			} else {
				return 0;
			}
		}
	}

	static class psllcomp implements Comparator<Long> {
		public int compare(Long l, Long r) {
			if (l < r) {
				return -1;
			} else if (l > r) {
				return +1;
			} else {
				return 0;
			}
		}
	}

	static class pcharcomp implements Comparator<Character> {
		public int compare(Character l, Character r) {
			if (l < r) {
				return -1;
			} else if (l > r) {
				return +1;
			} else {
				return 0;
			}
		}
	}

	static class pdoublecomp implements Comparator<Double> {
		public int compare(Double l, Double r) {
			if (l < r) {
				return -1;
			} else if (l > r) {
				return +1;
			} else {
				return 0;
			}
		}
	}

	static class phwllABcomp implements Comparator<hwll> {
		public int compare(hwll l, hwll r) {
			if (l.a < r.a) {
				return -1;
			} else if (l.a > r.a) {
				return +1;
			} else {
				if (l.b < r.b) {
					return -1;
				} else if (l.b > r.b) {
					return +1;
				} else {
					return 0;
				}
			}
		}
	}

	static class phwllREVcomp implements Comparator<hwll> {
		public int compare(hwll l, hwll r) {
			if (l.b < r.b) {
				return -1;
			} else if (l.b > r.b) {
				return +1;
			} else {
				if (l.a < r.a) {
					return -1;
				} else if (l.a > r.a) {
					return +1;
				} else {
					return 0;
				}
			}
		}
	}

	static class ptriplecomp implements Comparator<hwllc> {
		public int compare(hwllc l, hwllc r) {
			if (l.a < r.a) {
				return -1;
			} else if (l.a > r.a) {
				return +1;
			} else {
				if (l.b < r.b) {
					return -1;
				} else if (l.b > r.b) {
					return +1;
				} else {
					if (l.c < r.c) {
						return -1;
					} else if (l.c > r.c) {
						return +1;
					} else {
						return 0;
					}
				}
			}
		}
	}

	static class ptripleREVcomp implements Comparator<hwllc> {
		public int compare(hwllc l, hwllc r) {
			if (l.b < r.b) {
				return -1;
			} else if (l.b > r.b) {
				return +1;
			} else {
				if (l.a < r.a) {
					return -1;
				} else if (l.a > r.a) {
					return +1;
				} else {
					if (l.c < r.c) {
						return -1;
					} else if (l.c > r.c) {
						return +1;
					} else {
						return 0;
					}
				}
			}
		}
	}

	static class ptripleCABcomp implements Comparator<hwllc> {
		public int compare(hwllc l, hwllc r) {
			if (l.c < r.c) {
				return -1;
			} else if (l.c > r.c) {
				return +1;
			} else {
				if (l.a < r.a) {
					return -1;
				} else if (l.a > r.a) {
					return +1;
				} else {
					if (l.b < r.b) {
						return -1;
					} else if (l.b > r.b) {
						return +1;
					} else {
						return 0;
					}
				}
			}
		}
	}

	static class phwrealcomp implements Comparator<hwreal> {
		public int compare(hwreal l, hwreal r) {
			if (l.a < r.a) {
				return -1;
			} else if (l.a > r.a) {
				return +1;
			} else {
				if (l.b < r.b) {
					return -1;
				} else if (l.b > r.b) {
					return +1;
				} else {
					return 0;
				}
			}
		}
	}

	static class pquadcomp implements Comparator<linell> {
		public int compare(linell l, linell r) {
			int ac = phwllABcomp.compare(l.a, r.a);
			if (ac != 0) {
				return ac;
			}
			int bc = phwllABcomp.compare(l.b, r.b);
			if (bc != 0) {
				return bc;
			}
			return 0;
		}
	}

	static class pfracomp implements Comparator<hwllc> {
		public int compare(hwllc l, hwllc r) {
			if (l.a * r.b < l.b * r.a) {
				return -1;
			} else if (l.a * r.b > l.b * r.a) {
				return +1;
			} else {
				return 0;
			}
		}
	}

	static boolean isinrange (long left, long x, long right) {
		return (left <= x && x <= right);
	}

	static boolean isinrange_soft (long left, long x, long right) {
		return (left <= x && x <= right) || (left >= x && x >= right);
	}

	static void sw (long[] l, long[] r) {
		if (l[0] == r[0]) return;
		long t = l[0];
		l[0] = r[0];
		r[0] = t;
	}

	static long frac[] = new long[N_MAX * 3];
	static long invf[] = new long[N_MAX * 3];
	static long ncr (long n, long r, long m) {
		if (n < 0 || r < 0 || n < r) return 0;
		return frac[n] * (invf[r] * invf[n - r] % m) % m;
	}

	static long a[] = new long[N_MAX + 5];
	static long b[] = new long[N_MAX + 5];
	static long c[] = new long[N_MAX + 5];
	static long d[] = new long[N_MAX + 5];
	static long e[] = new long[N_MAX * 4];
	static char s[] = new char[N_MAX + 1];
	static char t[] = new char[N_MAX + 1];
	static char u[] = new char[N_MAX + 1];
	static hwll xy[] = new hwll[N_MAX + 5];
	static hwllc tup[] = new hwllc[N_MAX + 5];
	static long table[][] = new long