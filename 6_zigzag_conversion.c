#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *convert(char *s,int numRows)
{

	int row_pos = 0;//count straight
	int col_pos = 0;//count horizon
	bool goForward = true;
	int arr[numRows][strlen(s)];
	if(numRows == 1)
		return s;
	else if(numRows > 1){
		for(int i = 0 ; i < numRows ; i++)//initialize arr with -1
		{
        	for(int j =0;j<strlen(s);j++)
            	arr[i][j] = -1;
    	}
		for(int i = 0 ; i < strlen(s) ; i++)//put index of s[] to arr
		{
			if(goForward)
			{
				arr[row_pos][col_pos] = i;
				row_pos ++;
				if(row_pos == numRows)
				{
					goForward = false;
					row_pos --;
				}
			}
			else
			{
				row_pos --;
				col_pos ++;
				arr[row_pos][col_pos] = i;
				if(row_pos == 0)
				{
					goForward = true;
					row_pos++;
				}
			}
		}
	}
	/*for(int i = 0 ; i < numRows ; i++)//check if init success
	{
		for(int j =0;j<strlen(s);j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}*/
	char *zigzag = malloc(sizeof(char) * strlen(s));
	int count = 0;
	for(int i = 0 ; i < numRows ; i++)
	{
		for(int j = 0 ; j < strlen(s) ; j++)
		{
			if(arr[i][j] != -1 && count < strlen(s))
			{
				zigzag[count] = s[arr[i][j]];
				count ++;
			}
			else if(count >= strlen(s))
				break;
		}
		if(count >= strlen(s))
			break;
	}
	return zigzag;
}

int main()
{
	char *s = "PAYPALISHIRING";
	printf("%s\n",convert(s,3));
	printf("%s\n",convert(s,4));
	char *s1 = "AB";
	printf("%s\n",convert(s1,1));
	return 0;
}
