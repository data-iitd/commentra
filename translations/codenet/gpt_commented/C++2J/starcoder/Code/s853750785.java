
import java.util.*;
import java.io.*;
import java.math.*;

public class AtCoder {

	// Define type aliases for convenience
	static final long mod = 1000000007;
	static final int MAX = 100005;
	static final int INF = (int)1e9;
	static final double EPS = 1e-9;
	static final double PI = Math.acos(-1.0);
	static final long[] fact = new long[MAX];
	static final long[] ifact = new long[MAX];
	static final Random rnd = new Random(1234567890);

	// Define mathematical constants and macros
	static final double rad_to_deg = 180.0 / PI;
	static final double deg_to_rad = PI / 180.0;
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return Math.cbrt(x); }
	static final double sqr(int x) { return x * x; }
	static final double cbrt(int x) { return Math.cbrt(x); }
	static final double sqr(long x) { return x * x; }
	static final double cbrt(long x) { return Math.cbrt(x); }
	static final double sqr(float x) { return x * x; }
	static final double cbrt(float x) { return Math.cbrt(x); }
	static final double sqr(double x) { return x * x; }
	static final double cbrt(double x) { return