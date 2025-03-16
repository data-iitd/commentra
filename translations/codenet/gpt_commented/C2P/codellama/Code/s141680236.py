#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

#define push(chonda) kinbo[++top] = chonda
#define pop() kinbo[top--]

int top, kinbo[MAX];

int main()
{
  int chonda, yamagami;
  top = 0;
  char null[100];

  while(scanf("%s", null) != EOF)
    {
      if(null[0] == '+')
	{
	  chonda = pop();
	  yamagami = pop();
	  push(chonda + yamagami);
	}
      else if(null[0] == '-')
	{
	  yamagami = pop();
	  chonda = pop();
	  push(chonda - yamagami);
	}
      else if(null[0] == '*')
	{
	  chonda = pop();
	  yamagami = pop();
	  push(chonda * yamagami);
	}
      else
	push(atoi(null));
    }

  printf("%d\n", pop());

  return 0;
}

