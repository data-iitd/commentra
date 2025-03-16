
public class Main {
	public static void main(String[] args) {
		int N = 0;
		int R = 0;

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		R = sc.nextInt();

		if(N >= 10) {
			System.out.println(R);
		} else {
			System.out.println(R + 100*(10-N));
		}
	}
}

