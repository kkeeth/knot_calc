#include<stdio.h>#include<complex.h>#include<math.h>	/*メイン関数*/int main(void) {	int a,b;	float N;	double J=0;	double _Complex t,T=0;		printf("a,b,Nの値を入力して下さい。");	scanf("%d %d %f",&a,&b,&N);			t = cexp(2*M_PI*I/N);			for(int e=-1; e<2; e=e+2){		for(float k=(-1)*(N-1)/2; k<=((N-1)/2); k++){			T = T + (e * cpow(t,a*b*pow(k,2) + k*(a+e*b) + e/2));		}	}		J = cabs(T/(cpow(t,N) - 1));//	printf("J:%.24lf  %.24lf\n",creal(J),cimag(J));	printf("N=%d:%.24lf\n",(int)N,log(J)/N);		return 0;}