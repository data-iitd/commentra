
import java.util.Scanner;
 
public class s201528373{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int x = scanner.nextInt();
    int[] l = new int[n];
    for (int i = 0; i < n; i++) {
      l[i] = scanner.nextInt();
    }
    
    int tmpSum = 0;
    int rs = 0;
    for (int i = 0; i < n; i++) {
      tmpSum += l[i];
      if (i >= n) {
        rs = n;
        break;
      }
      if (tmpSum <= x) {
        rs = i + 2;
      } else if (tmpSum > x) {
        break;
      }
    }
    System.out.println(rs);
  }
}

