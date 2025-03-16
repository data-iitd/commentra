import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 0; i < t; i++)
		{
			String line = sc.nextLine();
			HashMap<Character, Integer> bought_count = new HashMap<Character, Integer>();
			for(int j = 0; j < line.length(); j++)
			{
				if(bought_count.containsKey(line.charAt(j)))
				{
					int count = bought_count.get(line.charAt(j));
					bought_count.put(line.charAt(j), count + 1);
				}
				else
				{
					bought_count.put(line.charAt(j), 1);
				}
			}
			line = sc.nextLine();
			HashMap<Character, Integer> made_cout = new HashMap<Character, Integer>();
			for(int j = 0; j < line.length(); j++)
			{
				if(made_cout.containsKey(line.charAt(j)))
				{
					int count = made_cout.get(line.charAt(j));
					made_cout.put(line.charAt(j), count + 1);
				}
				else
				{
					made_cout.put(line.charAt(j), 1);
				}
			}
			int res = 0;
			for(char color : made_cout.keySet())
			{
				if(!bought_count.containsKey(color))
				{
					System.out.println(-1);
					return;
				}
				res += Math.min(bought_count.get(color), made_cout.get(color));
			}
			System.out.println(res);
		}
	}
}
