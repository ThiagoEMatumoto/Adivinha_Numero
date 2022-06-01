#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define NUMERO_TENTATIVAS 10

void imprime_cabeca(){
       
printf("       _                         _                    _ _       _       _                /\\/|       \n");
printf("      | |                       | |          /\\      | (_)     (_)     | |              |/\\/        \n");
printf("      | | ___   __ _  ___     __| | ___     /  \\   __| |___   ___ _ __ | |__   __ _  ___ __ _  ___  \n");
printf("  _   | |/ _ \\ / _` |/ _ \\   / _` |/ _ \\   / /\\ \\ / _` | \\ \\ / / | '_ \\| '_ \\ / _` |/ __/ _` |/ _ \\ \n");
printf(" | |__| | (_) | (_| | (_) | | (_| |  __/  / ____ \\ (_| | |\\ V /| | | | | | | | (_| | (_| (_| | (_) |\n");
printf("  \\____/ \\___/ \\__, |\\___/   \\__,_|\\___| /_/    \\_\\__,_|_| \\_/ |_|_| |_|_| |_|\\__,_|\\___\\__,_|\\___/ \n");
printf("                __/ |                                                                )_)            \n");
printf("               |___/                                                                                \n");                                                                    
	return;
}

void limpa_tela(){
		system("pause");
		system("cls");
}

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"Portuguese");
	
	//////////////////////////////////////////////
	// CONFIGURANDO A RAND PARA N�MEROS ALEAT�RIOS
	//////////////////////////////////////////////	
	int segundos = time(0);
	srand(segundos);
	char resp; 
	
	do{
		
		int auxiliar = rand();
	
		int valor = auxiliar % 100;
	
		int pontos = 1000;
	
		int chute, i;
	
		//////////////////////
		// DIN�MICA DO JOGO
		//////////////////////	
		for (i = 1; i<=NUMERO_TENTATIVAS; i++ ){
			imprime_cabeca();
			printf("Est� � sua %d� tentativa \n", i);
			printf("Fa�a o seu chute -> ");
			scanf("%d", &chute);
	
			if (chute < 0){
				printf("N�mero inv�lido -> colocar um valor maior que 0 \n");
				i --;
				limpa_tela();
			continue;
			}
		
			if (chute < valor){
			printf("Chute um valor mais alto \n");
			pontos = pontos - 100;
			limpa_tela();
			} else {
				if (chute > valor){
				printf("Chute um valor mais baixo \n");
				pontos = pontos - 100;
				} 
			limpa_tela();
			}		
		}	
		
		///////////////////////////////
		//  VIT�RIA OU DERROTA
		//////////////////////////////
		
		if (chute == valor){
			printf("Voc� ganhou o jogo ! Parab�ns ! \n");
			printf("Voc� acertou em %d tentativas \n", i);
			printf("Total de Pontos: %d", pontos);
			limpa_tela();
		} else {
			printf("N�o foi dessa vez... \n");
			printf("Mas n�o desanima, voc� pode tentar outra vez");
			limpa_tela();
		}
		
		/////////////////////////////////
		// FIM DE JOGO | JOGAR NOVAMENTE
		////////////////////////////////
		imprime_cabeca();
		printf("Voc� fez %d pontos \n", pontos);
		printf("Voc� deseja jogar novamente ? [s|n]");
		scanf("%s", &resp);
		limpa_tela();
	}while ( resp == 's');
	
	
	return 0;
}
