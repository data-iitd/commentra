
import java.util.*;
import java.io.*;

class s480530100 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        BIT bit = new BIT(n);
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            bit.add(i, a);
        }
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            if (t == 0) {
                int p = sc.nextInt();
                int x = sc.nextInt();
                bit.add(p, x);
            } else {
                int l = sc.nextInt();
                int r = sc.nextInt();
                System.out.println(bit.sum(l, r));
            }
        }
    }
}

class BIT {
    int n;
    int[] data;

    public BIT(int n) {
        this.n = n;
        data = new int[n];
    }

    public void add(int p, int x) {
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
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
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    public int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
     