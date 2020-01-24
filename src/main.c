#include <stdio.h>

typedef int bool;

#define HEIGHT		4
#define WIDTH		8
#define R_LEN		32
#define CHARSET_LEN	28

#define REST		0
#define NUMERAL		1

const char skeleton[R_LEN] =	"        "
				"   ()   "
				"   ^^   "
				"   ][   ";

char *T="IeJKLMaYQCE]jbZRskc[SldU^V\\X\\|/_<[<:90!\"$434-./2>]s";
char K[3][1000];
char *F;
char x;
bool A;
char *M;
char *J;
char *g;
char *Q;
char *k;
char q;
char D;

char remainingSemaphores;

void generateSkeleton(char *semaphores)
{
	/* TODO I feel bad about removing this, I don't want to change how the program fundamentally works to this degree. I will probably rewrite this function. */
	/*
		x = 0;
		g = J;
		while (x < R_LEN)
		{
		   r[0] = ' ';
		   r[1] = x + 1 + CHARSET_LEN;
		   printf("%c	", r[1]);
		   r[2] = *Q + 2;
		   r[3] = M[1-(x&1)][1];

		   printf("%i:	%i\n", x, (x&7));
		   *g++ = ((((x&7)-1)>>1)-1) ? ' ' : r[x>>3];
		   ++x;
		}
	*/

	char *s = semaphores;
	char i;
	for (i = 0; i < R_LEN; ++i)
	{
		*s++ = skeleton[i];
	}
}

void placeFlags()
{
	/*
		A determines if the iteration is for the left or right hand
		side. T is a specific sequence of values that makes things more
		difficult. Q, F, k, and M are pointers along T. x is the value
		used to actually decide what to do based on values in T. J is a
		pointer to the current flagdude.
	*/

	if (!A)
	{
		generateSkeleton(J);
	}

	x = 7 & (*T >> A * 3);

	/* Adds arms. */
	J[(F[x]-R_LEN-x)^A*7] = Q[x&3] ^ A * M[2+(x&1)];
	/* Adds flags. */
	g = J + ((k[x] - R_LEN) ^ A * 7) - A;
	g[0] = (x & 1) ? '[' : '<';
	g[1] = (x & 1) ? ']' : '>';

	T += A;
	if (A = !A)
	{
		placeFlags();
		J += R_LEN;
	}
}

void initialiseRepresentations()
{
	char i;
	for (i = CHARSET_LEN; i > 0; --i)
	{
		placeFlags();
	}
}

void parseInput()
{
	bool ws = 1;

	while (*J)
	{
		D = *J;

		if (D >= '0' && D <= '9')
		{
			*g++ = NUMERAL;
		}
		else if (!ws && (D == ' ' || D == '\t' || D == '\n' || D == '\r'))
		{
			*g++ = REST;
			ws = 1;
		}

		/*
			Representation values are -2 as alphanumerics come
			after rest and numeral identifier in array.
		*/
		if (D >= 'A' && D <= 'Z')
		{
			ws = 0;
			*g++ = D - ('A'-2);
		}
		else if (D >= 'a' && D <= 'z')
		{
			ws = 0;
			*g++ = D - ('a'-2);
		}
		else if (D == '0')
		{
			ws = 0;
			*g++ = 12;
		}
		else if (D >= '1' && D <= '9')
		{
			ws = 0;
			*g++ = D - ('1'-2);
		}

		J++;
	}
}

void writeSegmentChars(char row)
{
	char i;
	for (i = 0; i < WIDTH; ++i)
	{
		putchar(K[0][D * R_LEN +    /* Relevant semaphore representation */
			row * WIDTH +	    /* Current row of representation */
			i]		    /* Current char on row */
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
	k = Q + HEIGHT + 2;
	F = k + 7;
	M = F + 7;
	initialiseRepresentations();

	/* Everything until here is just initial setup. */
	char input[80];
	while (1)
	{
		fgets(input, 80, stdin);
		writeAsSemaphores(input);
	}
}
