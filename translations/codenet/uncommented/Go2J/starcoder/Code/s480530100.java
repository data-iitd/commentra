package main;

import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();

		BIT fw = new BIT(n);
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			fw.add(i, a);
		}

		for (int i = 0; i < q; i++) {
			int t = sc.nextInt();
			if (t == 0) {
				int p = sc.nextInt();
				int x = sc.nextInt();
				fw.add(p, x);
			} else {
				int l = sc.nextInt();
				int r = sc.nextInt();
				System.out.println(fw.sum(r) - fw.sum(l));
			}
		}
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	int[] data;

	public BIT(int n) {
		this.n = n;
		data = new int[n];
	}

	public void add(int p, int x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public int sum(int r) {
		int s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
	int n;
	long[] data;

	public BIT(int n) {
		this.n = n;
		data = new long[n];
	}

	public void add(int p, long x) {
		p++;
		for (int i = p; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	public long sum(int r) {
		long s = 0;
		for (int i = r; i > 0; i -= i & -i) {
			s += data[i - 1];
		}
		return s;
	}
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

/