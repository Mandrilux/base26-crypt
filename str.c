
#include "data.h"

char	*epur_str(char *str)
{
  char	*rtn;
  int	i;
  int	j;

  if (str == NULL ||
      (rtn = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    return (NULL);
  memset(rtn, 0, strlen(str) + 1);
  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	rtn[j++] = str[i];
      else if (str[i] == ' ' || str[i] == '\t')
	{
	  if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != ' '
	      && str[i + 1] != '\t' && str[i + 1] != '\0')
	    rtn[j++] = ' ';
	}
      i++;
    }
  return (rtn);
}

void    adjust_str(char *str)
{
  int   i = -1;

  while (str[++i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] -= 32;
      else if (str[i] >= 'A' && str[i] <= 'Z');
      else
	str[i] = ' ';
    }
}
