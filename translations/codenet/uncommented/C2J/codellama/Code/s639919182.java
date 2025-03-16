
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] v = new int[10];
		int sum = 0;
		int i;
		
		for(i=0;i<10;i++)
			v[i] = sc.nextInt();
		
		for(i=0;i<10;i++)
			sum += v[i];
		
		System.out.println(sum);
		
		sc.close();
	}
}

