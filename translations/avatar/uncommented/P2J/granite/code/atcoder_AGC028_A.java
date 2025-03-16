
import java.util.*;
import java.lang.*;
import java.io.*;
class atcoder_AGC028_A
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		String S = sc.next();
		String T = sc.next();
		char[] list_S = S.toCharArray();
		char[] list_T = T.toCharArray();
		int[] Number_i = new int[N];
		int[] Number_iMN = new int[N];
		int[] Number_j = new int[M];
		int[] Kaburi_j = new int[M];
		int[] Kaburi_i = new int[N];
		int counter = 0;
		int Flag = 0;
		int Kaburi_Size = 0;
		for ( int i = 0; i < N; i++ ) {
			Number_i[i] = i;
		}
		for ( int i = 0; i < N; i++ ) {
			Number_iMN[i] = ( int ) ( i * M / N );
		}
		for ( int j = 0; j < M; j++ ) {
			Number_j[j] = j;
		}
		for ( int j = 0; j < M; j++ ) {
			if ( Arrays.asList(Number_iMN).contains(Number_j[j]) ) {
				Kaburi_j[Kaburi_Size] = Number_j[j];
				Kaburi_Size++;
			}
		}
		for ( int j = 0; j < Kaburi_Size; j++ ) {
			Kaburi_i[j] = ( int ) ( Kaburi_j[j] * N / M );
		}
		while ( counter <= Kaburi_Size - 1 ) {
			if ( list_S[Kaburi_i[counter]] == list_T[Kaburi_j[counter]] ) {
				pass;
			} else {
				Flag = 1;
				break;
			}
			counter++;
		}
		if ( Flag == 1 ) {
			System.out.println(-1);
		} else {
			int gcd = gcd(N,M);
			System.out.println(N*M/gcd);
		}
	}
	public static int gcd ( int a, int b ) {
		while ( b > 0 ) {
			a = b;
			b = a % b;
		}
		return a;
	}
}
