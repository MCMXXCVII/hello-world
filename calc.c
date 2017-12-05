#include <stdio.h>

int main(void)
{
float num1;
float num2;
char oper;
printf("Первое число: ");
scanf("%f",&num1);
printf("Второе число: ");
scanf("%f",&num2);
printf("Оператор ( + - * / ) ");
while((oper = getchar()) != EOF)
{
if (oper == '+')
{
printf("%6.2f\n",num1 + num2);
break;
}
else if (oper == '-')
{
printf("%6.2f\n",num1 - num2);
break;
}
else if (oper == '*')
{
printf("%6.2f\n",num1 * num2);
break;
}
else if (oper == '/')
{
if (num2 == 0)
{
printf("Ошибка деления на ноль!");
break;
}
else
{
printf("%6.2f\n",num1 / num2);
break;
}
}
}
return 0;
}
