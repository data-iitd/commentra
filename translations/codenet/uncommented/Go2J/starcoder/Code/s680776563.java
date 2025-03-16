package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		if (B - A == C - B) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}

//template
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//<START-OF-CODE>
	}
}

//Max,Min
public class Main {
	public static int max(int a, int b) {
		if (a < b) {
			return b;
		}
		return a;
	}

	public static long max(long a, long b) {
		if (a < b) {
			return b;
		}
		return a;
	}

	public static float max(float a, float b) {
		if (a < b) {
			return b;
		}
		return a;
	}

	public static double max(double a, double b) {
		if (a < b) {
			return b;
		}
		return a;
	}

	public static int min(int a, int b) {
		if (a > b) {
			return b;
		}
		return a;
	}

	public static long min(long a, long b) {
		if (a > b) {
			return b;
		}
		return a;
	}

	public static float min(float a, float b) {
		if (a > b) {
			return b;
		}
		return a;
	}

	public static double min(double a, double b) {
		if (a > b) {
			return b;
		}
		return a;
	}
}

//Gcd
public class Main {
	public static int gcd(int a, int b) {
		if (a < b) {
			int t = a;
			a = b;
			b = t;
		}
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	public static long gcd(long a, long b) {
		if (a < b) {
			long t = a;
			a = b;
			b = t;
		}
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}
}

public class Main {
	public static int abs(int a) {
		if (a < 0) {
			a *= -1;
		}
		return a;
	}

	public static long abs(long a) {
		if (a < 0) {
			a *= -1;
		}
		return a;
	}
}

//Translate the above Java code to C++ and end with comment "