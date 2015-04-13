#include<stdio.h>
#include<math.h>

int n,i,j,k,l;
double c,sigma;
double A[50][51],x[50];
double b[50];
void input(){
	printf("\tGAUSS NAIF\n\n");

	printf("Input ordo:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			printf("matrik A[%d][%d]:",i+1,j+1);
			scanf("%lf",&A[i][j]);
		}
		printf("\n");
	}

	printf("Matrik Inputan(A):\n");
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			printf("%g  ",A[i][j]);
		}
		printf("\n");
	}

}
void hitung(){
	x[n-1]=b[n-1]/A[n-1][n-1];
	for(k=n-2;k>=0;k--){
		sigma=0;
		for(j=k+1;j<n;j++)
			sigma = sigma + A[k][j] * x[j];

		x[k] = (b[k] - sigma) / A[k][k];
		}
		printf("hasil akar:\n");
		for(i=0;i<n;i++){
			printf("akar[%d]:%g ",i+1,x[i]);
			printf("\n");}
	

}
void obe(){

	puts("\nProses OBE augmented matrik ");
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){

			c=A[j][i]/A[i][i];
			for(k=0;k<n+1;k++){
				A[j][k]=A[j][k]-c*A[i][k];
			}
			puts("");
			for(k=0;k<n;k++)
			{
				for(l=0;l<n;l++)
				{
					printf("%.2g\t", A[k][l]);
				}
				printf("%.2g\t", A[k][n]);
				puts("");
			}

		}
	}

	for(i=0;i<n;i++){
		b[i]=A[i][n];
	}
}
main(){

	input();
	obe();
	hitung();


}
