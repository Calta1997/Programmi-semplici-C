//Librerie:
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Configurazioni:
#define CIFRE 4 //imposta numero di cifre con cui si gioca

//Funzioni:

//Funzione che prende in input il vettore del numero segreto quello della chiamata avversaria e uno vuoto da riempire
//Restituisce un vettore di due locazioni con il numero di strike in 0 e il numero di ball in 1
void ritornaVettorePunti(const int segreto[CIFRE],const int chiamata[CIFRE], int sb[2]){
  int i,j;
  sb[0]=0;
  sb[1]=0;
  
  //per ogni posto della chiamata compara con tutte le altre del numero segreto
  for(i=0; i<CIFRE; i++){
    for(j=0; j<CIFRE; j++){
      if( chiamata[i] == segreto[j] ){//se un numero e' stato azzeccato
	if( i==j )//se il numero di posizione e' uguale
	  sb[0]++;//incremento numero di strike
	else
	  sb[1]++;//incremento numero di ball
      }
    }
  }
  return;
}


//Funzione che restituisce il vettore del numero preso in input dall'utente
void getNumber(int numero[]){
  int i;
  
  printf("Immetti le %d cifre del numero separate da spazio\n--> ", CIFRE);
  for(i=0;i<CIFRE;i++)//immagazzino cifre nelle varie locazioni  
    scanf("%d",&numero[i]);
  
  for(i=0;i<CIFRE;i++)//controllo ogni locazione per vedere se contiene una sola cifra
    if(numero[i]<0 || numero[i]>9){//se l'istanza non soddisfa le precondizioni 
      puts("Errore: Questa volta separa tutte le singole cifre da uno spazio");
      getNumber(numero);//stampo errore e richiamo nuovamente la funzione (tanto i vettori vengono passati per riferimento)
    }
  
  return;
}


//Funzione che controlla che non ci siano due cifre uguali all'interno di uno stesso numero
//restituisce 1 se trova cifre uguali
bool checkUguali(const int numero[]){
  int a,j;
  bool uguali = false; 
  uguali = 0;// se trovo due cifre uguali diventa vero e mi inculo l'utente
  for (a = 0; a < CIFRE && !uguali ; a++){ 
    for (j = 0; j < CIFRE && !uguali ; j++)
      if ((numero[a] == numero[j]) && (a != j)){
	uguali = true;
	printf("ERRORE: Sono state immesse almeno due cifre uguali, ricontrollare istanza\n");
      }
  }
  return uguali;
}

void clearCls(void){	
	//system("clear"); // Funzione che pulisce la console
        #ifdef _WIN32
            system("cls");
        #else
            // Assume POSIX
            system ("clear");
#endif
}
