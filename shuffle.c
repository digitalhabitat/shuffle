/*
Michael Miller
Fisher-Yates Shuffle Demo
5/4/2016
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void randperm(int n, int perm[]);


int main(){

	int num = 3;
	int per[num];
	srand(time(NULL));	
	int randNum = rand();

	printf("random number is %d\n", randNum);
	randperm(num, per);

	return 0;
}
void randperm(int n, int perm[])
{

	int k = 10000000;
	int h;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	double A, B, C, D, E, F;

	int i, j, temp;

	
	//this loop can demo multiple shuffles
	for (h = 0; h < k; h++){
		
		//acts like n! sided dice for possible permutations		
		//intialize array [0 to (n-10)]
		for (i = 0; i < n; i++){
			perm[i] = i;
		}
		
		//Fisher-Yates shuffle
		for (i = 0; i<n; i++) {

			// [0 to (n-1)] with incrementing lower bound
			j = rand() % (n - i) + i;
			
			//swaping p[j] and p[i]
			temp = perm[j];
			perm[j] = perm[i];
			perm[i] = temp;
			printf("%d ",perm[i]);
		}

		printf("\n");
		if (perm[0] == 0 && perm[1] == 1 && perm[2] == 2){
			++a;
		}
		else if (perm[0] == 2 && perm[1] == 0 && perm[2] == 1){
			++b;
		}
		else if (perm[0] == 1 && perm[1] == 2 && perm[2] == 0){
			++c;
		}
		else if (perm[0] == 2 && perm[1] == 1 && perm[2] == 0){
			++d;
		}
		else if (perm[0] == 0 && perm[1] == 2 && perm[2] == 1){
			++e;
		}
		else if (perm[0] == 1 && perm[1] == 0 && perm[2] == 2){
			++f;
		}
	}

	A = (double)a / k;
	B = (double)b / k;
	C = (double)c / k;
	D = (double)d / k;
	E = (double)e / k;
	F = (double)f / k;

	printf("Performed %d shuffles\n", k);

	printf("case a(012): %.3lf\n", A);
	printf("case b(201): %.3lf\n", B);
	printf("case c(120): %.3lf\n", C);
	printf("case d(210): %.3lf\n", D);
	printf("case e(021): %.3lf\n", E);
	printf("case f(102): %.3lf\n", F);


	

}
