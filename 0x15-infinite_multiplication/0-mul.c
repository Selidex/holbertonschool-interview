#include <stdlib.h>
#include <stdio.h>

/**
 * partrim - parses a string confirming it is all ints and trims leading 0s
 * @str: the string being parsed and trimmed
 * Return: void, no return
 */
char* partrim(char *str)
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
	printf("num1: %s\nnum2: %s\n", num1, num2);
	return (0);
}
