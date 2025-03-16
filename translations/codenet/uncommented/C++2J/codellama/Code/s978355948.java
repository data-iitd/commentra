import java.util.Scanner;
import java.util.Vector;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		Vector<Integer> L = new Vector<Integer>();
		for(int i = 0; i < N; i++)
			L.add(sc.nextInt());
		
		int i;
		int d = 0;
		for(i = 0; i < N; i++){
			d = d + L.get(i);
			if(d > X)
				break;
		}

		System.out.println(i+1);
	}
}

