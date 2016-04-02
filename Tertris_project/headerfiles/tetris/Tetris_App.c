/*
 * Tetris_App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */
#include "../types.h"
//#include "Tertris_App.h"

 u8 background[8][8] =	   { { 0, 0, 0, 0, 0, 0, 0, 0 },
		                     { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
	                         { 0, 0, 0, 0, 0, 0, 0, 0 } };


 u8 movingpart[8][8] =	 { { 0, 0, 0, 0, 0, 0, 0, 0 },
		                     { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
	                         { 0, 0, 0, 0, 0, 0, 0, 0 } };




 u8 DotMatrix[8][8] =	   { { 0, 0, 0, 0, 0, 0, 0, 0 }, ///is the moving part matrix
		                     { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
							 { 0, 0, 0, 0, 0, 0, 0, 0 },
	                         { 0, 0, 0, 0, 0, 0, 0, 0 } };
void MatrixRotate(u8 Copy_u8PtrToMatrix[][2], u8 Copy_u8PtrTonewMatrix[][2]) {
	u8 i, j;
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 2; ++j) {
			Copy_u8PtrTonewMatrix[i][j] = Copy_u8PtrToMatrix[2 - j - 1][i];
		}
	}
}



void MatrixEquality(u8 Copy_u8PtrToMatrix[][2], u8 Copy_u8PtrTonewMatrix[][2])
{
	u8 i, j;
		for (i = 0; i < 2; ++i) {
			for (j = 0; j < 2; ++j) {
				Copy_u8PtrToMatrix	[i][j] = Copy_u8PtrTonewMatrix[i][j];
			}
		}

}

void MatrixRotateInTheSameMatrix(u8 Copy_u8PtrToMatrix[][2] ) {
	u8 i, j;
	u8 Copy_u8PtrTonewMatrix[2][2]={{0,0},{0,0}};
	__asm__("CLI");
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 2; ++j) {
			Copy_u8PtrTonewMatrix[i][j] = Copy_u8PtrToMatrix[2 - j - 1][i];
		}
	}

	MatrixEquality(Copy_u8PtrToMatrix,Copy_u8PtrTonewMatrix);
	__asm__("SEI");
}


/*     0,0  0,1
 *     1.0  1,1
 *
 *      (X,Y )
 *
 * */


void MatrixAdditionAtXY(u8 Copy_u8PtrToMatrix[][2],u8 copy_u8XPosition,u8 copy_u8YPosition) {
	u8 localx_u8counter=0;
	u8 localy_u8counter=0;
	//initializing the DotMatrix to zero
	//if(x>)
	for(localx_u8counter=0;localx_u8counter<8;localx_u8counter++)
	{
		for(localy_u8counter=0;localy_u8counter<8;localy_u8counter++)
			{
//TODO dot matrix repalcment
			movingpart[localx_u8counter][localy_u8counter]=0;
			}

	}
// the range of the  copy_u8XPosition & copy_u8YPosition is from  1:8
//	if((copy_u8XPosition<=8) && (copy_u8YPosition<=8))
//	{
		// the range of the  copy_u8XPosition & copy_u8YPosition is from  1:8
		/// i need to make it from 0 to 7
	copy_u8XPosition--;
	copy_u8YPosition--;
	movingpart[copy_u8XPosition]  [copy_u8YPosition]		+=  Copy_u8PtrToMatrix[1][0];
	movingpart[copy_u8XPosition-1][copy_u8YPosition]	 	+= 	Copy_u8PtrToMatrix[0][0];
	movingpart[copy_u8XPosition]  [copy_u8YPosition+1] 		+= 	Copy_u8PtrToMatrix[1][1];
	movingpart[copy_u8XPosition-1][copy_u8YPosition+1] 		+=	Copy_u8PtrToMatrix[0][1];
//	}
//	else
//	{
//
//	}
}

void MatrixAddition(u8 Copy_u8PtrToMatrix[][2]) {


	DotMatrix[0][3] = Copy_u8PtrToMatrix[0][0];
	DotMatrix[0][4] = Copy_u8PtrToMatrix[0][1];
	DotMatrix[1][3] = Copy_u8PtrToMatrix[1][0];
	DotMatrix[1][4] = Copy_u8PtrToMatrix[1][1];

}

void MatrixFlow(void) {
	u8 btn=1;
	static u8 counter=0;
	static u8 reault1=0;
	static u8 reault2=0;
	switch (btn) {
			case 0:



			break;
			case 1:

				//for (counter = 0; counter < 8; counter++)

					counter++;
					reault1=DotMatrix[counter + 1][3] + DotMatrix[counter][3];
					reault2=DotMatrix[counter + 1][4] +  DotMatrix[counter][4];
					if (reault1>1 || reault2>1){
						break;
					}
					else{
						DotMatrix[counter + 1][3] =DotMatrix[counter][3];
						DotMatrix[counter + 1][4]= DotMatrix[counter][4];
						DotMatrix[counter][3] = 0;
						DotMatrix[counter][4] = 0;
					}

				if(counter==7)
				{
					counter=0;

				}

				break;
	}
}



void addingThebackgroundTotheMovingPart() {
	u8 localx_u8counter=0;
	u8 localy_u8counter=0;

	//initializing the DotMatrix to zero
	//if(x>)
	for(localx_u8counter=0;localx_u8counter<8;localx_u8counter++)
	{
		for(localy_u8counter=0;localy_u8counter<8;localy_u8counter++)
			{

			DotMatrix[localx_u8counter][localy_u8counter]=movingpart[localx_u8counter][localy_u8counter]+background[localx_u8counter][localy_u8counter];
			}

	}
}

void updateThebackground(void)
{
	u8 localx_u8counter=0;
		u8 localy_u8counter=0;

		//initializing the DotMatrix to zero
		//if(x>)
		for(localx_u8counter=0;localx_u8counter<8;localx_u8counter++)
		{
			for(localy_u8counter=0;localy_u8counter<8;localy_u8counter++)
				{

				background[localx_u8counter][localy_u8counter]=DotMatrix[localx_u8counter][localy_u8counter];
				}

		}

}


void check4collisioion(u8 *local_u8collisionflag) {
	u8 localx_u8counter = 0;
	u8 localy_u8counter = 0;
	u8 temp[8][8];
	*local_u8collisionflag = 0;

	for (localx_u8counter = 0; localx_u8counter < 8; localx_u8counter++) {
		for (localy_u8counter = 0; localy_u8counter < 8; localy_u8counter++) {

			temp[localx_u8counter][localy_u8counter] =
					movingpart[localx_u8counter][localy_u8counter]
							+ background[localx_u8counter][localy_u8counter];
		}

	}
	for (localx_u8counter = 0; localx_u8counter < 8; localx_u8counter++) {
		for (localy_u8counter = 0; localy_u8counter < 8; localy_u8counter++) {
			if (temp[localx_u8counter][localy_u8counter] == 0 ||temp[localx_u8counter][localy_u8counter] == 1) {

			} else {
				*local_u8collisionflag = 1;
				break;
			}

		}
	}

}
