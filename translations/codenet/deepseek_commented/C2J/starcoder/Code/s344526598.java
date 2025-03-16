import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] x = new int[10000];
		int i = 0;
		int j = 0;
		x[i] = sc.nextInt();
		while(x[i]!= 0){
			i++;
			x[i] = sc.nextInt();
		}
		for(j=0;j<i;j++){
			System.out.println("Case " + (j+1) + ": " + x[j]);
		}
	}
}
