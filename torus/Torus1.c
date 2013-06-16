#include<stdio.h>#include<complex.h>#include<math.h>/*ーーーーグローバル変数の宣言ーーーー*/int i,j,l;/*ーーーー関数のプロトタイプ宣言ーーーー*/double _Complex poly1(float k, double _Complex t);double _Complex poly2(float k, double _Complex t);/*ーーーーメイン関数ーーーー*/int main(void) {	int a,b;	float k,N,e;	double J;	double _Complex t,T,Tn=0;		printf("a,bの値を入力して下さい。");	scanf("%d %d",&a,&b);		for(N=2;N<2000;N++){		t = cexp(2*M_PI*I/N);		J=0,T=0,Tn=0;				for(i=0; i<N; i++){			Tn = Tn + cpow(t,i);		}				for(k=(-1)*(N-1)/2; k<=((N-1)/2); k++){			if(k == 0){				T = T + cpow(t,(float)(-1)/2) / Tn;			}			else if(2*b*k+1 == N){				T = T + cpow(t,a*b*pow(k,2) + (a-b)*k -(float)1/2);			}			else if(2*b*k+1 > 0){				T = T + cpow(t,a*b*pow(k,2) + (a-b)*k -(float)1/2) * poly1(2*b*k+1,t)/Tn;			}			else if(2*b*k+1 < 0){				T = T + cpow(t,a*b*pow(k,2) + (a-b)*k -(float)1/2) * poly2(2*b*k+1,t)/Tn;			}		}		J = cabs(T);//		printf("J:%.24lf\n",J);		printf("%.24lf\n",log(J)/N);	}	return 0;}/*ーーーーサブ関数ーーーー*/double _Complex poly1(float k, double _Complex t){	double _Complex Tb=0;		for(j=0; j<k; j++){		Tb = Tb + cpow(t,j);	}//	printf("Tb+:%lf  %lf\n",creal(Tb),cimag(Tb));	return Tb;}double _Complex poly2(float k, double _Complex t){	double _Complex Tb=0;		for(l=0; l<-k; l++){		Tb = Tb + cpow(t,l);	}	//	printf("Tb-:%lf  %lf\n",creal(Tb),cimag(Tb));	return -cpow(t,k)*Tb;}