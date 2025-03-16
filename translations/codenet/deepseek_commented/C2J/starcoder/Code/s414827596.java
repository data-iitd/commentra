import java.util.*;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt()){
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int d = sc.nextInt();
			int e = sc.nextInt();
			int f = sc.nextInt();
			double x,y;
			y = (double)(c*d-f*a)/(b*d-e*a);
			x = (double)(c*e-f*b)/(a*e-d*b);
			if(y<=0&&y>-0.0005)y=0;
			if(x<=0&&x>-0.0005)x=0;
			System.out.printf("%.3f %.3f\n",x,y);
		}
	}
}
