
import java.util.Scanner;

public class s736909850{
   public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      int sheep = scanner.nextInt();
      int wolf = scanner.nextInt();

      if (wolf >= sheep) {
         System.out.println("unsafe");
      } else {
         System.out.println("safe");
      }
   }
}
// END-OF-CODE