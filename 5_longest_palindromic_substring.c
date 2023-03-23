#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*char *longestPalindrome(char *s)
{
	if(strlen(s) == 1)
		return s;
	bool isPalindrome = false;
	char *str = malloc(sizeof(char) * strlen(s)); 
	for(int i = 0 ; s[i] != '\0' ; i++)
	{
		for(int j = strlen(s) - 1 ; j >= i ; j--)
		{
			if(i != j && s[i] == s[j])
			{
				int count = 0;
				for(int k = i ; k <= (i+j)/2 ; k++)
        		{
					isPalindrome = true;
            		if(s[k] != s[j-count])
            		{	   
                		isPalindrome = false;
                		break;
            		}
					count++;
       			}
			}
			if(isPalindrome)
            {
                for(int l = 0 ; i+l <= j ; l++)
                {
                    str[l] = s[i+l];
                }
                return str;
            }
		}
	}
	str[0] = s[0];
	return str;
}*/

char *longestPalindrome(char *s)
{
    if(strlen(s) == 1)
        return s;
    bool isPalindrome = false;
    int outlength = 0;
    int cur_i = 0;
    int cur_j = 0;
    //char *str = malloc(sizeof(char) * strlen(s));
    for(int i = 0 ; s[i] != '\0' ; i++)
    {
        isPalindrome = false;
        for(int j = strlen(s) - 1 ; j >= i ; j--)
        {
            if(i != j && s[i] == s[j])
            {
                int count = 0;
                for(int k = i ; k <= (i+j)/2 ; k++)
                {
                    isPalindrome = true;
                    if(s[k] != s[j-count])
                    {
                        isPalindrome = false;
                        break;
                    }
                    count++;
                }
            }
            if(isPalindrome)
            {
                if(outlength < j - i + 2)
                {
                    outlength = j - i + 2;
                    cur_i = i;
                    cur_j = j;
                }
            }
        }
    }
    if(outlength == 0)
    {
        char *str = malloc(sizeof(char)*2);
        str[0] = s[0];
        str[1] = '\0';
        return str;
    }
    else
    {
        char *str = malloc(sizeof(char) * outlength);
        for(int l = 0 ; cur_i + l <= cur_j ; l++)
        {
            str[l] = s[cur_i+l];
        }
        str[cur_j-cur_i+1] = '\0';
        return str;
    }    
}


int main()
{              
	char *s1 = "babad";
	printf("%s\n",longestPalindrome(s1));
	char *s2 = "cbbd";
	printf("%s\n",longestPalindrome(s2));
	char *s3 = "aacabdkacaa";
    printf("%s\n",longestPalindrome(s3));
	char *s4 = "bbcbbd";
    printf("%s\n",longestPalindrome(s4));
	char *s5 = "aaaaa";
    printf("%s\n",longestPalindrome(s5));
	return 0;
}
