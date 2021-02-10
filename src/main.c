#include <stdio.h>

typedef int bool;

#define BUF_SIZE	80
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

char remainingSemaphores;

void generateSkeleton(char *semaphores)
{
	char i;
	for (i = 0; i < R_LEN; ++i)
	{
		*semaphores++ = skeleton[i];
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

void parseInput(char *input)
{
	char *nextchar = input;
	bool ws = 1;
	while (*nextchar)
	{
		if (*nextchar >= '0' && *nextchar <= '9')
		{
			*g++ = NUMERAL;
		}
		else if (!ws && (*nextchar == ' ' || *nextchar == '\t' || *nextchar == '\n' || *nextchar == '\r'))
		{
			*g++ = REST;
			ws = 1;
		}

		/*
			Representation values are -2 as alphanumerics come
			after rest and numeral identifier in array.
		*/
		if (*nextchar >= 'A' && *nextchar <= 'Z')
		{
			ws = 0;
			*g++ = *nextchar - ('A'-2);
		}
		else if (*nextchar >= 'a' && *nextchar <= 'z')
		{
			ws = 0;
			*g++ = *nextchar - ('a'-2);
		}
		else if (*nextchar == '0')
		{
			ws = 0;
			*g++ = 12;
		}
		else if (*nextchar >= '1' && *nextchar <= '9')
		{
			ws = 0;
			*g++ = *nextchar - ('1'-2);
		}

		++nextchar;
	}
}

void writeSegmentChars(char row, char idx)
{
	char i;
	for (i = 0; i < WIDTH; ++i)
	{
		putchar(K[0][idx * R_LEN +  /* Relevant semaphore representation */
			row * WIDTH +	    /* Current row of representation */
			i]		    /* Current char on row */
			);
	}
}

void writeRowSegments(char row, char *currentSemaphore)
{
	while (*currentSemaphore < (remainingSemaphores < WIDTH ? remainingSemaphores : WIDTH))
	{
		writeSegmentChars(row, g[*currentSemaphore]);

		putchar(' ');
		++(*currentSemaphore);
	}
}

void writeRows(char *currentSemaphore)
{
	char row = 0;
	while (row < HEIGHT)
	{
		*currentSemaphore = 0;
		writeRowSegments(row, currentSemaphore);

		putchar('\n');
		++row;
	}
}

void writeSemaphores()
{
	char semaphoresWritten;
	while (remainingSemaphores)
	{
		writeRows(&semaphoresWritten);
		putchar('\n');

		remainingSemaphores -= semaphoresWritten;
		g += semaphoresWritten;
	}
}

void writeAsSemaphores(char input[INPUT_MAX])
{
	g = K[2];
	parseInput(input);

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
	char input[INPUT_MAX];
	while (fgets(input, INPUT_MAX, stdin) != NULL)
	{
		writeAsSemaphores(input);
	}
}
