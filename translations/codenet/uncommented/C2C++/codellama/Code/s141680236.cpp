#include<iostream>
#include<string>

using namespace std;

int main()
{
  int chonda,yamagami;
  int top = 0;
  int kinbo[1000];

  string null;

  while(cin >> null)
    {
      if(null[0] == '+')
	{
	  chonda = kinbo[top--];
	  yamagami = kinbo[top--];
	  kinbo[++top] = chonda + yamagami;
	}
      else if(null[0] == '-')
	{
	    yamagami = kinbo[top--];
	    chonda = kinbo[top--];
	    kinbo[++top] = chonda - yamagami;
	}
      else if(null[0] == '*')
	{
	   chonda = kinbo[top--];
	   yamagami = kinbo[top--];
	   kinbo[++top] = chonda * yamagami;
	}
      else
	kinbo[++top] = atoi(null.c_str());
    }

  cout << kinbo[top--] << endl;

  return 0;
}

