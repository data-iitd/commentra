
import java.util.Scanner;

class s403900151 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n, r, p, c;
    int i, j, k, l;
    int[] a = new int[51];
    int[] b = new int[51];

    while (true) {
      n = sc.nextInt();
      r = sc.nextInt();
      if (n == 0 && r == 0)
        break;

      for (i = 0; i < n; i++)
        a[i] = i + 1;

      for (i = 0; i < r; i++) {
        p = sc.nextInt();
        c = sc.nextInt();

        //      printf("p=%d c=%d\n",p,c);

        for (j = 0; j < c; j++)
          b[j] = a[n - p - c + 1 + j];    
        for (j = 0; j < p - 1; j++)
          a[n - p - c + 1 + j] = a[n - p + j + 1];
        for (j = n - p - c + 1 + j, k = 0; k < c; j++, k++) {
          //printf("b[%2d] = %d\n",k,b[k]);
          a[j] = b[k];
        }

        /*
        for( j=0;j<n;j++)
          printf("%d\n",a[j]);
        printf("---\n");
        */

      }
      System.out.println(a[n - 1]);
    }
  }
}
