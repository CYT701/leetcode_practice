#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool isValid(char *s)
{
	int cnt_l = 0;
	int cnt_m = 0;
	int cnt_b = 0;
	int pos_l[5000] = {0};
	int pos_m[5000] = {0};
	int pos_b[5000] = {0};
	bool isL = false;
	bool isM = false;
	bool isB = false;
	int i = 0;
	while(s[i] != '\0')
	{
		switch(s[i])
		{
			case '(':
				cnt_l ++;
				pos_l[cnt_l] = i;
				break;
			case '[':
				cnt_m ++;
				pos_m[cnt_m] = i;
				break;
			case '{':
				cnt_b ++;
				pos_b[cnt_b] = i;
				break;
			case ')':
				if(cnt_l == 0 || pos_b[cnt_b] > pos_l[cnt_l] || pos_m[cnt_m] > pos_l[cnt_l])
					return false;	
				if(cnt_l > 0)
					cnt_l --;
				break;
			case ']':
                if(cnt_m == 0 || pos_l[cnt_l] > pos_m[cnt_m] || pos_b[cnt_b] > pos_m[cnt_m])
				    return false;
				if(cnt_m > 0)
					cnt_m --;
				break;
			case '}':
                if(cnt_b == 0 || pos_l[cnt_l] > pos_b[cnt_b] || pos_m[cnt_m] > pos_b[cnt_b])    
					return false;
				if(cnt_b > 0)
                    cnt_b --;
                break;
		}
		i++;
	}
	if(cnt_l == 0 && cnt_m == 0 && cnt_b == 0)	
		return true;
	return false;
}

int main()
{
	char *input1 = "()";//true
	if(isValid(input1))
        printf("true\n");
    else
        printf("false\n");
	char *input2 = "()[]{}";//true
	if(isValid(input2))
        printf("true\n");
    else
        printf("false\n");
	char *input3 = "(]";//false
	if(isValid(input3))
		printf("true\n");
	else
		printf("false\n");
	char *input4 = "(]";
    if(isValid(input4))
        printf("true\n");
    else
        printf("false\n");
	return 0;
}
