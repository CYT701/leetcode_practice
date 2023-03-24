#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int reverse_str(int x)
{
    if(x / 1000000000 != 0 && x % 10 >2)
        return 0;
    bool isPositive = true;
    if(x < 0 && x > -2147483648)
    {
        isPositive = false;
        x = -x;
    }
    else if( x == -2147483648)
        return 0;
    int pow = 10;
    int num_of_digit = 1;
    while(x % pow != x && pow <= 100000000)
    {
        pow *= 10;
        num_of_digit ++; 
    }
    if(x % pow != x)
        num_of_digit ++;
    char *input_str = malloc(sizeof(char)* (num_of_digit+1));
    sprintf(input_str,"%d",x);
    char *out_str = malloc(sizeof(char) * (num_of_digit+1));
    for(int i = 0 ; i < num_of_digit ; i++)
    {
        out_str[i] = input_str[num_of_digit-1-i];
    }
    out_str[num_of_digit] = '\0';
    if(isPositive)
        return atoi(out_str) < 0 ? 0 : atoi(out_str);
    else 
        return -atoi(out_str) > 0 ? 0 : -atoi(out_str);
}

int reverse_math(int x)
{
	//if(x % 1000000000 != x && x % 10 >= 2)
	//	return 0;
	bool isPositive = true;
	if(x < 0)
	{
		isPositive = false;
		x = 0 - x;
	}
	int power_of_10 = 10;
	int num_of_digit = 1;
	int reverse_x = 0;
	bool isOverflow = false;
	/*while(x % power_of_10 != x)
	{
		power_of_10 *= 10;
		num_of_digit ++; 
	}*/
	for(int i = 1 ; i < 10 ; i++)
	{
		if(x % power_of_10 != x)
		{
			power_of_10 *= 10;
			num_of_digit ++;
		}
		else
		{
			isOverflow = false;
			break;
		}
		isOverflow = true;
	}
	if(isOverflow && x % 10 > 2)
		return 0;
	else
	{
		//return 0;
		int pow_of_10 = 1;
		for(int i = num_of_digit ; i >= 1 ; i--)
		{
			power_of_10 /= 10;
			reverse_x += (x / power_of_10) * pow_of_10;
			x -= (x / power_of_10) * power_of_10;	
			pow_of_10 *= 10;
		}
		return isPositive ? reverse_x : -reverse_x;
	}
	//return isPositive ? atoi(out_str) : -atoi(out_str);
}

int main()
{
	int x0 = 123;
	printf("%d\n",reverse_str(x0));
	int x1 = -123;
    printf("%d\n",reverse_str(x1));
	int x2 = 120;
    printf("%d\n",reverse_str(x2));
	int x3 = 1534236469;
	printf("%d\n",reverse_str(x3));
	return 0;
}
