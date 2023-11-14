#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/* custom putchar function */
int _putchar(char c);
/* Custom function to print number*/
int print_number(int num);
/* Main printf function */
int _printf(const char *format, ...);
int print_pointer(void *ptr);
int print_non_printable(char c);
void string_handler(char *str, int *count);
#endif
