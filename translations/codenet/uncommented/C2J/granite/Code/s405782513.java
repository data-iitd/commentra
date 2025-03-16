
import java.util.Scanner;

public class s405782513{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while (sc.hasNextInt()){
			int[] c = new int[3];
			
			for (int i = 0; i < 3; i++){
				c[i] = sc.nextInt();
			}
			char[] card = new char[10];
			int count = 0;
			int sum = c[0] + c[1];
			
			for (int i = 0; i < 3; i++){
				card[c[i] - 1] = '1';
			}
			for (int i = 0; i < 10; i++){
				if (card[i] == '0' && sum + i + 1 <= 20){
					count++;
				}
			}
			if (count >= 4){
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
		}
		
		sc.close();
	}
}

