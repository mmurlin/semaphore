#include <stdio.h>

// Observations:
//  a 'flagman' is at most 4 characters high (N = 4), and 8 wide (Y = 8).
//  all sequences (terminated with newline or space in input) end with the same flag position

char *T="IeJKLMaYQCE]jbZRskc[SldU^V\\X\\|/_<[<:90!\"$434-./2>]s";
char K[3][1000];
char *F;
char x;
char A;
char *M[2];
char *J;
char r[4];
char *g;
char N;
char Y;
char *Q;
char W;
char *k;
char q;
char D;

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

void l() // Calls E() while q.
{
	--q;
	E();

	if (q)
	{
		l();
	}
}

void B() // Likely sets up each flagman
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
		B();
	}
}

void b() // Writes each character for a given flagman.
{
	A = K[0][D*W+r[2]*Y+x];
	putchar(A);

	if (++x < Y)
	{
		b();
	}
}

void t() // Prints a row of characters for a flagman.
{
	D = q[g];
	x = 0;
	b();

	putchar(' ');

	if (++q < (r[1] < Y ? r[1] : Y))
	{
		t();
	}
}

void R() // Writes a row of characters.
{
	q = 0;
	t();

	putchar('\n');

	if (++r[2] < N)
	{
		R();
	}
}

void O()
{
	r[2] = 0;
	R();
	putchar('\n');

	if (r[1] -= q)
	{
		g += q;
		O();
	}
}

void C() // Gets user input and sets up input representation, then writes to screen.
{
	if (gets(K[1]))
	{
		J = K[1];

		g = K[2];
		B();

		if (!r[0])
		{
			*g++ = 0;
		}

		r[0] = 1;

		r[1] = g - K[2];

		g = K[2];

		if (r[1])
		{
			O();
		}

		C();
	}
}

int main()
{
	A = 0;
	J = K[0];
	W = 32;
	N = 4;
	Y = W - N;
	q = Y;
	Q = T + q;
	M[1] = Q + N;
	k = M[1] + 2;
	F = k + 7;
	M[0] = F + 7;
	l();

	r[0] = 1;
	Y = N << 1;
	C();
}
