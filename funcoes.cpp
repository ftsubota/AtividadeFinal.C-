#include "funcoes.h"

char menu () {	
	char escolha = ' ';
	std::cout << "\n=====SELECIONE UMA OPCAO ABAIXO======";
	std::cout << "\nDIGITE A LETRA COM A FUNCAO DESEJADA:";
	std::cout << "\n==========A - CADASTRAR ALUNO========";
	std::cout << "\n==========B - FAZER A LEITURA========";
	std::cout << "\n==========C - FINALIZAR APLICACAO====\n";
	std::cin >> escolha;
	system("cls");
	return escolha;
}

bool cadastraAluno (Aluno aluno) {
	std::ofstream arquivo;
	arquivo.open("database.csv", std::fstream::app);
	
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return 0;	
	}
	
	arquivo	<< aluno.nome << ";" 
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << ";"
			<< aluno.sub << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
			   
	arquivo.close();
	return true;
}

void inserirDadosAlunos(Aluno aluno) {
	std::cout<< "Digite o nome do aluno: ";
	std::cin >> aluno.nome;
	std::cout<< "Digite a matricula do aluno: ";
	std::cin >> aluno.matricula;
	std::cout<< "Digite a note da AEP1: ";
	std::cin >> aluno.aep1;
	std::cout<< "Digite a nota da prova 1: ";
	std::cin >> aluno.prova1;
	std::cout<< "Diigite a nota da AEP 2: ";
	std::cin >> aluno.aep2;
	std::cout<< "Digite a nota da prova 2: ";
	std::cin >> aluno.prova2;
	//para calcular a media de cada aluno e definir a situacao final
aluno.media = ((aluno.aep1 + aluno.prova1)/2) + ((aluno.aep2 + aluno.prova2)/2);
	if (aluno.media >= 6){
		aluno.status = "Aprovado!";
	}else{
		std::cout<< "Qual o valor da nota sub: ";
		aluno.media = ((aluno.aep1 + aluno.prova1)/2) + ((aluno.aep2 + aluno.prova2 + aluno.sub)/3);
	if(aluno.media >= 6){
		aluno.status = "Aprovado!";
	}else{
		aluno.status = "Reprovado!";
	}
	}
}
	
	


bool realizaLeituraArquivo () {
	std::ifstream arquivo;
	arquivo.open("database.csv");
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	std::string linha;
	int indexAluno = 0;
	while (std::getline(arquivo, linha)) {
//		std::cout << linha << "\n"; string == array char
		int coluna = 0;
		int controleColuna = 0;
		std::string conteudo = "";
		for (int i = 0; i < linha.size(); i++) {
			if (coluna == 1 && controleColuna == 0)  {
				alunos[indexAluno].nome = conteudo;	
				conteudo = "";
				controleColuna = 1;
			} else if (coluna == 2 && controleColuna == 1) {
				alunos[indexAluno].matricula = conteudo;	
				conteudo = "";
				controleColuna = 2;
			}
			if (linha[i] == ';') {
				coluna++;				
				continue;
			}
			conteudo.push_back(linha[i]);					
		}
		indexAluno++;
	}
	arquivo.close();
	
	for (int i = 0; i < 100; i++) {
		std::cout << "Aluno n " << i+1 << "\n";
		std::cout << "Nome: " << alunos[i].nome << "\n";
		std::cout << "Matricula: " << alunos[i].matricula << "\n";
	}
	
	return true;
}

	
	


