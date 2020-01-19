#include <stdio.h>

#define HEIGHT		4
#define WIDTH		8
#define R_LEN		32
#define CHARSET_LEN	28

const char skeleton[32] =	"        "
							"   ()   "
							"   ^^   "
							"   ][   ";

char *T="IeJKLMaYQCE]jbZRskc[SldU^V\\X\\|/_<[<:90!\"$434-./2>]s";
char K[3][1000];
char *F;
char x;
char A;
char *M[2];
char *J;
char r[4];
char *g;
char *Q;
char *k;
char q;
char D;

char remainingSemaphores;

void generateSkeleton(char *semaphores)
{
	// TODO I feel bad about removing this, I don't want to change how the program fundamentally works to this degree. I will probably rewrite this function.
	// x = 0;
	// g = J;
	// while (x < R_LEN)
	// {
	//	r[0] = ' ';
	//	r[1] = x + 1 + CHARSET_LEN;
	//	printf("%c	", r[1]);
	//	r[2] = *Q + 2;
	//	r[3] = M[1-(x&1)][1];

	//	printf("%i:	%i\n", x, (x&7));
	//	*g++ = ((((x&7)-1)>>1)-1) ? ' ' : r[x>>3];
	//	++x;
	// }

	char *s = semaphores;
	for (char i = 0; i < R_LEN; ++i)
	{
		*s++ = skeleton[i];
	}
}

void placeFlags()
{
	if (!A)
	{
		generateSkeleton(J);
	}

	x = 7 & (*T >> A * 3);
	J[(F[x]-R_LEN-x)^A*7] = Q[x&3] ^ A * M[0][2+(x&1)];
	g = J + ((x[k] - R_LEN) ^ A * 7) - A;

	T += A;
	g[0] = M[1][x&1];
	g[1] = M[0][x&1];

	if (A ^= 1)
	{
		placeFlags();
		J += R_LEN;
	}
}

void initialiseRepresentations()
{
	for (char i = CHARSET_LEN; i > 0; --i)
	{
		placeFlags();
	}
}

void parseInput()
{
	while (*J)
	{
		D = *J;

		// TODO
		if (D >= '0' && D <= '9' && (*g++=1),!(D-R_LEN&&D-9&&D-10&&D-13))
		{
			if (!*r)
			{
				*g++ = 0;
				*r = 1;
			}
		}

		if (D >= 'A' && D <= 'Z')
		{
			*r = 0;
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
	}
}

void writeSegmentChars(char row)
{
	for (char i = 0; i < WIDTH; ++i)
	{
		putchar(K[0][D * R_LEN +	// Relevant semaphore representation
					 row * WIDTH +	// Current row of representation
					 i]				// Current char on row
			);
	}
}

void writeRowSegments(char row)
{
	while (q < (remainingSemaphores < WIDTH ? remainingSemaphores : WIDTH))
	{
		D = g[q];
		writeSegmentChars(row);

		putchar(' ');
		++q;
	}
}

void writeRows(char row)
{
	while (row < HEIGHT)
	{
		q = 0;
		writeRowSegments(row);

		putchar('\n');
		++row;
	}
}

void writeSemaphores()
{
	while (remainingSemaphores)
	{
		writeRows(0);
		putchar('\n');

		remainingSemaphores -= q;
		g += q;
	}
}

void writeAsSemaphores(char input[80])
{
	J = input;

	g = K[2];
	parseInput();

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
	Q = T + CHARSET_LEN;
	M[1] = Q + HEIGHT;
	k = M[1] + 2;
	F = k + 7;
	M[0] = F + 7;
	initialiseRepresentations();

	// Everything until here is just initial setup.
	char input[80];
	while (1)
	{
		fgets(input, 80, stdin);
		writeAsSemaphores(input);
	}
}
