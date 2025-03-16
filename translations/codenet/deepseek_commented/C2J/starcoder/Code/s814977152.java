import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		int[] tomatu = new int[N];
		int yukinnko = 1;
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
			tomatu[i] = A[i];
		}
		Arrays.sort(tomatu);
		for (int i = 1; i < N; i++) {
			if (tomatu[i]!= tomatu[yukinnko - 1]) {
				tomatu[yukinnko++] = tomatu[i];
			}
		}
		int[] mikakosi = new int[yukinnko];
		for (int i = 0; i < N; i++) {
			int kugyu = Arrays.binarySearch(tomatu, A[i]);
			if (kugyu < 0) kugyu = -kugyu - 1;
			mikakosi[kugyu] = 1 - mikakosi[kugyu];
		}
		int emirinn = 0;
		for (int i = 0; i < yukinnko; i++) {
			if (mikakosi[i] == 1) emirinn++;
		}
		System.out.println(emirinn);
	}
}

