
import java.util.Scanner;

public class s784517449{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] A = new int[n];
    for(int i=0; i<n; i++) {
      A[i] = sc.nextInt();
    }
    int q = sc.nextInt();
    int sum = 0;
    for(int i=0;i<q;i++) {
      int k = sc.nextInt();
      int left = 0;
      int right = n;
      while(left < right) {
        int mid = (left + right) / 2;
        if(k == A[mid]) {
          sum++;
          break;
        }
        if(k > A[mid]) left = mid + 1;
        else if(k < A[mid]) right = mid;
      }
    }
    System.out.println(sum);
  }
}
