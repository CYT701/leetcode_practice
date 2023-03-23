#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *longestCommonPrefix(char **strs, int strsSize){
    //char *strout = malloc(sizeof(char)*200);
    if(strlen(strs[0]) == 0)
        return strs[0];
    char *compare = strs[0];
    int count_length = 0;
    bool isCommon = true;
    for(int j = 0 ; j < strlen(strs[0]) ; j++){
        for(int i = 0 ; i < strsSize ; i++){
            if(compare[j] != strs[i][j])
			{
                isCommon = false;
                break;
			}
        }
        if(!isCommon)
            break;
        count_length ++;
    }
    char *strout = malloc(sizeof(char)*(count_length+1));
    for(int i = 0 ; i < count_length ; i++)
        strout[i] = compare[i];
    strout[count_length] = '\0' ;
    return strout;
} 

int main()
{
	
	char *strout = malloc(sizeof(char)*200);
	char *str0[3] = {"flower","flow","flight"};
	char **strs0 = str0;
	char *str1[3] = {"dog","racecar","car"};
	char **strs1 = str1;
	strout = longestCommonPrefix(strs0,3);
	printf("%s\n",strout);
	strout = longestCommonPrefix(strs1,3);
    printf("%s\n",strout);
	return 0 ;
}
