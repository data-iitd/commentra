import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int T = in.nextInt();
        int[] A = new int[N];
        for(int i = 0; i < N; i++) A[i] = in.nextInt();
        int m = A[0];
        int[] B = new int[N];
        B[1] = A[1] - m;
        m = Math.min(m, A[1]);
        for(int i = 2; i < N; i++){
            B[i] = A[i] - m;
            m = Math.min(m, A[i]);
        }
        System.out.println(Arrays.stream(B).boxed().filter(x -> x == *max_element(B)).count());
    }
}
