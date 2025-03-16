
import java.util.*;
import java.io.*;

class s240627521 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[] A = new long[N];
    for(int i=0;i<N;++i) A[i] = sc.nextLong();
    Arrays.sort(A);
    int index = 0;
    long max = Long.MAX_VALUE;
    for(int i=1;i<N;++i) {
      if(max>Math.abs(A[N-1]-2*A[N-1-i])) {
        max = Math.abs(A[N-1]-2*A[N-1-i]);
        index = i;
      }
    }
    System.out.println(A[N-1]+" "+A[N-1-index]);
  }
}
