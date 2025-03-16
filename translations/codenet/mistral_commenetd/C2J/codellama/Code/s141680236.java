
import java.util.Scanner;

public class Main
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int top = 0;
    int[] kinbo = new int[1000];

    while(sc.hasNext())
      {
	String null = sc.next();
	if(null.charAt(0) == '+')
	  {
	    int chonda = kinbo[top--];
	    int yamagami = kinbo[top--];
	    kinbo[++top] = chonda + yamagami;
	  }
	else if(null.charAt(0) == '-')
	  {
	    int yamagami = kinbo[top--];
	    int chonda = kinbo[top--];
	    kinbo[++top] = chonda - yamagami;
	  }
	else if(null.charAt(0) == '*')
	  {
	    int chonda = kinbo[top--];
	    int yamagami = kinbo[top--];
	    kinbo[++top] = chonda * yamagami;
	  }
	else
	  kinbo[++top] = Integer.parseInt(null);
      }

    System.out.println(kinbo[top]);
  }
}

