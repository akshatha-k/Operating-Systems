#include <stdio.h>

void Page(int no)
{
	printf("Page number : %d\n",no/32);
	printf("Page offset : %d\n",no%32);
}
int main()
{
	Page(204);
	Page(56);
	printf("Bytes: 8 \n");
}