#include "stdio.h"
#include "string.h"
#define  N 26
int main()
{
	FILE *fp1 = fopen("input.txt", "r");
	FILE *fp2 = fopen("output.txt", "w");
	char code[100],chbuf,c;
	int sizefile,sizecode,i,j;
	printf("enter a keyword\n");
	sizecode = strlen(code);
	scanf("%s", code);
	fseek(fp1, 0, SEEK_END);
	sizefile = ftell(fp1);
	fseek(fp1, 0, SEEK_SET);
	i = 0;
	char alphabet [N] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char d[127][127];
	for (i = 0; i < N; i++)
	{	
		for (j = 0; j < N; j++)
		{

			c = j + i;
			if (c > N-1)
				c -= N;
			d[i+alphabet[0]][j + alphabet[0]] = alphabet[0] +c;
		}
			
	}

	i = 0;
	while (sizefile)
	{
		chbuf = fgetc(fp1);
		sizefile--;
		if (i == strlen(code))
			i -= strlen(code);
		if (chbuf >96)
		{
			chbuf = d[code[i]][chbuf];
			i++;
		}
		if ((chbuf>64)&&(chbuf<91))
		{

			chbuf = d[code[i]][chbuf+32];
			i++;
		}
		fputc(chbuf, fp2);
	}
	return 0;
}
	