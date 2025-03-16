
import java.util.*;

class s628392045 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] h = new int[n];
    int max = -1;
    int flag = 0;

    for(int i = 0;i < n;i++){
      h[i] = sc.nextInt();
      if(max < h[i]) max = h[i];

      if(max - h[i] >= 2) flag = 1;
    }

    if(flag == 1) System.out.println("No");

    else System.out.println("Yes");
  }
}
