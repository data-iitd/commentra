
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		int[] tomatu = new int[N];
		int[] mikakosi = new int[N];
		int yukinnko = 1;
		int emirinn = 0;
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
		for (int i = 0; i < N; i++) {
			mikakosi[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			int kugyu = sumipe(A[i], tomatu);
			mikakosi[kugyu] = 1;
		}
		for (int i = 0; i < yukinnko; i++) {
			if (mikakosi[i] == 1) emirinn++;
		}
		System.out.println(emirinn);
	}
	public static int sumipe(int hayaminn, int[] tomatu) {
		int satorina = 0, zaasan = tomatu.length - 1;
		while (satorina <= zaasan) {
			int yukati = satorina + (zaasan - satorina) / 2;
			if (tomatu[yukati] == hayaminn) return yukati;
			else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
			else zaasan = yukati - 1;
		}
		return -1;
	}
}

