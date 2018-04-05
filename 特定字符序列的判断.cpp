#include <stdio.h>
#include <string.h>
bool b = true;
int main()
{
	char s[30];
	int len,mark;
	scanf("%s",s);
	len = strlen(s);
	if (s[len - 1] != '#')
	{
		printf("no!");
		return 0;
	}
	else
	{
		mark = len / 2 - 1;
		for (int i = 0;i < mark;i ++)
		{
			if (s[i] != s[len - i - 2])
			{
				b = false;
				break;
			}
			
		} 
		if (b) printf("yes!");
		else printf("no!");
	}
	return 0;
}
