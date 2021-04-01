#include <stdio.h>
#include <string.h>
#include <stdlib.h>

intro(){	
	
	printf(" ------------------------------------------------------------- \n");
	printf("|                          AGENDA                             |\n");
	printf(" ------------------------------------------------------------- \n");
	printf("| 1 - Cadastrar novo contato                                  |\n");
	printf("|_____________________________________________________________|\n");
    printf("| 2 - Exibir Contatos                                         |\n");
    printf("|_____________________________________________________________|\n");
    printf("| 3 - Procurar Contato                                        |\n");
	printf("|_____________________________________________________________|\n");
	
}
	
	
typedef struct Cliente{
	int primary_key;
	char nome[200];
	char data_nasc[20];
	char numero[30];
	char observacoes[300];
	} Pessoa;




int main() {
	//Declara��o de Vari�veis
	Pessoa a[10];
	int controle = 0, esc, esc2 = 0,i=0,j=0, m=0, n=0;
	char control[200],name_esc[200];
	
	//INSTANCIANDO VALORES PRIMARIOS DO VETOR
	for(i=0;i<=9;i++)
	{
		strcpy(a[i].nome, "\0");	
	}
	
	
	
	//Controle de tempo de dura��o da aplica��o
	while (controle == 0) {
		
		//Apresenta��o do Menu da Aplica��o e Capta��o da escolha do usu�rio
		intro();
        printf("\n.: ");
        scanf("%i",&esc);
		
		switch (esc) {
			
			case 1:
				//GRAVANDO NOVOS USU�RIOS
                if(j>=10){
                    printf("\nAgenda lotada. Impossivel efetuar a operacao\n");
                    system("pause");
                    system("cls");
                }else{

                    for(i=j; i<10; i++){ 
                        
                        system("cls");
                        fflush(stdin);

                        printf("Nome: ");
                        fgets(a[i].nome, 200, stdin); //recebendo nome do usu�rio
                        fflush(stdin);
                        
                        printf("Data de Nascimento: ");
                        fgets(a[i].data_nasc, 20, stdin);//recebendo data de nascimento
                        fflush(stdin);

                        printf("Numero: ");
                        fgets(a[i].numero, 30, stdin); //recebendo valor do n�mero
                        fflush(stdin);

                        printf("Obs: ");
                        fgets(a[i].observacoes, 300, stdin); //recebendo valor da cidade
                        fflush(stdin);

                        printf("Deseja adicionar mais contatos? (1-SIM | 2-NAO)\n.: "); 
                        scanf("%i", &esc2); //colhendo a informa��o se o usu�rio deseja adicionar mais contatos
                        fflush(stdin);
                        //Estrutura de valida��o baseado na escolha de adicionar ou nao novos usu�rios

                        
                        if(esc2 == 1){ 

                            if (i == 9){
                                system("cls");
                                printf("\nAgenda Lotada. Impossivel efetuar operacao!\n");
                                system("pause");
                                system("cls");
                            }
                            a[j].primary_key = j+1; //setando valor da chave prim�ria
                            j++;
                        }else{
                            a[j].primary_key = j+1; //setando valor da chave prim�ria
                            j++;
                            system("cls");
                            i = 10;
                            
                        }                    	
                    }
                }    
            break;

            case 2:
                //LISTANDO USU�RIOS
                system("cls");
                printf("|------------------------------------------------------------|\n");
                printf("|                           USERS                            |\n");
                printf("|------------------------------------------------------------|\n\n\n");
				for(i=0; i<=9; i++)
                {
                	fflush(stdin);
                    if(a[i].nome[0] == NULL)
					{
                        
                    }
                    else
					{
						printf("_____________________________________________________________\n");
                    	printf("| Contato %i                                                  |\n",i+1);
                    	printf("|____________________________________________________________|\n");
                        printf("| Nome: %s \n",a[i].nome);
                        printf("|------------------------------------------------------------|\n");
                        printf("| Numero: %s \n",a[i].numero);
                        printf("|------------------------------------------------------------|\n");
						printf("| Data de Nascimento: %s \n",a[i].data_nasc);
                        printf("|------------------------------------------------------------|\n");
						printf("| Observacoes: %s \n",a[i].observacoes);
                        printf("|____________________________________________________________|\n\n\n");
					}
                }
				system("pause");
				system("cls");
            break;

            case 3:
                
            
                printf("_____________________________________________________________\n");
                printf("|                     Procurar Contato                       |\n");
                printf("|____________________________________________________________|\n");
                printf("|Nome: ");

                fflush(stdin);
                fgets(name_esc, 200, stdin);

                printf("\n|procurando ...\n\n");
                system("pause");
                system("cls");

                m = strlen(name_esc);
                name_esc[m-1] = "\0";

                for(i=0; i<=9; i++)
                {
                	fflush(stdin);   

                    n = strlen(a[i].nome);
                    a[i].nome[n-1] = "\0";

                    if(strcmp(a[i].nome, name_esc) == 0)
					{
                        printf("_____________________________________________________________\n");
                    	printf("| Contato %i                                                  |\n",i+1);
                    	printf("|____________________________________________________________|\n");
                        printf("| Nome: %s \n",a[i].nome);
                        printf("|------------------------------------------------------------|\n");
                        printf("| Numero: %s \n",a[i].numero);
                        printf("|------------------------------------------------------------|\n");
						printf("| Data de Nascimento: %s \n",a[i].data_nasc);
                        printf("|------------------------------------------------------------|\n");
						printf("| Observacoes: %s \n",a[i].observacoes);
                        printf("|____________________________________________________________|\n\n\n");
                        
                    }
                    else
					{
                        if(i==9){
                            printf("Usuario nao encontrado\n");
                            goto fim;
                        }
                        
					}
                }
                fim:
                system("pause");
                system("cls");
            break;

            default:
                printf("Opcao invalida");
        }
    }
}					  
