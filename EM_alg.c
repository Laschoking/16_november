#include <stdio.h>
#include <stdlib.h>
/*Gewinn für A bei (0,0), und (0,1)*/
enum {Gewinn=0,gesWahrs=1};
float q_A[2];/*angabe wahrscheinlichkeiten*/
float q_B[2];

float h_Ages,h_Bges;
/*Eintrag von 1. Anzahl Gewinne h(analysator) 2. Summe Wahrscheinlichkeiten für Analysator A*/


float Unvoll_P[2][2]; /*wahrscheinlichkeiten innerhalb Produktmenge{(0,0),(0,1)//(1,0),(1,1)} || 2-dim-Array*/
float Voll_P[2][2]; /*tatsächliche Verteilung innerhalb Produktmenge*/
float Voll_h_A[2];/*tatsächliches Vorkommen der jeweiligen Zahl (0),(1) */
float Voll_h_B[2]; /*float da nicht unbedingt ganzzahlig*/

void init(){
q_A[1]=1-q_A[0];
q_B[1]=1-q_B[0];
}

void BerechnungKorpus(int AGewinn,int BGewinn){
int i,j;
puts("Wahrscheinlichkeiten");
for (i=0;i<=1;i++){		/*unvollständige Belegung der Produktmengen*/
	for (j=0;j<=1;j++){
		Unvoll_P[i][j]=q_A[i]*q_B[j];/*Wahrscheinlichkeit des Ereignisses*/
		printf("(%d,%d) %f\n",i,j,Unvoll_P[i][j]);
	}
}
h_Ages=Unvoll_P[0][0]+ Unvoll_P[0][1];
h_Bges=Unvoll_P[1][0]+ Unvoll_P[1][1];

puts("vollständige Belegung");
for (i=0;i<=1;i++){		/*vollständige Belegung der Produktmengen*/
	for (j=0;j<=1;j++){
		if(i==0)Voll_P[i][j]=Unvoll_P[i][j]*AGewinn/h_Ages; /*Vorkommen des Ereignisses*/
		else Voll_P[i][j]=Unvoll_P[i][j]*BGewinn/h_Bges;
		printf("(%d,%d) %f\n",i,j,Voll_P[i][j]);

	}
}
puts("Vorkommen Einzelergebnisse");
for (i=0;i<=1;i++){
	Voll_h_A[i]=0; 		/*Initialisierung*/
	Voll_h_B[i]=0; 		
	for(j=0;j<=1;j++){
		Voll_h_A[i]+=Voll_P[i][j];	/*Vorkommen der Einzelereignisse h(0),(1)*/
		Voll_h_B[i]+=Voll_P[j][i];
	}
		printf("h1A(%d) %f\n",i,Voll_h_A[i]);
		printf("h1B(%d) %f\n",i,Voll_h_B[i]);
	}
}
void q_neu(int AGewinn,int BGewinn){
puts("alte Einzelwahrscheinlichkeiten");
for(int i=0;i<=1;i++){
	printf("q1A(%d) %f\n",i,q_A[i]);
	printf("q1B(%d) %f\n",i,q_B[i]);
}
puts("neue Einzelwahrscheinlichkeiten");
for(int i=0;i<=1;i++){
	q_A[i]=Voll_h_A[i]/(AGewinn+BGewinn);
	q_B[i]=Voll_h_B[i]/(AGewinn+BGewinn);
	printf("q1A(%d) %f\n",i,q_A[i]);
	printf("q1B(%d) %f\n",i,q_B[i]);
	}
}

int main(){
int AGewinn,BGewinn;
puts("Eingabe 1. Gewinn A 2.Wahrscheinlichkeit q0A");
scanf("%d %f",&AGewinn,&q_A[0]);
puts("Eingabe 1. Gewinn B 2. Wahrscheinlichkeit q0B");
scanf("%d %f",&BGewinn,&q_B[0]);
init();
/*for(int i=1;i<=2;i++){*/
BerechnungKorpus(AGewinn,BGewinn);
q_neu(AGewinn,BGewinn);
/*}*/
}	
