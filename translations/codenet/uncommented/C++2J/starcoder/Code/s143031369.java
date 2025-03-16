import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n,xx,yy;
		n=in.nextInt();
		Point[] P=new Point[110];
		for(int i=0;i<n;i++){
			xx=in.nextInt();
			yy=in.nextInt();
			P[i]=new Point(xx,yy);
		}
		if(n==2){
			System.out.println("0.5");
			System.out.println("0.5");
		}else{
			int m=jarvis(P,n);
			double sum=0;
			if(m==2){
				P[0].k=0.5;
				P[1].k=0.5;
			}else{
				for(int i=0;i<m;i++){
					P[ch[i]].k=PI-acos(cos(P[ch[i]],P[ch[(i-1+m)%m]],P[ch[(i+1)%m]]));
				}
				for(int i=0;i<n;i++){
					P[i].k/=2./PI;
				}
			}
			for(int i=0;i<n;i++){
				System.out.println(P[i].k);
			}
		}
	}
	public static int jarvis(Point[] P, int n) {
		int d, i, o, s, l, t;
		for(d = i = 0; i < n; i ++)
			if(P[i] < P[d])
				d = i;
		l = s = d;
		d = 1;
		do {
			o = l;
			for(i = 0; i < n; i ++)
				if((t=sig(cross(P[o], P[l], P[i])))>0 || (t==0 && btw(P[l], P[o], P[i])<=0))
					l = i;
			ch[d ++] = l;
		} while(l!= s); 
		return d-1;
	}
	public static int sig(double d) {
		return Math.abs(d) < 1e-8? 0 : d < 0? -1 : 1;
	}
	public static double dot(Point o, Point a, Point b) {
		return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);
	}
	public static double dot(Point a, Point b) {
		return a.x*b.x + a.y*b.y;	//(a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);
	}
	public static double cross(Point o, Point a, Point b) {
		return (a.x - o.x)*(b.y - o.y)-(b.x - o.x)*(a.y - o.y);
	}
	public static int btw(Point x, Point a, Point b) {
		return sig(dot(x, a, b));
	}
	public static double dis(Point a, Point b) {
		return Math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	}
	public static double cos(Point o, Point a, Point b) {
		return dot(o,a,b)/dis(o,a)/dis(o,b);
	}
	static class Point implements Comparable<Point> {
		double x, y, k;
		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
		public Point() {}
		public void set(double x, double y) {
			this.x = x;
			this.y = y;
		}
		public double mod() {
			return Math.sqrt(x*x+y*y);
		}
		public double mod_pow() {
			return x*x + y*y;
		}
		public void output() {
			System.out.printf("x = %f, y = %f\n", x, y);
		}
		public int compareTo(Point p) {
			if(sig(x-p.x)!= 0)
				return x < p.x? -1 : 1;
			else
				return sig(y-p.y) < 0? -1 : 1;
		}
		public boolean equals(Point p) {
			return x == p.x && y == p.y;
		}
		public boolean less(Point p) {
			return x < p.x || (x == p.x && y < p.y);
		}
		public boolean less_eq(Point p) {
			return x < p.x || (x == p.x && y <= p.y);
		}
		public boolean greater(Point p) {
			return x > p.x || (x == p.x && y > p.y);
		}
		public boolean greater_eq(Point p) {
			return x > p.x || (x == p.x && y >= p.y);
		}
		public boolean not_eq(Point p) {
			return x!= p.x || y!= p.y;
		}
		public boolean operator < (Point p) {
			return less(p);
		}
		public boolean operator <= (Point p) {
			return less_eq(p);
		}
		public boolean operator > (Point p) {
			return greater(p);
		}
		public boolean operator >= (Point p) {
			return greater_eq(p);
		}
		public boolean operator!= (Point p) {
			return not_eq(p);
		}
	}
}

