#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int myAtoi(char *s)
{
	bool isNum = false;
	int count = 0;
	int firstchar = 0;
	for(int i = 0 ; s[i] != '\0' ; i++)
	{
		if(isNum)
		{
			if((s[i] - '0' <= 9 && s[i] - '0' >= 0)||s[i] == '-')
				count++;
			else
				break;
		}
		else//!isNum
		{
			if((s[i] - '0' <= 9 && s[i] - '0' >= 0)||s[i] == '-')
			{
				count++;
				firstchar = i;
				isNum = true;
			}
		}
	}
	char *outstr = malloc(sizeof(char)*(count+1));
	for(int i = 0 ; i < count ; i++)
		outstr[i] = s[firstchar + i]; 
	outstr[count] = '\0';
	return atoi(outstr);
}

int main()
{
	char *s0 = "42";
	printf("%d\n",myAtoi(s0));
	char *s1 = "   -42";
    printf("%d\n",myAtoi(s1));
	char *s2 = "4193 with words";
    printf("%d\n",myAtoi(s2));
	return 0;
}
