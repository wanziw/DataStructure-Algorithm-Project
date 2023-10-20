#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100 //定义最大容量

#include "test6_AdjM.h"


int main()
{
	MGraph *MG = InitMGraph();

	MGraphCreate(MG);

	MGraphPrint(MG);

	printf("\n");
	MGraphDegree(MG);
	return 0;
}
