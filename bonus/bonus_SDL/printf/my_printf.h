/*
** ETNA PROJECT, 16/01/2019 by delapo_a
** my_printf
** File description:
**      printf but better
*/

#ifndef __MY_PRINTF__
#define __MY_PRINTF__

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int my_strlen(char *str);
int my_nbrlen(int n);
int my_putnbr_base(int nbr, char *base);
int my_sprintf(char *str, const char *format, ...);
int my_printf(const char*, ...);
int my_putchar(char c);
int my_putnbr(int n);
int my_putstr(char *str);
int my_putnbr_unsigned(unsigned int n);
int my_putnbr_unsigned_print(va_list lst);
int my_putnbr_print(va_list lst);
int my_putchar_print(va_list lst);
int my_putstr_print(va_list lst);
int my_putnbr_base_print_min (va_list lst);
int my_putnbr_base_print_maj (va_list lst);
int my_putnbr_base_print_octal (va_list lst);
int my_pourcent_print(va_list lst);
void my_pourcent(char n);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char *src);


typedef int (*fptr_t)(va_list);
typedef struct wow_s {
	char argument;
	fptr_t fptr;
} wow_t;

#endif