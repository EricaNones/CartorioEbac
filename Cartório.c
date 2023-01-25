#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espaco de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca repons�vel por cuidar da strings


int registro() //Respons�vel por cadastrar o usu�rio no sistema
{	
	//�NICIO Cria��o de vari�veis/strig
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//FINAL Cria��o de vari�veis/strig
	
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);  //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza (a)
	fprintf(file,","); //adiciona uma vingula
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); //aqui � escrito o nome
	scanf("%s",nome); // aqui l� o que foi escrito
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause"); //o sistema pede para que clique em qualquer tecla para retornar o menu
}


int consulta()

{	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); // l� as strings que � um conjunto de
  	
	FILE *file; // acessa o FILE *para criar um arquivo
	file = fopen(cpf,"r"); //nome do arquivo = ao que ele tem que fazer,neste caso,ler o cpf
  	
	if(file == NULL)
{
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
}
	
	while(fgets(conteudo, 100, file) != NULL)
{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
	system ("pause");
}



int deletar()

{	
	char cpf[40];

    printf("Digite o CPF do usu�rio a ser deletado:");
    scanf("%s",cpf);

    FILE *file; 
    file = fopen(cpf,"r"); 	
    
    if(file == NULL)
    {
        printf("\nUsu�rio n�o encontrado.");
        printf("\n\n");
        system("pause");
        return 0; // retorna ao menu
    }
    fclose(file);
    remove(cpf);
     
   {
	 	printf("\nUsu�rio deletado com sucesso! ");
    	printf("\n\n");
    	system("pause");
	}
}



int main() 
{
	int opcao=0; //Definindo vari�vel
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); // respons�vel por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf ("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n"); 
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n"); //Final do menu
	   	printf("\t4 - Sair do sistema\n");
	    printf("Op��o: ");
	
        scanf("%d",&opcao); //Armazenando a escolha do usu�rio
    
        system("cls");
        
        switch(opcao)
        {	
        	case 1: 
        	registro(); //chamada de fun��o
	    	break;
	    	
	    	case 2:
	    	consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
				
		}
	
	} 
}
