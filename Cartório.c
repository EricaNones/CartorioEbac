#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaco de memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca reponsável por cuidar da strings


int registro() //Responsável por cadastrar o usuário no sistema
{	
	//ÍNICIO Criação de variáveis/strig
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//FINAL Criação de variáveis/strig
	
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);  //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza (a)
	fprintf(file,","); //adiciona uma vingula
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); //aqui é escrito o nome
	scanf("%s",nome); // aqui lê o que foi escrito
	
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
	scanf("%s",cpf); // lê as strings que é um conjunto de
  	
	FILE *file; // acessa o FILE *para criar um arquivo
	file = fopen(cpf,"r"); //nome do arquivo = ao que ele tem que fazer,neste caso,ler o cpf
  	
	if(file == NULL)
{
	printf("Não foi possível abrir o arquivo, não localizado!.\n");
}
	
	while(fgets(conteudo, 100, file) != NULL)
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
	system ("pause");
}



int deletar()

{	
	char cpf[40];

    printf("Digite o CPF do usuário a ser deletado:");
    scanf("%s",cpf);

    FILE *file; 
    file = fopen(cpf,"r"); 	
    
    if(file == NULL)
    {
        printf("\nUsuário não encontrado.");
        printf("\n\n");
        system("pause");
        return 0; // retorna ao menu
    }
    fclose(file);
    remove(cpf);
     
   {
	 	printf("\nUsuário deletado com sucesso! ");
    	printf("\n\n");
    	system("pause");
	}
}



int main() 
{
	int opcao=0; //Definindo variável
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); // responsável por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf ("### Cartório da EBAC ###\n\n"); //Início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n"); 
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n"); //Final do menu
	   	printf("\t4 - Sair do sistema\n");
	    printf("Opção: ");
	
        scanf("%d",&opcao); //Armazenando a escolha do usuário
    
        system("cls");
        
        switch(opcao)
        {	
        	case 1: 
        	registro(); //chamada de função
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
				
		}
	
	} 
}
