
import java.util.*;

public class s798522572{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int T = sc.nextInt();
    int[] A = new int[N];
    for(int i = 0; i < N; i++) A[i] = sc.nextInt();
    int m = A[0];
    int[] B = new int[N];
    B[1] = A[1] - m;
    m = Math.min(m, A[1]);
    for(int i = 2; i < N; i++){
      B[i] = A[i] - m;
      m = Math.min(m, A[i]);
    }
    int max_value = Arrays.stream(B).max().getAsInt();
    int count = Arrays.stream(B).filter(x -> x == max_value).count();
    System.out.println(count);
  }
}
