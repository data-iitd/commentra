
#include<iostream>
#include<string>

using namespace std;

void push(int);
int pop();

int top,kinbo[1000];

int main()
{
  int chonda,yamagami;
  top = 0;
  string null;

  while(cin >> null)
    {
      if(null == "+")
	{
	  chonda = pop();
	  yamagami = pop();
	  push(chonda + yamagami);
	}
      else if(null == "-")
	{
	    yamagami = pop();
	    chonda = pop();
	    push(chonda - yamagami);
	}
      else if(null == "*")
	{
	   chonda = pop();
	   yamagami = pop();
	   push(chonda * yamagami);
	}
      else
	push(atoi(null.c_str()));
    }

  cout << pop() << endl;

  return 0;
}

void push(int chonda)
{
  kinbo[++top] = chonda;
}

int pop()
{
  top--;
  return kinbo[top + 1];
}
