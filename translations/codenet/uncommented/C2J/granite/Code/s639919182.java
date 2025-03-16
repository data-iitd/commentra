
import java.util.Scanner;
public class s639919182{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] v = new int[10];
		int sum = 0;
		for(int i = 0; i < 10; i++) {
			v[i] = sc.nextInt();
			sum += v[i];
		}
		System.out.println(sum);
	}
}
// 