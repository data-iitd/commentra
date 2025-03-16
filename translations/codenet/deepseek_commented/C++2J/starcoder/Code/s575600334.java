import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int a = in.nextInt();
    int b = in.nextInt();

    // Print the binary AND of a and b
    System.out.println(Integer.toBinaryString(a&b));
    // Print the binary OR of a and b
    System.out.println(Integer.toBinaryString(a|b));
    // Print the binary XOR of a and b
    System.out.println(Integer.toBinaryString(a^b));
  }
}
