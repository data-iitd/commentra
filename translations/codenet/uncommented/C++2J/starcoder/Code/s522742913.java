
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String source = in.next();

		if(source.length() > 10 || source.length() < 1)
		{
			return -1;
		}

		int max_i = (int) Math.pow(2, source.length() - 1);

		double sum = 0;

		for (int i = 0; i < max_i; ++i)
		{
			BitSet plus = new BitSet(100);
			plus.set(i);

			double number = 0;

			String working = source;
			while(plus.anySet())
			{
				int i = 0;
				while(!plus.get(i)) ++i;
				sum += Double.parseDouble(working.substring(0, i + 1));
				plus.clear(i);
				working = working.substring(i + 1);
			}
			sum += Double.parseDouble(working);
		}

		System.out.printf("%.0f", sum);
	}
}

