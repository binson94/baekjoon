#include<cstdio>
using namespace std;

int Bit = 0;

int main(void)
{
	int count;
	scanf("%d", &count);

	for(int i = 0;i < count;i++)
	{
		char cmd[6];
		int num;

		scanf("%s", cmd);

		if(cmd[0] == 'a')
			if(cmd[1] == 'd')
			{
				scanf("%d", &num);
				Bit |= (1 << num);
			}
			else
				Bit = (1 << 21) - 1;
		else if(cmd[0] == 'r')
		{
			scanf("%d", &num);
			Bit &= ~(1 << num);
		}
		else if(cmd[0] == 'c')
		{
			scanf("%d", &num);
			printf("%d\n", (Bit & (1 << num)) ? 1 : 0);
		}
		else if(cmd[0] == 't')
		{
			scanf("%d", &num);
			Bit ^= (1 << num);
		}
		else
			Bit = 0;

	}
}
