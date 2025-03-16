import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int K = in.nextInt();
    int X = in.nextInt();
    for(int i = X - K + 1; i <= X + K - 1; i++){
      System.out.print(i);
      if(i < X + K - 1) System.out.print(" ");
    }
    System.out.println();
  }
}
