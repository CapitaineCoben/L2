#include <cstdio>
int main()
{int note;
	do
	{	printf("entrez une note\n");
		scanf("%d",&note);
	}while(note < 0 || note > 20);

	if (note <= 10 and note >=0) {printf("failing\n");}
	if (note <= 12 and note >10) {printf("satisfactory\n");}
	if (note <= 16 and note >12) {printf("good\n");}
	if (note > 16 and note <=20)  {printf("excellent\n");}

}
