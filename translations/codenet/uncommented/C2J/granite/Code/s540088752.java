
import java.util.Scanner;

public class s540088752{

   public static void main(String[] args) {
   
      Scanner sc = new Scanner(System.in);
   
      int N = sc.nextInt();
   
      int[] A = new int[N + 1];
      int[] B = new int[N];
      int i;
   
      for (i = 0; i < N + 1; i++) {
         A[i] = sc.nextInt();
      }
   
      for (i = 0; i < N; i++) {
         B[i] = sc.nextInt();
      }
   
      long ans = 0;
   
      for (i = 0; i < N; i++) {
      
         //site i
         if (A[i] >= B[i]) {
            ans = ans + B[i];
            A[i] = A[i] - B[i];
            B[i] = 0;
         }
         else {
            ans = ans + A[i];
            B[i] = B[i] - A[i];
            A[i] = 0;
         }
      
         //site i + 1
         if (A[i + 1] >= B[i]) {
            ans = ans + B[i];
            A[i + 1] = A[i + 1] - B[i];
            B[i] = 0;
         }
         else {
            ans = ans + A[i + 1];
            B[i] = B[i] - A[i + 1];
            A[i + 1] = 0;
         }
      }
   
      System.out.println(ans);
   
      //