import java.util.Scanner;

public class Main {
  public static void binPrint(int x, int bits){
    for (int i=bits-1; i>=0; i--){
      System.out.print((x&(1<<i))?1:0);
    }
    System.out.println();
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();

    binPrint(a&b, 32);
    binPrint(a|b, 32);
    binPrint(a^b, 32);
  }
}

