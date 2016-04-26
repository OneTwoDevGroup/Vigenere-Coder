#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "locale.h"
#define  N 32
int main()
{	
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	FILE *fp1 = fopen("input.txt", "r");
	FILE *fp2 = fopen("output.txt", "w");
	unsigned char code[100]="ËÈÌÎÍ", chbuf, c;
	int sizefile, sizecode, i, j;
	printf("enter a keyword\n");
	sizecode = strlen((const char*)code);
	fseek(fp1, 0, SEEK_END);
	sizefile = ftell(fp1);
	fseek(fp1, 0, SEEK_SET);
	i = 0;
	/*char alphabet[N] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char savealphabet[N] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	*/
	unsigned char alphabet[N] = { 'À','Á','Â','Ã','Ä','Å','Æ','Ç','È','É','Ê','Ë','Ì','Í','Î','Ï','Ð','Ñ','Ò','Ó','Ô','Õ','Ö','×','Ø','Ù','Ý','É','Û','Ü','Þ','ß' };
	unsigned char savealphabet[N]= { 'À','Á','Â','Ã','Ä','Å','Æ','Ç','È','É','Ê','Ë','Ì','Í','Î','Ï','Ð','Ñ','Ò','Ó','Ô','Õ','Ö','×','Ø','Ù','Ý','É','Û','Ü','Þ','ß' };
	unsigned char d[256][256];
	unsigned char newalphabet[N];
	c = N;
	for (i = 0; i < N; i++)
	{
		j = rand() % c;
		newalphabet[i] = alphabet[j];
		alphabet[j] = alphabet[c - 1];
		c--;
	}
	c = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{

			c = j + i;
			if (c > N - 1)
				c -= N;
			d[savealphabet[i]][savealphabet[j]] = newalphabet[c];
		}

	}

	i = 0; j = 0;
	while (sizefile)
	{
		if (j == 5)
		{
			fputc(' ', fp2);
			j = 0;
		}
		chbuf = fgetc(fp1);
		sizefile--;
		if (i == strlen((const char*) code))
			i -= strlen((const char*)code);
		if ((chbuf >191)&&(chbuf<224))
		{
			chbuf = d[code[i]][chbuf];
			i++;
			fputc(chbuf, fp2);
			j++;
		}
		if ((chbuf>223))
		{

			chbuf = d[code[i]][chbuf - 32];
			i++;
			fputc(chbuf, fp2);
			j++;
		}
	
	
	}
	return 0;
}
