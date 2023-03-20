#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize){
	char *strout = malloc(sizeof(char)*200);
	//char out[200] = {'\0'};
	//char *strout = out;
	char *compare = strs[0];
	for(int j = 0 ; j < 200 ; j++){
		for(int i = 0 ; i < strsSize ; i++){
			if(compare[j] != strs[i][j])
				return strout;
		}
		strout[j] = compare[j];
		//printf("%c\n",strout[j]);
	}
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
