#include"test5.h"
int main()
{
	BiTree *T=(BiTree*)malloc(sizeof(BiTree));
	InitBiTree(T);
	CreateBiTree(T);
	printf(";%d",DepthBiTree(*T));
	printf("\n");
	if(FindBiTree(*T,'a')==1)
		printf("\n");
	else 
		printf("\n");
	printf(":");
	PreOrder(*T);
	printf("\n");
	printf(";");
	InOrder(*T);
	printf("\n");
	printf(":");
	PostOrder(*T);
	printf("\n");
	printf(":");
    LevelOrder(*T);
	printf("\n");
	ClearBiTree(T);
	printf(":");
	if(EmptyBiTree(*T)==1)
		printf("!\n");
	else
		printf("!\n");
	return 0;
}



	