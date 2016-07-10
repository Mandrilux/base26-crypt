
#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

		/* strtoword.c */

int		 count_words(char *str, char decoup);
int		 wordlen(char *str, char decoup);
char*		 complete_line(char *str, int nb, char decoup);
char		 **small_tab(char *str);
char		 **strtowordtab(char *str, char decoup);

		/* error.c */

int		 return_error(char *error, int flag);

		/* str.c */

char		 *epur_str(char *str);
void		 adjust_str(char *str);

		/* main.c */

int		 main(int argc, char **argv);
int		 base_26(char *str);
int		 *encode(char *str);
int		 get_indice(char c);
void		 somme(int *tab, int len);

#endif /* DATA_H_ */
