
#include<stdio.h>
#include<stdlib.h>

#define TAB_SIZE 10 // 10x10

typedef struct
{
	int vetor1X, vetor1Y;
	int vetor2X, vetor2Y;
	int vetor3X, vetor3Y;
}PECAS_NAVIO;

// uso de NAVIO para agrupar as informaçoes, tanto das coordenadas das peças quanto se esta ativo ou nao
typedef struct
{
	PECAS_NAVIO pecas;
	int ativo;
}NAVIO;

// preenche o tabuleiro com 0
void IniciarTabuleiro(int tabuleiro[TAB_SIZE][TAB_SIZE])
{
	for(int i = 0; i < TAB_SIZE; i++)
	{
		for(int j = 0; j < TAB_SIZE; j++)
		{
			tabuleiro[i][j] = 0;
		}
	}
}

// exibe o tabuleiro na tela
void ExibirTabuleiro(int tabuleiro[TAB_SIZE][TAB_SIZE])
{
		for(int i = 0; i < TAB_SIZE; i++)
	{
		for(int j = 0; j < TAB_SIZE; j++)
		{
			printf("%d ", tabuleiro[i][j]);
		}
		printf("\n");
	}
}

int ValidarPosicaoDoNavio(NAVIO *navio, int tabuleiro[TAB_SIZE][TAB_SIZE])
{
	// representando as coordenadas das 3 partes do navio em uma matriz
	int posicoes[3][2] = {
		{navio->pecas.vetor1X, navio->pecas.vetor1Y},
		{navio->pecas.vetor2X, navio->pecas.vetor2Y},
		{navio->pecas.vetor3X, navio->pecas.vetor3Y}
	};
	
	for(int i = 0; i < 3; i++)
	{
		// passa as coordenadas para as duas variaveis, pra poder validar se as posiçoes sao validas
		int x = posicoes[i][0];
		int y = posicoes[i][1];
		
		// verifica se a posiçao indicada é menor que 0 e se a posiçao é maior que TAB_SIZE. Detalhe que TAB_SIZE vale 10
		if(x < 0 || x >= TAB_SIZE || y < 0 || y >= TAB_SIZE)
		{
			return 0;
		}
		// verifica se a posiçao é diferente de 0, caso seja diferente de 0 é porque tem um navio nessa posiçao
		if(tabuleiro[x][y] != 0)
		{
			return 0;
		}
	}
	
	// retorna 1, indicando que a posiçao é valida
	return 1;
}

void PosicionarNavio(NAVIO *navio, int tabuleiro[TAB_SIZE][TAB_SIZE])
{
	tabuleiro[navio->pecas.vetor1X][navio->pecas.vetor1Y] = 3;
	tabuleiro[navio->pecas.vetor2X][navio->pecas.vetor2Y] = 3;
	tabuleiro[navio->pecas.vetor3X][navio->pecas.vetor3Y] = 3;
	navio->ativo = 1;
}

int main()
{
	/*
		  0 1 2 3 4 5 6 7 8 9
		  ___________________
		0|0 0 0 0 0 0 0 0 0 0
		1|0 0 0 0 0 0 0 0 0 0
		2|0 0 3 0 0 0 0 0 0 0
		3|0 0 3 0 0 0 0 0 0 0
		4|0 0 3 0 0 0 0 0 0 0
		5|0 0 0 0 0 0 0 0 0 0
		6|0 0 0 0 0 0 0 3 3 3
		7|0 0 0 0 0 0 0 0 0 0
		8|0 0 0 0 0 0 0 0 0 0
		9|0 0 0 0 0 0 0 0 0 0
	*/
	int tabuleiro[TAB_SIZE][TAB_SIZE];
	NAVIO n1;
	NAVIO n2;

	// inicia o tabuleiro com 0
	IniciarTabuleiro(tabuleiro);
	
	// ** navio 1 vetores: peças 1, 2 e 3
	n1.pecas.vetor1X = 2;
	n1.pecas.vetor1Y = 2;
	
	n1.pecas.vetor2X = 3;
	n1.pecas.vetor2Y = 2;
	
	n1.pecas.vetor3X = 4;
	n1.pecas.vetor3Y = 2;
	
	if(ValidarPosicaoDoNavio(&n1, tabuleiro))
	{
		PosicionarNavio(&n1, tabuleiro);
	}
	
	// ** navio 2 vetores: peças 1, 2 e 3
	n2.pecas.vetor1X = 6;
	n2.pecas.vetor1Y = 9;
	
	n2.pecas.vetor2X = 6;
	n2.pecas.vetor2Y = 8;
	
	n2.pecas.vetor3X = 6;
	n2.pecas.vetor3Y = 7;
	
	if(ValidarPosicaoDoNavio(&n2, tabuleiro))
	{
		PosicionarNavio(&n2, tabuleiro);
	}
	
	// exibindo tabuleiro e finalizando o programa
	ExibirTabuleiro(tabuleiro);
	
	
	return 0;
}
