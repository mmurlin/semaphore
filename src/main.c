#include <stdio.h>

#define HEIGHT 4
#define WIDTH  8

char *T="IeJKLMaYQCE]jbZRskc[SldU^V\\X\\|/_<[<:90!\"$434-./2>]s";
char K[3][1000];
char *F;
char x;
char A;
char *M[2];
char *J;
char r[4];
char *g;
char Y;
char *Q;
char W;
char *k;
char q;
char D;

char remainingSemaphores;

void X()
{
	r[0] = ' ';
	r[1] = x + 1 + Y;
	r[2] = *Q + 2;
	r[3] = M[1-(x&1)][1];

	*g++ = ((((x&7)-1)>>1)-1) ? *r : r[x>>3];

	if (++x < r[0])
	{
		X();
	}
}

void E()
{
	if (!A)
	{
		x = 0;
		g = J;
		X();
	}

	x = 7 & (*T >> A * 3);
	J[(F[x]-W-x)^A*7] = Q[x&3] ^ A * M[0][2+(x&1)];
	g = J + ((x[k] - W) ^ A * 7) - A;

	T += A;
	g[0] = M[1][x&1];
	g[1] = M[0][x&1];

	if (A ^= 1)
	{
		E();
		J += W;
	}
}

void l()
{
	while (--q)
	{
		E();
	}
}

void parseInput()
{
	if (*J)
	{
		D = *J;

		if (D >= '0' && D <= '9' && (*g++=1),!(D-W&&D-9&&D-10&&D-13))
		{
			if (!*r)
			{
				*g++ = 0;
				*r = 1;
			}
		}

		if (D >= 'A' && D <= 'Z')
		{
			*r=0;
			*g++ = D - ('A'-2);
		}
		else if (D >= 'a' && D <= 'z')
		{
			*r = 0;
			*g++ = D - ('a'-2);
		}
		else if (D == '0')
		{
			*r = 0;
			*g++ = 12;
		}
		else if (D >= '1' && D <= '9')
		{
			*r = 0;
			*g++ = D - ('1'-2);
		}

		J++;
		parseInput();
	}
}

void writeSegmentChars(char row)
{
	char i = 0;

	for (char i = 0; i < WIDTH; ++i)
	{
		putchar(K[0][D * W +		// Relevant semaphore representation
					 row * WIDTH +	// Current row of representation
					 i]				// Current char on row
			);
	}
}

void writeRowSegments(char row)
{
	D = q[g];
	writeSegmentChars(row);

	putchar(' ');

	if (++q < (remainingSemaphores < WIDTH ? remainingSemaphores : WIDTH))
	{
		writeRowSegments(row);
	}
}

void writeRows(char row)
{
	q = 0;
	writeRowSegments(row);

	putchar('\n');

	if (++row < HEIGHT)
	{
		writeRows(row);
	}
}

void writeSemaphores()
{
	writeRows(0);
	putchar('\n');

	if (remainingSemaphores -= q)
	{
		g += q;
		writeSemaphores();
	}
}

void writeAsSemaphores(char input[80])
{
	J = input;

	g = K[2];
	parseInput();
	if (!r[0])
	{
		*g++ = 0;
	}
	r[0] = 1;

	remainingSemaphores = g - K[2];


	g = K[2];

	if (remainingSemaphores)
	{
		writeSemaphores();
	}
}

int main()
{
	A = 0;
	J = K[0];
	W = 32;
	Y = W - HEIGHT;
	q = Y;
	Q = T + q;
	M[1] = Q + HEIGHT;
	k = M[1] + 2;
	F = k + 7;
	M[0] = F + 7;
	l();

	r[0] = 1;

	// Everything until here is just initial setup.
	char input[80];
	while (1)
	{
		fgets(input, 80, stdin);
		writeAsSemaphores(input);
	}
}
