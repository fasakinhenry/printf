#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* custom putchar function */
int _putchar(char c);
/* Custom function to print number*/
int print_number(int num, int print_sign, int print_hash);
/* Main printf function */
int _printf(const char *format, ...);
int print_pointer(void *ptr);
int print_non_printable(char c);
void string_handler(char *str, int *count);
int print_reverse(const char *str);
#endif
