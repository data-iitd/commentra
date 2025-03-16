import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double a;
		double ave = 0;
		int i;
		
		for (i = 0; i < 5; i++){
			a = sc.nextDouble();
			if (a <= 40){
				ave += 40;
			}
			else {
				ave += a;
			}
		}
		//System.out.printf("%.0f\n", ave);
		
		ave /= 5.0;
		
		System.out.printf("%.0f\n", ave);
	}
}
