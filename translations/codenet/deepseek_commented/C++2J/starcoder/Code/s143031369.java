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
				System.out.println("0.5");
				System.out.println("0.5");
			}else{
				for(int i=0;i<m;i++){
					ang[ch[i]]=PI-acos(cos(P[ch[i]],P[ch[(i-1+m)%m]],P[ch[(i+1)%m]]));
				}
				for(int i=0;i<n;i++){
					ans[i]=ang[i]/2./PI;
				}
			}
			for(int i=0;i<n;i++){
				System.out.println(ans[i]);
			}
		}
	}
	static int ch[]=new int[110];
	static double ang[]=new double[110];
	static double ans[]=new double[110];
	static double PI=Math.acos(-1.0);
	static int sig(double d) {
		return Math.abs(d) < 1e-8? 0 : d < 0? -1 : 1;
	}

	static class Point {
		double x, y;
		double k;
		Point(){}
		Point(double x, double y): x(x), y(y) {}
		void set(double x, double y) {
			this.x = x;
			this.y = y; 
		}
		double mod() {
			return Math.sqrt(x*x+y*y);
		}
		double mod_pow() {
			return x*x + y*y;
		}
		void output() {
			System.out.printf("x = %f, y = %f\n", x, y);
		}
		public boolean operator < (Point p) {
			return sig(x-p.x)!= 0? x < p.x : sig(y-p.y) < 0;
		}
	}
	static int jarvis(Point[] p, int n) {
		int d, i, o, s, l, t;
		for(d = i = 0; i < n; i ++)
			if(p[i] < p[d])
				d = i;
		l = s = ch[0] = d;
		d = 1;
		do {
			o = l;
			for(i = 0; i < n; i ++)
				if((t=sig(cross(p[o], p[l], p[i])))>0 || (t==0 && btw(p[l], p[o], p[i])<=0))
					l = i;
			ch[d ++] = l;
		} while(l!= s); 
		return d-1;
	}

	static double dot(Point o, Point a, Point b) {
		return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);
	}

	static double dot(Point a, Point b) {
		return a.x*b.x + a.y*b.y;	//(a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);
	}
	static double cross(Point o, Point a, Point b) {
		return (a.x - o.x)*(b.y - o.y)-(b.x - o.x)*(a.y - o.y);
	}
	static int btw(Point x, Point a, Point b) {
		return sig(dot(x, a, b));
	}
	static double dis(Point a, Point b) {
		return Math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	}

	static double cos(Point o, Point a, Point b) {
		return dot(o,a,b)/dis(o,a)/dis(o,b);
	}
}

