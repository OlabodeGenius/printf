#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* EMTOLALAA'S PERSONAL FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* DECIDED TO USE THESE  SIZES FOR MY PERSONAL REASON */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op by emtolalaa
 * @fmt: The emtolalaa format.
 * @fn: The emtolalaa function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op for emto
 * @fmt: The emtolalaa format.
 * @fm_t: My personal emtolalaa  function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);

/* THESE ARE FUNCTIONS I WANT TO USE AND THERE ARE SEVERAL OF THEM*/

/* I would use these functions below  to print characters  and strings */
int print_char_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* I would use these functions to print numbers*/
int print_int_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa_emto(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* The one function to print non_printable characters */
int print_non_printable_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* I would print memory addresses using the function below */
int print_pointer_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* These unique functions are for specifiers */
int get_flags_emto(const char *format, int *i);
int get_width_emto(const char *format, int *i, va_list list);
int get_precision_emto(const char *format, int *i, va_list list);
int get_size_emto(const char *format, int *i);

/*To print every string in reverse, I would use the function below*/
int print_reverse_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* An added function to print rot13 string */
int print_rot13string_emto(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* These functions would take care of width handlers */
int handle_write_char_emto(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number_emto(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num_emto(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer_emto(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned_emto(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/* These are for my utils */
int is_printable_emto(char);
int append_hexa_code_emto(char, char[], int);
int is_digit_emto(char);

long int convert_size_number_emto(long int num, int size);
long int convert_size_unsgnd_emto(unsigned long int num, int size);
#endif
