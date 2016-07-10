#include "data.h"

int     free_double_char(char **tab)
{
  int   i;

  if (tab == NULL)
    return (-1);
  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (1);
}
