
import java.util.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int chonda,yamagami;
    Stack<Integer> stack = new Stack<Integer>();

    while(sc.hasNext())
    {
      String null = sc.next();
      if(null.charAt(0) == '+')
      {
	chonda = stack.pop();
	yamagami = stack.pop();
	stack.push(chonda + yamagami);
      }
      else if(null.charAt(0) == '-')
      {
	yamagami = stack.pop();
	chonda = stack.pop();
	stack.push(chonda - yamagami);
      }
      else if(null.charAt(0) == '*')
      {
	chonda = stack.pop();
	yamagami = stack.pop();
	stack.push(chonda * yamagami);
      }
      else
	stack.push(Integer.parseInt(null));
    }

    System.out.println(stack.pop());
  }
}

