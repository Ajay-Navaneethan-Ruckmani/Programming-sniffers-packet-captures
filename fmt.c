#include<stdio.h>
/*%n is a format specifier for pointer that is uded in printf which gives the number of bytes returned so far  */

int main(){
	int i=0, j=20, k, l;
	printf("k: %d\n l:%d\n",k,l ); 	//k and l will hvae garbage value 
	//how %n works
	printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit%n. Duis iaculis ullamcorper accumsan.Nukkam mu sapien, finibus nec leo non, finibus luctus est. Aliquam gravida, mauris tincindunt tempur portitior,o orci turpis%n.", &k,&l);

	printf("K:%d\n l: %d\n",k,l );
	printf("i: %d,at %08x. j:%d, at %08x. \n",i,&i,j,&j);
	return 0;

}