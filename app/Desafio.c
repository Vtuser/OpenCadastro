#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // Adicionar mais bibliotecas que serão utilizadas 


// 1.Desenvolva a seguinte aplica��o que utilizar� ponteiros, fun��es, structs e recursividade:

// Um mini cadastro de alunos (vetor de 10 posi��es); Cada aluno dever� conter um nome,
// ra e quatro notas; O usu�rio poder� escolher: Cadastrar novo aluno, exibir alunos existentes,
// exibir aluno pelo ra, exibir m�dias dos alunos e exibir maior e menor m�dia (uma fun��o para cada op��o);
// A op��o para exibir o aluno pelo c�digo do ra dever� ser recursiva e exibir o aluno caso ele exista.

// Regras
// 	N�o � poss�vel informar um RA j� existente (dever� ser feita uma buscar recursiva pelo n�mero de RA);
//  As notas devem ser entre 0 e 10 (verificar se a nota est� correta ao informar);

struct dados{
       char nome[80];
       int RA;
       float N[4];
       }Aluno_DATA[10];

void cadastre(int cont){

     int i;

     printf("insira o NOME do aluno: ");
     fflush(stdin);
     gets(Aluno_DATA[cont].nome);
     fflush(stdin);
     printf("insira o RA do aluno: "); scanf("%d", &Aluno_DATA[cont].RA);
     for(i=0; i<4; i++){
     printf("insira a %da Nota do aluno: ", i+1); scanf("%f", &Aluno_DATA[cont].N[i]);
     if(Aluno_DATA[cont].N[i] < 0 || Aluno_DATA[cont].N[i] > 10){
             printf("Nota NAO Inserida!\n");
             i--;
             }
     }
}

void exibaAlunos(int cont){

     int i, j;
     printf("----------- Exibindo Alunos -----------\n\n");

     for(i=0; i< cont; i++){
        printf(" Nome: %s\n RA: %d \n", Aluno_DATA[i].nome, Aluno_DATA[i].RA);
        for(j=0; j<4; j++){
                     printf(" Nota %d: %.1f\n", j+1, Aluno_DATA[i].N[j]);
                                       }

                 }
     printf("\n\n ----------- Fim da Funcao -----------");
     system("PAUSE");
     }

void encontre(int cont, int RA, int i) {

     int j;

     if (i == cont){}
     else{if(Aluno_DATA[i].RA == RA){
        printf(" Nome: %s\n RA: %d \n", Aluno_DATA[i].nome, Aluno_DATA[i].RA);
        for(j=0; j<4; j++){
                     printf(" Nota %d: %.1f\n", j+1, Aluno_DATA[i].N[j]);
        }}
        else{encontre(cont, RA, i+1);}
        }
}
void exibaMedia() {}

void maiorMenor() {}

int main(int argc, char *argv[]){

    int menu, i = 0, cont = 0, RA;
    do{
    printf("\n\n ---MENU---\n 1 - Cadastrar novo aluno; \n 2 - Exibir alunos existentes; \n 3 -  Encontrar aluno por RA; \n 4 - Exibir m�dias dos alunos; \n 5 - Exibir menor e maior media \n\n Digite o numero da fun��o desejada: ");
    scanf("%d", &i);

    switch (i){

     case 1:
     cadastre(cont);
     cont++;
     break;

     case 2:
     exibaAlunos(cont);
     break;

     case 3:
      printf("\n\n Digite o RA do Aluno:"); scanf("%d", &RA);
     encontre(cont, RA, 0);
     break;

     case 4:
     exibaMedia();
     break;

     case 5:
     maiorMenor();
     break;

     default:
     printf("fun��o n�o existe \n ");
           }
}while( i > -1);
             }
