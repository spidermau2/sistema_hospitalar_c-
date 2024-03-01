#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define size 50

//Programa possui:
//1- Cadastro de médico(nome, email, cpf, crm e especialidade); 
//2- Cadastro de paciente(nome, rg, cpf e telefone);
//3- Agendamento(nome, cpf, data da consulta, horario);
//4- Cancelamento de consultas.

//Há função para cada tarefa (função para cadastro, outra para agendamento, etc).

void cadastromedico()
{
	char nome[size], email[size], cpf[15];
	char especialidade[size], crm[6], var[20];
	int quest=1, quest2=1;
	FILE *arq;

//O programa cria um txt nomeado com o CRM.
//Nele ficam salvos todos os dados dados do médico,
//Facilitando a localização e a leitura do mesmo.

//Na repetição "do while", o algoritmo está salvando os dados.
	
	do{
		printf("\tBem vindo ao cadastro de medico\n\n");
		printf("(1) Para Cadastrar ou outro valor pra gerar relatorio: ");
		scanf("%d", &quest2);
		
		if(quest2!=1)
		{
			arq=fopen("Relatorios\\Rmedicos.txt", "r");
			if(arq!=NULL)
			{
				system("del Relatorios\\Rmedicos.txt");
			}
			sprintf(var,"copy Medicos\\*.txt Relatorios\\Rmedicos.txt");
			system(var);
			system("cls");
			printf("Relatorio gerado!\n\n");
			system("type Relatorios\\Rmedicos.txt");
		}
		else
		{
			printf("\n\tInsira as informacoes do mesmo:\n");
		
			fflush(stdin);
			
			printf("\nNome: ");
			gets(nome);
			
			printf("\nEmail: ");
			gets(email);
			
			printf("\nCPF: ");
			gets(cpf);
			
			fflush(stdin);	
			printf("\nCRM: ");
			gets(crm);
			
			sprintf(var,"Medicos\\%s.txt", crm);
				
			arq=fopen(var, "r");
			
			//Aqui o algoritmo confere se já não há registro com este CPF
			while(arq!=NULL)
			{
				printf("\nErro: CRM %s ja cadastrado.", crm);
				printf("\nInsira CRM nao cadastrado para continuar: ");
				gets(crm);
				
				fclose(arq);
				
				sprintf(var,"Medicos\\%s.txt", crm);
				arq=fopen(var, "r");
			}
			
			
			fclose(arq);
			
			printf("\nEspecialidade: ");
			gets(especialidade);
			
			//Aqui ele nomeia e abre o arquivo txt como gravação 
			//para salvar os dados dentro
			arq=fopen(var, "w");
			fprintf(arq, "-Nome: %s\n\n", nome);
			fprintf(arq, "-Email: %s\n\n", email);
			fprintf(arq, "-CPF: %s\n\n", cpf);
			fprintf(arq, "-CRM: %s\n\n", crm);
			fprintf(arq, "-Especialidade: %s", especialidade);
			fprintf(arq,"\n______________________\n-");
			
			fclose(arq);
			system("cls");
			printf("Cadastrado com sucesso!");
		}
		printf("\nDigite 1 para novo medico ou outro valor para voltar ao menu principal: ");
		scanf("%d", &quest);
								
		system("cls");
		
			
	}while(quest==1);
}

void cadastropaciente()
{
	char nome[size], rg[size];
	char cpf[11], tel[11], var[20];
	int quest=1, quest2;
	FILE *arq;

//email-rg, crm-telefone, exclui espec
//O programa cria um txt nomeado com o CPF.
//Nele ficam salvos todos os dados dados do paciente,
//Facilitando a localização e a leitura do mesmo.

//Na repetição "do while", o algoritmo está salvando os dados.
	
	do{
		printf("\tBem vindo ao cadastro de pacientes\n\n");
		printf("(1) Para Cadastrar ou outro valor pra gerar relatorio: ");
		scanf("%d", &quest2);
		
		if(quest2!=1)
		{
			arq=fopen("Relatorios\\Rpacientes.txt", "r");
			if(arq!=NULL)
			{
				system("del Relatorios\\Rpacientes.txt");
			}
			sprintf(var,"copy Pacientes\\*.txt Relatorios\\Rpacientes.txt");
			system(var);
			system("cls");
			printf("Relatorio gerado!\n\n");
			system("type Relatorios\\Rpacientes.txt");
		}
		else
		{
			printf("\n\t Insira as informacoes do mesmo:\n");
		
			fflush(stdin);
			
			printf("\nNome: ");
			gets(nome);
			
			printf("\nRG: ");
			gets(rg);
			
			fflush(stdin);
			printf("\nCPF: ");
			gets(cpf);
					
			sprintf(var,"Pacientes\\%s.txt", cpf);
			
			arq=fopen(var, "r");
			
			//Aqui o algoritmo confere se já não há registro com este CPF
			while(arq!=NULL)
			{
				printf("\nErro: CPF %s ja cadastrado.", cpf);
				printf("\nInsira CPF nao cadastrado para continuar: ");
				gets(cpf);
				
				fclose(arq);
				
				sprintf(var,"Pacientes\\%s.txt", cpf);
				arq=fopen(var, "r");
			}
			
			fclose(arq);
			
			fflush(stdin);
			printf("\nTelefone: ");
			gets(tel);
			
			fflush(stdin);
			
			//Aqui ele nomeia o arquivo e o abre como gravação 
			//para salvar os dados dentro
			
			arq=fopen(var, "w");
			
			fprintf(arq, "-Nome: %s\n\n", nome);
			fprintf(arq, "-Rg: %s\n\n", rg);
			fprintf(arq, "-CPF: %s\n\n", cpf);
			fprintf(arq, "-telefone: %s", tel);
			fprintf(arq,"\n______________________\n-");
			
			fclose(arq);
			
			printf("\nCadastrado com sucesso!");
		}
		printf("\nDigite 1 para novo paciente ou outro valor para voltar ao menu principal: ");
		scanf("%d", &quest);
								
		system("cls");
		
			
	}while(quest==1);
}

void agendamento()
{
	FILE *arq;
	int quest=1, quest2, tamdia;
	char dia[6], cpf[11],hora[5];
	char nome[size], var[100];
	
	//O algoritmo cria um .txt para cada dia agendado.
	do
	{
		fflush(stdin);
		printf("\tBem vindo ao agendamento de pacientes");
		printf("\n(Permitido um agendamento por paciente, indifere a unidade)\n\n");
		
		printf("(1) Para agendar ou outro valor pra gerar relatorio: ");
		scanf("%d", &quest2);
		
		if(quest2!=1)
		{
			arq=fopen("Relatorios\\Ragendamento.txt", "r");
			if(arq!=NULL)
			{
				system("del Relatorios\\Ragendamento.txt");
			}
			sprintf(var,"copy Agendamentos\\*.txt Relatorios\\Ragendamentos.txt");
			system(var);
			system("cls");
			printf("Relatorio gerado!\n\n");
			system("type Relatorios\\Ragendamentos.txt");
		}
		else
		{
			printf("\n\nInsira data para agendamento(formato ddmmaa): ");
			gets(dia);
			system("cls");
			
			tamdia=strlen(dia);
			
			while(tamdia!=6)
			{
				printf("\nInsira data no formato ddmmaa: ");
				gets(dia);
				tamdia=strlen(dia);
				system("cls");
			}
			
			sprintf(var,"Agendamentos\\%s.txt", dia);
			arq=fopen(var, "r");
			
			//Se não há txt salvo na data inserida,é criado um novo.
			if(arq==NULL)
			{
				fclose(arq);
				printf("Nao ha agendamentos nesta data, criando nova lista...\n\n");
				
				arq=fopen(var, "w");
				
				fprintf(arq,"\tAgendamentos para ");
				
				for(int i=0;i<=tamdia;i++)
				{
					char c=dia[i];
					fprintf(arq,"%c",c);
					
					if(i==1 || i==3)
					{
						c='/';
						fprintf(arq,"%c", c);
					}
				}
				
				fclose(arq);
			}
			
			fflush(stdin);
			//Pergunta se existe registro com CPF inserido
			//para evitar agendamento de pessoas nao cadastradas.
			printf("Insira CPF do paciente: ");
			gets(cpf);
			
			char var1[100];
			sprintf(var1,"Pacientes\\%s.txt", cpf);
			arq=fopen(var1,"r");
			
			while(arq==NULL)
			{
				fclose(arq);
				printf("\nCPF nao encontrado, Insira um CPF ja cadastrado: ");
				gets(cpf);
				sprintf(var1,"Pacientes\\%s.txt", cpf);
				arq=fopen(var1,"r");
			}
			
			fclose(arq);
			
			system("cls");
			printf("Insira nome do paciente: ");
			gets(nome);
			system("cls");
			
			system("cls");
			printf("Insira hora(formato hh:mm): ");
			gets(hora);
			system("cls");
			
			//Aqui determina se quer unidade A, B ou C.
			char uni;
			printf("Qual unidade deseja ir?\n(A) Unidade A\n(B) Unidade B\n(C) Unidade C\n");
			printf("\nDigite uma opcao: ");
			scanf("%c", &uni);
			uni=toupper(uni);
			system("cls");
			
			fflush(stdin);
			
			while (uni!='A' && uni!='B' && uni!='C')
			{	
				system("cls");
				printf("Nao ha unidade %c, insira novamente:\n", uni);
				scanf("%c", &uni);
				uni=toupper(uni);
				fflush(stdin);
			}
			
			sprintf(var1,"\nUnidade %c - %s - %s - %s\n_________________________________________", uni, cpf, nome, hora);
			
			arq=fopen(var,"a");
			fprintf(arq,"\n%s", var1);
			fprintf(arq,"\n-");
			fclose(arq);	
			printf("\nAgendamento realizado com sucesso!\n", var);
		}
		printf("(1)Para novo agendamento ou outro valor para voltar ao menu principal: ");
		scanf("%d", &quest);
		system("cls");
				
	}while(quest==1);

}

void cancelamento()
{
	//Para cancelar consulta, recepção agirá pelo notepad que abrirá automaticamente.
	
	FILE *arq;
	int quest=1, dia;
	char var[20];
	
	do
	{
		printf("\tBem vindo ao cancelamento de consultas");
		printf("\n\nData da consulta(formato ddmmaa): ");
		scanf("%d", &dia);
		
		sprintf(var,"Agendamentos\\%d.txt",dia);
		arq=fopen(var,"r");
		
		//Checa se há txt com nome da data inserida
		while(arq==NULL)
		{
			system("cls");
			fclose(arq);
			printf("Nao ha agendamentos para esta data.");
			printf("\nInsira data valida: ");
			scanf("%d", &dia);
			sprintf(var,"Agendamentos\\%d.txt",dia);
			arq=fopen(var,"r");
		}
		fclose(arq);
		
		//Abre o notepad para a exclusão dos dados desejados
		printf("\n\nUma tela sera aberta para exclusao de consulta.\n");		
		sprintf(var,"notepad Agendamentos\\%d.txt",dia);
		system("pause");
		system(var);
		
		printf("\n(1)Para cancelar mais consultas ou outro valor para voltar ao menu principal: ");
		scanf("%d", &quest);
	}while(quest==1);
}

void login()
{
	char login[8];
	int senha;
	
	//Login: recepcao
	//Senha: 1234
	printf("Insira Login e senha fornecidos pela empresa\n\n");
	printf("Login: ");
	gets(login);
	printf("\nSenha: ");
	scanf("%d", &senha);
	
	while(!(login=="recepcao") && (!(senha==1234)))
	{
		fflush(stdin);
		system("cls");
		printf("Usuario ou senha incorreto!\nInsira novamente:\n\n");
		printf("Login: ");
		gets(login);
		printf("\nSenha: ");
		scanf("%d", &senha);
	}
	printf("\n\nUsuario e senha Corretos!\n\n");
	system("pause");
}


int main()
{
	login();
	
	CreateDirectory("Medicos", NULL);
	CreateDirectory("Pacientes", NULL);
	CreateDirectory("Agendamentos", NULL);
	CreateDirectory("Relatorios", NULL);	
	
	int quest;
	
	//Ao invés de criar uma função para cada unidade, preferi criar uma que já lida com todas
	//Assim, descomplicando a leitura e o deixando menor.
	
	//Aqui determina o que o usuario desejar (cadastro, agendamento, etc)
	do
	{	
		system("cls");
		printf("Seja bem-vindo ao SICM(Sistema de Informatica para Consultorio Medico)\n\n");
		printf("(1) Cadastro de medico\n(2) Cadastro de paciente\n(3) Agendamento\n(4) Cancelar consulta\n(5) Sair");
		printf("\n\nDigite uma opcao: ");
		scanf("%d", &quest);
		system("cls"); 
		
		if (quest==1)
		{
			cadastromedico();
		}
		else if (quest==2)
		{
			cadastropaciente();
		}
		else if (quest==3)
		{
			agendamento();
		}
		else if (quest==4)
		{
			cancelamento();
		}
	}while(quest!=5); //Cada fim de função volta para esta repetição
					  //fazendo o programa finalizar só quando inserir valor 5 nesta tela
	printf("Programa finalizado!\n");
	return 0;
}
