#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/* custom putchar function */
int _putchar(char c);
/* Custom function to print number*/
void print_number(int num);
/* Main printf function */
int _printf(const char *format, ...);
#endif
