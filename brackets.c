#include "brackets.h"

void ft_putchar(char c)
{
  write(1,&c,1);
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

int correct_pair(int i, char *str)
{
  int j;
  j = i + 1;
  while (str[j])
    {
      if (close_bracket(str[j]) == open_bracket(str[i]))
	return 1;
      ++j;
    }
  return 0;
}

int correct(char *str)
{
  int i;
  i = 0;
  while (str[i])
    {
      if (open_bracket(str[i]))
	{
	  if (!(correct_pair(i, str)))
	    return 0;
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
      if (correct(ac[i]) == 1)
	write(1, "OK\n", 3);
      else
	write(1, "Error\n", 6);
      ++i;
    }
  return 0;
}
