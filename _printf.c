#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - creates a custom printf
 * @format: a formated input
 * @...: variable argument
 * Return: number of characters in format(on success)
*/
int _printf(const char *format, ...)
{
    int char_print = 0;
    va_list list_arg;
    if (format == NULL)
    {
        return (-1);
    }
    va_start(list_arg, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++; 
            if (*format == '\0')
            {
                break;
            }
            if (*format == '%')
            {
                write (1, format, 1);
                char_print++;
            }
            else if (*format == 'c')
            {
                char c = va_arg(list_arg, int);
                write (1, &c, 1);
                char_print++;
            } 
            else if (*format == 's')
            {
                char *word = va_arg(list_arg, char*);
                int word_len = 0;
                while (word[word_len] != '\0')
                {
                    word_len++;
                }
                //print the word then
                write (1, word, word_len);
                char_print += word_len;
            }
        }
        else
        {
            write(1, format, 1);
            char_print++;
        }
        format++;
    }
    va_end(list_arg);
    return char_print;
}

