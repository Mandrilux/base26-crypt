#include "data.h"

int	main(int argc, char **argv)
{
  char	*str = NULL;
  int	*num = NULL;
  int	len_tab_num = 0;

  if (argc != 2)
    return (return_error("Usage : [str]", EXIT_FAILURE));
  adjust_str(argv[1]);
  if ((str = epur_str(argv[1])) == NULL)
    return (return_error("[-] ERROR MEMORY", EXIT_FAILURE));
  if ((num = encode(str)) == NULL)
    return (return_error("[-] ERROR MEMORY", EXIT_FAILURE));
  len_tab_num = strlen(str);
  free(str);
  somme(num, len_tab_num);
  return (EXIT_SUCCESS);
}

void	adjust_str(char *str)
{
  int	i = -1;

  while (str[++i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] -= 32;
      else if (str[i] >= 'A' && str[i] <= 'Z');
      else
	str[i] = ' ';
    }
}

int	*encode(char *str)
{
  int	len = strlen(str);
  int   *num = NULL;
  int	i = -1;

  if ((num = calloc(len, sizeof(int))) == NULL)
    return (NULL);
  while (str[++i] != '\0')
      num[i] = get_indice(str[i]);
  return (num);
}

int	get_indice(char	c)
{
  char	alpha[27] = {0};
  int	i = -1;
  int	s = 'A';

  while (++i < 26)
    alpha[i] = s + i;
  i = -1;
  while (alpha[++i] != '\0')
    {
      if (alpha[i] == c)
	return (i);
    }
  return (-1);
}

void	somme(int *tab, int len)
{
  int	i = -1;
  int	exp = len - 1;
  int	total = 0;
  while (++i < len)
    {
      total += tab[i] * (pow(2.0, (double)exp));
      exp --;
    }
  printf("%d\n", total);
}
