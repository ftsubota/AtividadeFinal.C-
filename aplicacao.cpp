#include "funcoes.cpp"

int main () {
	char opcao = ' ';
	do {
	   opcao = menu();	
	   Aluno aluno[100];
	   switch (opcao) {
	   		case 'A':
	   			for(int i = 0; i <= 100; i++){
	   				inserirDadosAlunos(aluno[i]);
	   		}
	   		break;
	   		case 'B':
	   			realizaLeituraArquivo();
	   		break;
	   		case 'C':
	   			std::cout << "Finalizando aplicacao...\n";
	   		break;
	   		// demais funcoes deverão ser chamadas aqui
	   		default:
	   			std::cout << "Opcao invalida\n Tente Novamente!\n";
	   }
	} while(opcao != 'C');	
}
