/*************************************************************
Programa Busca Palavras
Faça um programa que dado uma grade de letras que represente um jogo de caça-palavras
promova a busca (caça) das seguintes palavras:
JANEIRO ABRIL JULHO OUTUBRO
FEVEREIRO MAIO AGOSTO NOVEMBRO
MARCO JUNHO SETEMBRO DEZEMBRO
O programa deve leva em consideração:
(a) o arquivo de entrada exercicio2_trabalho2_entrada.txt fornece a matriz de entrada;
(b) o arquivo exercicio2_trabalho2_gabarito1.pdf apresenta o gabarito que servirá de referência para desenvolver o programa;
(c) as figuras1 e 2, as quais apresentam os requisitos de interface do usuário (tela) do programa;
(d) que ao escolher a opção 1 da tela, o usuário deverá entrar com uma das palavras (em
destaque acima) para a busca não importando se o usuário a escreveu usando letras minúsculas, maiúscula, ou uma combinação delas, ou seja, seu programa deverá considerar
todas estas opções e realizar internamente em seu programa (usando uma função) que a
transforme em uma palavra de letras maiúsculas para realizar a busca;
(e) que o resultado da busca da palavra deverá exibir na tela as informações: linha e coluna
da primeira letra da palavra buscada e se essa se encontra de forma vertical ou horizontal
(conforme Figura 2);
(f) se o usuário escrever uma palavra diferente das sugeridas, o programa deverá exibir uma
mensagem do tipo: Palavra inexistente;
(g) apos o usuário buscar uma palavra o programa deverá exibir novamente as opções de
ações da tela;
(h) que ao escolher a opção 2 da tela, o programa deverá exibir o gabarito do caça-palavras
completo (atentem-se que o exemplo apresentado na Figura 2 apresenta somente o
gabarito para as palavras FEVEREIRO, MAIO, JUNHO E JULHO);
(i) após a exibição do gabarito na tela o programa deverá ser encerrado;
(j) que ao escolher a opção 3 da tela, o programa deverá encerrar o jogo;
(k) adicionar a opção 4 (Imprimir Jogo) para criar um arquivo de saída (impressao.txt) com
a grade de letras e as palavras a serem caçadas (imprima o arquivo de saída e presenteie
alguém com a sua criação);
(l) após escolher a opção 4, o programa deverá exibir novamente todas as opções na tela;
(m) o programa deverá ser encerrado exibindo uma mensagem na tela parabenizando o usuário
quando este tiver buscado todas as 12 palavras propostas.
************************************************************/
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM 30
#define Y 15


int imprime(){
	int i=0,j=0,palavras[TAM][TAM],op;
	FILE *fe,*fs;
 	fs=fopen("impressao.txt","w");
	fe=fopen("exercicio2_trabalho2_entrada.txt","r");
	if(fe==NULL){
		printf("                                                **ERRO NA ABERTURA DO ARQUIVO**\n");
		return 1;
	}
	fprintf(fs,"                              ------------------------- Caça Palavras -----------------------\n");
	for(i=0;i<TAM;i++){
		fprintf(fs,"                                ");
        for(j=0;j<TAM;j++){
            fscanf(fe,"%d ",&palavras[i][j]);
            fprintf(fs,"%c ",palavras[i][j]);
    	}
    fprintf(fs,"\n");
    }
    fprintf(fs,"                              ------------------------Busca Palavras-------------------------\n\n");
    fprintf(fs,"                                              JANEIRO                FEVEREIRO\n");
    fprintf(fs,"                                              MARCO                  ABRIL\n");
    fprintf(fs,"                                              MAIO                   JUNHO\n");
    fprintf(fs,"                                              JULHO                  AGOSTO\n");
    fprintf(fs,"                                              SETEMBRO               OUTUBRO\n");
    fprintf(fs,"                                              NOVEMBRO               DEZEMBRO\n\n");
    
    fclose(fe);
    fclose(fs);
    
}


int opcoes(){
	int op;
	printf("\n                                [1]Buscar Palavra   [2]Gabarito   [3]Fim   [4]Imprimir Jogo\n");
    printf("\n                                Escolha uma opção: ");
    scanf("%d",&op);
    return op;
}


int interface(){
	int i,j,palavras[TAM][TAM];
	FILE *fe;
 
	fe=fopen("exercicio2_trabalho2_entrada.txt","r");
	if(fe==NULL){
		printf("                                                **ERRO NA ABERTURA DO ARQUIVO**\n");
		return 1;
	}
	printf("                              ------------------------- Caça Palavras -----------------------\n");
	for(i=0;i<TAM;i++){
		printf("                                ");
        for(j=0;j<TAM;j++){
            fscanf(fe,"%d ",&palavras[i][j]);
            printf("%c ",palavras[i][j]);
    	}
    printf("\n");
    }
    printf("                              ------------------------Busca Palavras-------------------------\n\n");
    printf("                                              JANEIRO                FEVEREIRO\n");
    printf("                                              MARCO                  ABRIL\n");
    printf("                                              MAIO                   JUNHO\n");
    printf("                                              JULHO                  AGOSTO\n");
    printf("                                              SETEMBRO               OUTUBRO\n");
    printf("                                              NOVEMBRO               DEZEMBRO\n\n");
    
    fclose(fe);
    
}


int compara_palavra(char s2[]){
	int i,qnt=0;
	char s1[][10]={"JANEIRO","FEVEREIRO","MARCO","ABRIL","MAIO","JUNHO","JULHO","AGOSTO","SETEMBRO","OUTUBRO","NOVEMBRO","DEZEMBRO"};
    for(i=0;i<=11;i++)
    	if(strcmp(s2,s1[i])==0){
        	qnt=1;
        	i=11;
		}
        
	return qnt;
}


int encontra_palavra(char mes[],int *pos,int *pos_x,int *pos_y){
	int i,j,m,n,tam_mes,x,y,aux_i=0,aux_j;
	FILE *farq;
	int palavras[TAM][TAM];
	farq=fopen("exercicio2_trabalho2_entrada.txt","r");
	if(farq==NULL){
		printf("                                                **ERRO NA ABERTURA DO ARQUIVO**\n");
		return 1;
	}
	for(i=0;i<TAM;i++)
		for(j=0;j<TAM;j++)
            fscanf(farq,"%d ",&palavras[i][j]);
	
	tam_mes=strlen(mes);
	
		for(i=0;i<TAM;i++){
			for(j=0;j<TAM;j++){
				x=0;
				y=0;
				for(m=0;m<tam_mes;m++){//acha palavra na coluna
					if(mes[m]==palavras[m+i][j]){y++;}
				}
				if(y==tam_mes){*pos=1;aux_i=i;aux_j=j;}//vertical
				
				for(n=0;n<tam_mes;n++){//acha palavra na linha
					if(mes[n]==palavras[i][n+j]){x++;}
				}
				if(x==tam_mes){*pos=2;aux_i=i;aux_j=j;}//horizontal
				
			}
		}
			
				*pos_x=aux_i;
				*pos_y=aux_j;
		
	fclose(farq);
}


void maiuscula(char palavra[]){
	int i;
	for(i=0;i<Y;i++){
			if(palavra[i]=='\0')
				i=Y-1;
			if(palavra[i]>='a'&&palavra[i]<='z')
				palavra[i]=palavra[i]-32;	
		}
}


int vitoria(char palavra[],int freq[]){
	
    int i,x;
	
        
	    if(strcmp(palavra,"JANEIRO")==0){x=1;}
		else if(strcmp(palavra,"FEVEREIRO")==0){x=2;}
		else if(strcmp(palavra,"MARCO")==0){x=3;}
		else if(strcmp(palavra,"ABRIL")==0){x=4;}
		else if(strcmp(palavra,"MAIO")==0){x=5;}
		else if(strcmp(palavra,"JUNHO")==0){x=6;}
		else if(strcmp(palavra,"JULHO")==0){x=7;}
		else if(strcmp(palavra,"AGOSTO")==0){x=8;}
		else if(strcmp(palavra,"SETEMBRO")==0){x=9;}
		else if(strcmp(palavra,"OUTUBRO")==0){x=10;}
		else if(strcmp(palavra,"NOVEMBRO")==0){x=11;}
		else if(strcmp(palavra,"DEZEMBRO")==0){x=12;}
		else{x=13;}
       
        freq[x]=freq[x]+1;
        if(freq[1]>=1&&freq[2]>=1&&freq[3]>=1&&freq[4]>=1&&freq[5]>=1&&freq[6]>=1&&freq[7]>=1&&freq[8]>=1&&freq[9]>=1&&freq[10]>=1&&freq[11]>=1&&freq[12]>=1){
			printf("\n                     >>>>>>>>>>>> Parabéns!!! Você conseguiu encontrar todas as 12 palavras propostas. <<<<<<<<<<<<\n");
			return 12;
		}
        
    return 0;
}


int busca_palavra(int freq[]){
	int op=0,pos_x,pos_y,pos;
	
	char palavra[Y];
	do{
		printf("\n                                Digite uma palavra: ");
		scanf("%s",palavra);
		maiuscula(palavra);
		if(compara_palavra(palavra)==0)
				printf("                                OPA!! Essa palavra não faz parte das sugestões, tente novamente.\n");
			else
				op=1;
	
		encontra_palavra(palavra,&pos,&pos_x,&pos_y);
		if(compara_palavra(palavra)==1){
		printf("                                Procure na Linha %d, Coluna %d, de modo ",pos_x+1,pos_y+1);
		if(pos==1)
			printf("vertical\n");
		else if(pos==2)
			printf("horizontal\n");
		}
			if(vitoria(palavra,freq)==12){
			return 12;
		}	
	}while(op==0);
	
        
	
}



int gabarito(){
	int i,j,m,n,palavras[TAM][TAM],gabarito[TAM][TAM],pos_x,pos_y,pos,tam_mes,x,y;
	FILE *fg;
    char meses[][TAM]={"JANEIRO","FEVEREIRO","MARCO","ABRIL","MAIO","JUNHO","JULHO","AGOSTO","SETEMBRO","OUTUBRO","NOVEMBRO","DEZEMBRO"};
    char mes[10];
	fg=fopen("exercicio2_trabalho2_entrada.txt","r");
	if(fg==NULL){
		printf("                                                **ERRO NA ABERTURA DO ARQUIVO**\n");
		return 1;
	}

	
	printf("\n                               --------------------------- Gabarito --------------------------\n");
	for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
			fscanf(fg,"%d ",&palavras[i][j]);  
		}	
	}
	for(i=0;i<TAM;i++)
	    for(j=0;j<TAM;j++)
	        gabarito[i][j]=00;
	  
	for(i=0;i<12;i++){
	  
	  for(j=0;j<TAM;j++)
        mes[j]=meses[i][j];
	  
	    encontra_palavra(mes,&pos,&pos_x,&pos_y);
	    
	    if(pos==1){//vertical
			for(m=0;m<TAM;m++)
                for(n=0;n<TAM;n++)
		            if(n==pos_y&&m>pos_x-1&&m<(pos_x)+strlen(mes))
		                gabarito[m][n]=palavras[m][n];
		                
	    }              
		else if(pos==2){//horizontal
		    	for(m=0;m<TAM;m++)
                    for(n=0;n<TAM;n++)
		                if(m==pos_x&&n>=pos_y&&n<pos_y+strlen(mes))
		                    gabarito[m][n]=palavras[m][n];
		}      	
	}	
	
	for(i=0;i<TAM;i++){
	    printf("                                  ");
	    for(j=0;j<TAM;j++){
	       if(gabarito[i][j]==00)
	        printf("  ");
	       else
	        printf("%c ",gabarito[i][j]);
    }
	    printf("\n");
	    }

		
	
    printf("                               -------------------------- Fim do Jogo -------------------------\n");
    fclose(fg);
    
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int i=0,op,freq[50];
	for(i=0; i<50; i++)
        freq[i]=0;
	
	if(interface()!=1)
	
	do{
		op=opcoes();
		switch(op){
			case 1:
				if(busca_palavra(freq)==12){op=3;}
				break;
			case 2:
				gabarito();
				op=3;
				break;
			case 3:
				printf("\n                                                  Fim de jogo. Até a próxima!!\n");
				break;
			case 4:
				if(imprime()==1)
					return 0;
				break;
			default:
				printf("\n                                                  EII!! Essa opção não existente.\n");
				break;			
		}
	}while(op!=3);
	return 0;
}



