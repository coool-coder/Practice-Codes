#include <stdio.h>
#define swap(a,b) a=a+b;b=a-b;a=a-b;


void main()
{
	auto a;
	register r;
	static s;
	extern e;
	printf("%d ",sizeof a);
	printf("%d ",sizeof r);
	printf("%d ",sizeof s);
	printf("%d \n",sizeof e);

	//int x = 2 < 3 < 1;
	//printf("%d\n", x);
	
	int x = 0, y = 0, t = 0;

	t = --x && y++;
	printf("%d %d %d\n", x,y,t);
	
}

