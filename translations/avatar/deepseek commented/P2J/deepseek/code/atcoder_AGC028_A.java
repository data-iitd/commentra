import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        String S = scanner.next();
        String T = scanner.next();
        
        char[] list_S = S.toCharArray();
        char[] list_T = T.toCharArray();
        
        int[] Number_i = new int[N];
        for (int i = 0; i < N; i++) {
            Number_i[i] = i;
        }
        
        double[] Number_iMN = new double[N];
        for (int i = 0; i < N; i++) {
            Number_iMN[i] = i * (double)M / N;
        }
        
        int[] Number_j = new int[M];
        for (int j = 0; j < M; j++) {
            Number_j[j] = j;
        }
        
        java.util.Set<Integer> Kaburi_j = new java.util.HashSet<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (Number_iMN[i] == j) {
                    Kaburi_j.add(j);
                }
            }
        }
        
        java.util.List<Integer> Kaburi_i = new java.util.ArrayList<>();
        for (int j : Kaburi_j) {
            Kaburi_i.add((int)(j * (double)N / M));
        }
        
        int counter = 0;
        boolean Flag = false;
        int Kaburi_Size = Kaburi_i.size();
        
        while (counter < Kaburi_Size) {
            if (list_S[Kaburi_i.get(counter)] != list_T[counter]) {
                Flag = true;
                break;
            }
            counter++;
        }
        
        if (Flag) {
            System.out.println(-1);
        } else {
            int gcd = gcd(N, M);
            System.out.println((N * M) / gcd);
        }
    }
    
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
