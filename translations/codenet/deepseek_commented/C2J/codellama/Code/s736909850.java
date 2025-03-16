
public class SheepAndWolves {
   public static void main(String[] args) {
      int sheep = 0;
      int wolf = 0;

      Scanner sc = new Scanner(System.in);
      sheep = sc.nextInt();
      wolf = sc.nextInt();

      if(wolf >= sheep) {
         System.out.println("unsafe");
      } else {
         System.out.println("safe");
      }
   }
}

