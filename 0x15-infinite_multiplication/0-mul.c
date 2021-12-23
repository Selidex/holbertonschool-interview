#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);

/**
 * partrim - parses a string confirming it is all ints and trims leading 0s
 * @str: the string being parsed and trimmed
 * Return: void, no return
 */
char *partrim(char *str)
{
	int i, offset = 0;
	int zero = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '0' && zero == 0)
			offset++;
		else
			zero = 1;
		if (str[i] < 48 || str[i] > 57)
		{
			printf("Error\n");
			exit(98);
		}
	}
	return (str + offset);
}



/**
 * len - returns teh length of a given string
 * @str: the string
 * Return: the lenght of the string
 */
int len(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{};
	return (i);
}

/**
 * mul - multiplies two potentially infinite long numbers
 * @num1: the first number
 * @num2: the second number
 * Return: void, no return
 */

void mul(char *num1, char *num2)
{
	int *total, i, j, m1, m2, tmp;

	total = malloc(sizeof(int) * (len(num1) + len(num2)));
	if (total == NULL)
		exit(98);
	for (i = 0; i < (len(num1) + len(num2)); i++)
		total[i] = 0;
	for (i = len(num1) - 1; i >= 0; i--)
	{
		for (j = len(num2) - 1; j >= 0; j--)
		{
			m1 = num1[i] - '0';
			m2 = num2[j] - '0';
			tmp = m1 * m2;
			total[i + j + 1] += tmp;
		}
	}
	for (i = len(num1) + len(num2) - 1; i > 0; i--)
	{
		m1 = total[i] % 10;
		m2 = total[i] / 10;
		total[i] = m1;
		total[i - 1] += m2;
	}
	for (i = 0; i < (len(num1) + len(num2)); i++)
	{
		if (i == 0 && total[0] == 0)
			continue;
		else
			printf("%d", total[i]);
	}
	printf("\n");
}

/**
 * main - the main program, recieves the argc/argv
 * @argc: number of arguments passed to program
 * @argv: the list of arguments
 * Return: void, no return
 */

int main(int argc, char *argv[])
{
	char *num1, *num2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = partrim(argv[1]);
	num2 = partrim(argv[2]);
	if (len(num1) == 0 || len(num2) == 0)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	mul(num1, num2);
	return (0);
}
