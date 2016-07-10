#include "data.h"

int	main(int argc, char **argv)
{
  char	*str = NULL;
  char	**word = NULL;
  int	i = -1;
  if (argc != 2)
    return (return_error("Usage : [str]", EXIT_FAILURE));
  adjust_str(argv[1]);
  if ((str = epur_str(argv[1])) == NULL)
    return (return_error("[-] ERROR MEMORY", EXIT_FAILURE));
  if ((word = strtowordtab(str, ' ')) == NULL)
    return (return_error("[-] ERROR MEMORY", EXIT_FAILURE));
  free(str);
  while (word[++i] != NULL)
    {
      if (base_26(word[i]) == -1)
	return (EXIT_FAILURE);
    }
  printf("\n");
  free(word);
  return (EXIT_SUCCESS);
}

int	base_26(char *str)
{
  int	len_tab_num = 0;
  int	*num = NULL;

  if ((num = encode(str)) == NULL)
    return (return_error("[-] ERROR MEMORY", -1));
  len_tab_num = strlen(str);
  free(str);
  somme(num, len_tab_num);
  free(num);
  return (1);
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

void	somme(int *tab, int len)
{
  int	i = -1;
  int	exp = len - 1;
  long long	total = 0;
  while (++i < len)
    {
      total += tab[i] * (pow(26.0, (double)exp));
      exp --;
    }
  printf("%lld ", total);
}
