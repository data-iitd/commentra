import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[] A = new long[N];
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextLong();
    }

    long answer = 0;
    // Calculate the maximum absolute difference between any two elements in the array
    for (int i = 0; i < N - 1; i++) {
      for (int j = i + 1; j < N; j++) {
        long diff = Math.abs(A[i] - A[j]);
        answer = Math.max(answer, diff);
      }
    }
    // Output the result
    System.out.println(answer);
  }
}

