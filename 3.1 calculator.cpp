#include<stdio.h>
main()
{  int option;
   int number1;
   int number2;   
    printf("CHOOSE YOUR OPTION\n");
	printf("1.addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.modulo\n");
	scanf("%d",&option);
    
	 switch (option)
	{
		case 1:
		{
			printf("Enter input 1 : ");
			scanf(" %d", &number1);
			printf("Enter input 2 : ");
			scanf(" %d", &number2);
			printf("Addition %d \n", number1 + number2);
			break;
		}
		case 2:
		{
			printf("Enter input 1  : ");
			scanf(" %d", &number1);
			printf("Enter input 2  : ");
			scanf(" %d", &number2);
			printf("Subtraction %d \n", number1 - number2);
			break;
		}
		case 3:
		{
			printf("Enter input 1 : ");
			scanf(" %d", &number1);
			printf("Enter input 2 : ");
			scanf(" %d", &number2);
			printf("Multiplication %d \n", number1 * number2);
			break;
		}
		case 4:
		{
			printf("Enter input 1 : ");
			scanf(" %d", &number1);
			printf("Enter input 2 : ");
			scanf(" %d", &number2);
			printf("Division %d \n", number1 / number2);
			break;
		}
		case 5:
		{
			printf("Enter input 1 : ");
			scanf(" %d", &number1);
			printf("Enter input 2 : ");
			scanf(" %d", &number2);
			printf("Division %d \n", number1 % number2);
			break;
		}
		default:
		{
			printf("wrong\n");
		}
	}
}
	