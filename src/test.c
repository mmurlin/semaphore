#include <stdio.h>

int main()
{
	for (char x = 0; x < 32; ++x)
	{
		printf("%i: %i	%c\n", x, ((((x&7)-1)>>1)-1), ((((x&7)-1)>>1)-1) ? 'y' : 'n');
	}
}
