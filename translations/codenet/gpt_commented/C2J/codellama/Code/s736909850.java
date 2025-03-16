
public class SheepAndWolves {
   public static void main(String[] args) {
      // Declare variables to hold the number of sheep and wolves
      int sheep;
      int wolf;

      // Read the number of sheep and wolves from user input
      sheep = Integer.parseInt(args[0]);
      wolf = Integer.parseInt(args[1]);

      // Check if the number of wolves is greater than or equal to the number of sheep
      if (wolf >= sheep) {
         // If there are more wolves than sheep, it's unsafe
         System.out.println("unsafe");
      } else {
         // If there are fewer wolves than sheep, it's safe
         System.out.println("safe");
      }
   }
}

