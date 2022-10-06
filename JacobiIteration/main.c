
#include<stdio.h>
#include<math.h>
#include<stdlib.h>



void main()
{
	float a[20][20],b[20],x[20],xn[20],epp=0.00001,sum;
	int i,j,n,flag;
	
	//	contoh matrix 10x10
	//	10 1 1 1 1 1 1 1 1 1
	//	1 10 1 1 1 1 1 1 1 1
	//	1 1 10 1 1 1 1 1 1 1
	//	1 1 1 10 1 1 1 1 1 1
	//	1 1 1 1 10 1 1 1 1 1
	//	1 1 1 1 1 10 1 1 1 1
	//	1 1 1 1 1 1 10 1 1 1
	//	1 1 1 1 1 1 1 10 1 1
	//	1 1 1 1 1 1 1 1 10 1
	//	1 1 1 1 1 1 1 1 1 10

	printf("\nJumlah Variabel: ");
	scanf("%d",&n);
	printf("\nMasukan nilai matrix: ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	printf("\nMasukan nilai: ");
	for(i=0;i<n;i++)
		scanf("%f",&b[i]);
	for(i=0;i<n;i++)
		x[i]=0; //initialize


	flag=0;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<n;j++)
			if(i!=j){
				sum+=fabs(a[i][j]);
//				printf("%f",sum);
			}
				
			if(sum>fabs(a[i][i])){
//				printf("%f",sum);
				printf("\n %f flag row %f",a[i][i],sum);
				flag=1;
			}
				
	}

	//checking for column dominance
	if(flag==1)
		flag=0;
	for(j=1;j<n;j++)
	{
		sum=0;
		for(i=1;i<n;i++)
			if(i!=j){
				sum+=fabs(a[i][j]);
//				printf("%f",sum);
			}
				
			if(sum>fabs(a[j][j])){
//				printf("%f",sum);
//				printf("%d",j);
				printf("\n %f flag col %f",a[j][j],sum);
				flag=1;
			}
				
	}

	if(flag==1)
	{
		printf("Koefisien matrix diagonal tidak dominan \n");
		exit(0);
	}

	for(i=0;i<n;i++)
		printf(" x[%d] ",i);
	printf("\n");

	do
	{
		for(i=0;i<n;i++)
		{
			sum=b[i];
			for(j=0;j<n;j++)
				if(j!=i)
					sum-=a[i][j]*x[j];
				xn[i]=sum/a[i][i];
		}
		for(i=0;i<n;i++)
			printf("%8.5f ",xn[i]);
		printf("\n");
		flag=0; 
		//indicates |x[i]-xn[i]|<epp for all i
		for(i=0;i<n;i++)
			if(fabs(x[i]-xn[i])<epp)
				flag=1;
		if(flag==1)
			for(i=1;i<n;i++)
				x[i]=xn[i]; //reset x[i]	

	}while(flag==1);

	printf("Jawaban \n");
	for(i=0;i<n;i++)
		printf("%8.5f ",xn[i]);
}

// referensi 

//#include<stdio.h>
//float coeff[10][10];
//float Dinv[10][10];
//float approx[10][1];
//float R[10][10];//declare the relevant matrices
//float matrixRes[10][1];
//float b[10][1];
//float temp[10][1];
//int row,column,size,navigate;
//void multiply(float matrixA[][10],float matrixB[][1])
//{
//    int ctr,ictr;
////function to perform multiplication
//for(ctr=0;ctr<size;ctr++)
//{
//    matrixRes[ctr][0]=0;
//        for(navigate=0;navigate<size;navigate++)
//            matrixRes[ctr][0]=matrixRes[ctr][0]+matrixA[ctr][navigate]*matrixB[navigate][0];
//}
//}
//int main()
//{
//printf("Enter the number of unknown(below 10)\n");
//scanf("%d",&size);//enter the size
//printf("Enter the coefficent matrix\n");
//for(row=0;row<size;row++)
//    for(column=0;column<size;column++)
//        scanf("%f",&coeff[row][column]);
//printf("Enter the first approximation\n");
//for(row=0;row<size;row++)
//scanf("%f",&approx[row][0]);
//printf("Enter the RHS coefficient\n");
//for(row=0;row<size;row++)
//scanf("%f",&b[row][0]);
//for(row=0;row<size;row++)//We calculate the diagonal inverse matrix make all other entries as zero except Diagonal entries whose resciprocal we store
//    for(column=0;column<size;column++)
//    {    if(row==column)
//        Dinv[row][column]=1/coeff[row][column];
//        else
//        Dinv[row][column]=0;
//    }
//for(row=0;row<size;row++)
//    for(column=0;column<size;column++)//calculating the R matrix L+U
//    {    if(row==column)
//        R[row][column]=0;
//        else
//        if(row!=column)
//        R[row][column]=coeff[row][column];
//    }
//int iter;
//printf("Enter the number of iterations:\n");
//scanf("%d",&iter);//enter the number of iterations
//int ctr=1;
//int octr;
//while(ctr<=iter)
//{
//multiply(R,approx);//multiply L+U and the approximation
//for(row=0;row<size;row++)
//temp[row][0]=b[row][0]-matrixRes[row][0];//the matrix(b-Rx)
//multiply(Dinv,temp);//multiply D inverse and (b-Rx)
//for(octr=0;octr<size;octr++)
//approx[octr][0]=matrixRes[octr][0];//store matrixRes value in the next approximation
//printf("The Value after iteration %d is\n",ctr);
//for(row=0;row<size;row++)
//printf("%.3f\n",approx[row][0]);//display the value after the pass
//ctr++;
//}
//getch();
//}

