import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long m=n;
		n--;
		for(;n>1;n--) {
			m*=n;
		}
		System.out.println(m);
	}
}
