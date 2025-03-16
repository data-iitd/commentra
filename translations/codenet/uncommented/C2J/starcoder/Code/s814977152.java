import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		int[] tomatu = new int[N];
		int yukinnko = 1;
		for (int inorinn = 0; inorinn < N; inorinn++) {
			A[inorinn] = sc.nextInt();
			tomatu[inorinn] = A[inorinn];
		}
		Arrays.sort(tomatu);
		for (int inorinn = 1; inorinn < N; inorinn++) {
			if (tomatu[inorinn]!= tomatu[yukinnko - 1]) {
				tomatu[yukinnko++] = tomatu[inorinn];
			}
		}
		int[] mikakosi = new int[yukinnko];
		for (int inorinn = 0; inorinn < N; inorinn++) {
			int kugyu = sumipe(A[inorinn], tomatu, yukinnko);
			mikakosi[kugyu] =!mikakosi[kugyu];
		}
		int emirinn = 0;
		for (int inorinn = 0; inorinn < yukinnko; inorinn++) {
			if (mikakosi[inorinn]) emirinn++;
		}
		System.out.println(emirinn);
	}

	public static int sumipe(int hayaminn, int[] tomatu, int yukinnko) {
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

