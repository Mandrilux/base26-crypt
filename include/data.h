
#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

		/* error.c */

int		 return_error(char *error, int flag);

		/* str.c */

char		 *epur_str(char *str);
void		 adjust_str(char *str);

		/* main.c */

int		 main(int argc, char **argv);
int		 *encode(char *str);
int		 get_indice(char c);
void		 somme(int *tab, int len);

#endif /* DATA_H_ */
