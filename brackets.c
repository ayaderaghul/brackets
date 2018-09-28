#include "brackets.h"

void ft_putchar(char c)
{
  write(1,&c,1);
}

int length(char *str)
{
  int i;
  i = 0;
  while (str[i])
    ++i;
  return i;
}

int open_bracket(char c)
{
  if (c == '(')
    return 1;
  if (c == '[')
    return 2;
  if (c == '{')
    return 3;
  return 0;
}

int close_bracket(char c)
{
  if (c == ')')
    return 1;
  if (c == ']')
    return 2;
  if (c == '}')
    return 3;
  return 0;
}

int correct(char *str)
{
  int l = length(str);
  if (l == 0)
    return 1;
  int array[l];
  int i;
  i = 0;
  int j = 0;
  while (str[i])
    {
      if (open_bracket(str[i]))
	{
	  array[j] = open_bracket(str[i]);
	  ++j;
	}
      if (close_bracket(str[i]))
	{
	  if (array[j - 1] != close_bracket(str[i]))
	    return 0;
	  else
	      array[j--] = 0;
	}
      ++i;
    }
  return 1;
}

int main(int av, char **ac)
{
  if (av == 1)
    ft_putchar('\n');
  int i;
  i = 1;
  while (i < av)
    {
      if (correct(ac[i]))
	write(1, "OK\n", 3);
      else
	write(1, "Error\n", 6);
      ++i;
    }
  return 0;
}
