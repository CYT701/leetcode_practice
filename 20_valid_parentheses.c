#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool isValid(char *s)
{
	bool open_l = false;  
	bool open_m = false; 
	bool open_b = false;
	int br_l = 0;
	int br_m = 0;
	int br_b = 0;
	int i = 0;
	while(s[i] != '\0')
	{
		switch(s[i])
		{
			case '(':
				br_l = i+1;
				//open_l = true;
				break;
			case '[':
				br_m = i+1;
				//open_m = true;
				break;
			case '{':
				br_b = i+1;
				//open_b = true;
				break;
			case ')':
                open_l = false;
				//if((open_b == true && br_b > br_l) || (open_m == true && br_m > br_l))
				if(br_b > br_l && br_m > br_l)
					return false;
				br_l = 0;
                break;
			case ']':
                open_m = false;
				//if((open_l == true && br_l > br_m)|| (open_b == true && br_b > br_m))
                if(br_l > br_m || br_b > br_m)
				    return false;
                br_m = 0;
				break;
			case '}':
                open_b = false;
				//if((open_l == true && br_l > br_b) || (open_m == true && br_m > br_b))
                if(br_l > br_b || br_m > br_b)    
					return false;
				br_b = 0;
                break;
		}
		i++;
	}
	//if(open_l == false && open_m == false && open_b == false)
	if(br_l == 0 && br_m == 0 && br_b == 0)	
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
	char *input4 = "{[()]}(){[]}[]";
    if(isValid(input4))
        printf("true\n");
    else
        printf("false\n");
	return 0;
}
