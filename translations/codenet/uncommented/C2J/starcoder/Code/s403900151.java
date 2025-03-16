
import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while( true ){
      int n = sc.nextInt();
      int r = sc.nextInt();
      if( n==0 && r==0 )
	break;
      int[] a = new int[n];
      int[] b = new int[n];
      for( int i=0;i<n;i++)
	a[i]=i+1;
      for( int i=0;i<r;i++){
	int p = sc.nextInt();
	int c = sc.nextInt();
	for( int j=0;j<c;j++)
	  b[j] = a[n-p-c+1+j];    
	for( int j=0;j<p-1;j++)
	  a[n-p-c+1+j] = a[n-p+j+1];
	for( int j=n-p-c+1+j,k=0;k<c;j++,k++){
	  a[j] = b[k];
	}
      }
      System.out.println(a[n-1]);
    }
  }
}
