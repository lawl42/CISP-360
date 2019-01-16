#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int addition(int num1, int num2)
{
	int result = 0;

	switch (num2)
	{
	case 2:
		result = num1 | num2;
		break;
	case 4:
		result = num1 | num2;
		break;
	case 8:
		result = num1 | num2;
		break;
	case 16:
		result = num1 | num2;
		break;
	case 32:
		result = num1 | num2;
		break;
	case 64:
		result = num1 | num2;
		break;
	default:
		break;
	}
	return result;
}

int main(int argc, char ** argv)
{
	if (argc == 4)
	{
		int result = 0, num1 = atoi(argv[1]), num2 = atoi(argv[3]);
		char op = argv[2][0];
		bool answered = true;

		switch (op)
		{
		case '+':
			if (!(num1 % 2) && !(num2 % 2))
			{
				if (num1 == num2)
				{
					result = num1 << 1;
					break;
				}
				switch (num1)
				{
					case 2:
						if ((num2 % 2) == 0)
							result = addition(num1, num2);
						break;
					case 4:
						if ((num2 % 2) == 0)
							result = addition(num1, num2);
						break;
					case 8:
						if ((num2 % 2) == 0)
							result = addition(num1, num2);
						break;
					case 16:
						if ((num2 % 2) == 0)
							result = addition(num1, num2);
						break;
					case 32:
						if ((num2 % 2) == 0)
							result = addition(num1, num2);
						break;
					case 64:
						if ((num2 % 2) == 0)
							result = addition(num1, num2);
						break;
					default:
						break;
				}
			}
			else
				result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			if (!(num1 % 2))
				switch (num1)
			{
				case 2:
					result = num2 << 1;
					break;
				case 4:
					result = num2 << 2;
					break;
				case 8:
					result = num2 << 3;
					break;
				case 16:
					result = num2 << 4;
					break;
				case 32:
					result = num2 << 5;
					break;
				case 64:
					result = num2 << 6;
					break;
				default:
					break;
			}
			else if ((num2 % 2) == 0)
				switch (num2)
			{
				case 2:
					result = num1 << 1;
					break;
				case 4:
					result = num1 << 2;
					break;
				case 8:
					result = num1 << 3;
					break;
				case 16:
					result = num1 << 4;
					break;
				case 32:
					result = num1 << 5;
					break;
				case 64:
					result = num1 << 6;
					break;
				default:
					break;
			}
			else
				result = num1 * num2;
			break;
		case '/':
			if (!num2)
			{
				printf("Can't divide by 0\n");
				answered = false;
			}
			else
			if ((num2 % 2) == 0)
				switch (num2)
			{
				case 2:
					result = num1 >> 1;
					break;
				case 4:
					result = num1 >> 2;
					break;
				case 8:
					result = num1 >> 3;
					break;
				case 16:
					result = num1 >> 4;
					break;
				case 32:
					result = num1 >> 5;
					break;
				case 64:
					result = num1 >> 6;
					break;
				default:
					break;
			}

			else
				result = num1 / num2;
			break;
		case '%':
			result = num1 % num2;
			break;
		default:
			answered = false;
			printf("invalid operator\n");
			break;
		}
		if (answered)
			printf("%d %c %d = %d\n", num1, op, num2, result);
	}
	else
		printf("Simple Calculator\nUsage: <value1> <operator> <value2>\n");
}