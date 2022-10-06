#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void multiply(int *a, int row1, int col1, int *b, int row2, int col2) 
{
    assert(col1 == row2);
    int i,j,k;

    int size = row1*col2;
#ifdef _MSC_VER
    int *d = malloc(size * sizeof *d);
#else
    int d[size];
#endif
    for ( i = 0; i < row1; i++) {
        for ( j = 0; j < col2; j++) {
            int sum = 0;
            for ( k = 0; k < col1; k++)
                sum = sum + a[i * col1 + k] * b[k * col2 + j];
            d[i * col2 + j] = sum;
        }
    }

    for ( i = 0; i < size; i++) {
        if (i % col2 == 0) {
            printf("\n");
        }
        printf("%d ", d[i]);
    }

#ifdef _MSC_VER
    free(d);
#endif
}




int main(void){
	printf("Masukan Baris: ");
    int i; 
    scanf("%d", &i);

    printf("Masukan Kolom: ");
    int y; 
    scanf("%d", &y);

    int array[i][y];
    int rows, columns;
    int random;
    int k;

    srand((unsigned)time(NULL));
	
	//generate angka random
    int * arr_1D = malloc(sizeof(int) * i * y);
    if (arr_1D == NULL)
        exit(-1);

    int count = 0;
    for(rows=0;rows<i;rows++)
        {
            for(columns=0;columns<y;columns++)
                {
                    random=rand()%100+1;

                    array[rows][columns] = random;
                    printf("%d\t",array[rows][columns]);
                    // Konversi array
                    arr_1D[count++] =  array[rows][columns];
                }

            printf("\n");
        }

    for ( k = 0; k < count; ++k)
    {
        printf("%d ", arr_1D[k]);
    }
    
    printf("\n");
    
    // konversi 1d ke 2d
    
    printf("Masukan Baris: ");
    int N; 
    scanf("%d", &N);

    printf("Masukan Kolom: ");
    int M; 
    scanf("%d", &M);
    
    
    
    // contoh array a[6]={1,2,3,4,5,6};
    
    int arrayIndex = 0;
    int m[N][M];
    int a[6]={1,2,3,4,5,6};
    int row,column;
	for ( row = 0; row < N; ++row) {
	    for ( column = 0; column < M; ++column) {
	        m[row][column] = a[arrayIndex];
	        printf("%d\t",m[row][column]);
	        ++arrayIndex;
	    }
	    printf("\n");
	}
		
	
	printf("\n Perkalian Matrix");
	printf("\n  1, 2, 3,");
	printf("\n  4, 5, 6,");
	
	printf("\n\n  7, 10,");
	printf("\n\n  8, 11,");
	printf("\n\n  9, 12,");
	
	//contoh perkalian matrix 1d
    int arrA[] = {
        1, 2, 3,
        4, 5, 6,
    };
    int arrB[] = {
        7, 10,
        8, 11,
        9, 12,
    };
	
	printf("\n Hasil Perkalian \n");
    multiply(arrA, 2, 3, arrB, 3, 2);
}








