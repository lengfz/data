#include <stdio.h>
bool b = true;
int main()
{
	int m[1000] = {0},s[1000] = {0},d[1000]={0},len = 0;
	int n;
	scanf("%d",&n);
	for (int i = 0;i < n;i ++)
	{
		scanf("%d",&m[i]);
	}
	for (int i = 0;i < n;i ++)
	{
		for (int j = 0;j <= len;j ++)
		{
			b = true;
			if (m[i] == s[j])
			{
				b = false;
				break;
			}
		}
		if (b) s[len ++] = m[i];
	}
	for (int i = 0;i <= len;i ++)
	{
		for (int j = 0;j < n;j ++)
		{
			if (s[i] == m[j]) d[i] ++;
		}
	}
	int max = d[0];
	int k = 0;
	for (int i = 0;i <= len;i ++)
	{
		if (max == d[i])
		{
			if (s[k] > s[i])
			{
				max = s[i];
				k = i;
			}
		}
		else if (max < d[i])
		{
			max = s[i];
			k = i;
		}
	}
	printf("%d",s[k]);
	return 0;
}
