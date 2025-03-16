
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		int[] tomatu = new int[N];
		for (int i = 0; i < N; i++) {
			tomatu[i] = A[i];
		}
		int yukinnko = 1;
		for (int i = 1; i < N; i++) {
			if (tomatu[i] != tomatu[yukinnko - 1]) {
				tomatu[yukinnko++] = tomatu[i];
			}
		}
		int[] mikakosi = new int[N];
		for (int i = 0; i < N; i++) {
			mikakosi[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			int kugyu = sumipe(tomatu, yukinnko, A[i]);
			mikakosi[kugyu] = 1;
		}
		int emirinn = 0;
		for (int i = 0; i < yukinnko; i++) {
			if (mikakosi[i]) emirinn++;
		}
		System.out.println(emirinn);
	}

	public static int sumipe(int[] tomatu, int yukinnko, int hayaminn) {
		int satorina = 0, zaasan = yukinnko - 1;
		while (satorina <= zaasan) {
			int yukati = satorina + (zaasan - satorina) / 2;
			if (tomatu[yukati] == hayaminn) return yukati;
			else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
			else zaasan = yukati - 1;
		}
		return 114513;
	}
}

