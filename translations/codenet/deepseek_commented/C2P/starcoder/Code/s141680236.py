#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int top = 0;
int kinbo[MAX];

int main()
{
  int chonda, yamagami;
  char null[100];

  while(scanf("%s", null)!= EOF)
  {
    if(null[0] == '+')
    {
      yamagami = pop();
      chonda = pop();
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
      yamagami = pop();
      chonda = pop();
      push(chonda * yamagami);
    }
    else
    {
      push(atoi(null));
    }
  }

  printf("%d\n", pop());

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

