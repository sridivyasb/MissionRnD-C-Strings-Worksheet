/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

  #include <stdio.h>

void reverse(char *str, int len);

void number_to_str(float number, char *str, int afterdecimal) {
	int intPart = (int)number;

	int i = 0;
	char sign = NULL;
	if (intPart < 0) {
		sign = '-';
		intPart *= -1;
	}
	while (intPart > 0) {
		str[i] = (intPart % 10) + '0';
		intPart = intPart / 10;
		i++;
	}
	if (sign == '-')
		str[i++] = '-';
	reverse(str, i);

	if (afterdecimal > 0) {
		str[i++] = '.';
		if (number < 0)
			number *= -1;

		float floatPart = number - (float)((int)number);
		for (int j = 0; j < afterdecimal; j++) {
			floatPart *= 10;
			str[i++] = ((int)floatPart % 10) + '0';
		}
	}
	str[i] = '\0';
}

void reverse(char *str, int len) {
	int temp;
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}