#include <stdio.h>

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

X()
{
    r[r[r[3]=M[1-(x&1)][*r=W,1],2]=*Q+2,1]=x+1+Y,*g++=((((x&7)-1)>>1)-1)?*r:r[x>>3],(++x<*r)&&X();
}

E()
{
    A||X(x=0,g=J),x=7&(*T>>A*3),J[(x[F]-W-x)^A*7]=Q[x&3]^A*(*M)[2+(x&1)],g=J+((x[k]-W)^A*7)-A,g[1]=(*M)[*g=M[T+=A,1][x&1],x&1],(A^=1)&&(E(),J+=W);
}

l()
{
    E(--q && l());
}

B()
{
    *J&&B((D=*J,Q[2]<D&&D<k[1]&&(*g++=1),!(D-W&&D-9&&D-10&&D-13)&&(!*r&&(*g++=0),*r=1)||64<D&&D<91&&(*r=0,*g++=D-63)||D>=97&&D<123&&(*r=0,*g++=D-95)||!(D-k[3])&&(*r=0,*g++=12)||D>k[3]&&D<=k[1]-1&&(*r=0,*g++=D-47),J++));
}

j()
{
    putchar(A);
}

b()
{
    (j(A=(*K)[D*W+r[2]*Y+x]),++x<Y)&&b();
}

t()
{
    (j((b(D=q[g],x=0),A=W)),++q<(*(r+1)<Y?*(r+1):Y))&&t();
}

R()
{
    (A=(t(q=0),'\n'),j(),++r[2]<N)&&R();
}

O()
{
    (j((r[2]=0,R())),r[1]-=q)&&O(g-=-q);
}

C()
{
    (J=gets(K[1]))&&C((B(g=K[2]),*r=!(!*r&&(*g++=0)),(*r)[r]=g-K[2],g=K[2],r[1]&&O()));
}

main()
{
    C((l((J=(A=0)[K],A[M]=(F=(k=(M[!A]=(Q=T+(q=(Y=(W=32)-(N=4))))+N)+2)+7)+7)),Y=N<<(*r=!-A)));
}
