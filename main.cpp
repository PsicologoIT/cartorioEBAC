#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf);
    
    FILE *file = fopen(arquivo, "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    
    fprintf(file, "%s,", cpf);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    fprintf(file, "%s,", nome);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    fprintf(file, "%s,", sobrenome);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    fprintf(file, "%s", cargo);
    
    fclose(file);
    
    printf("Cadastro realizado com sucesso!\n");
    system("pause");
    
    return 0;
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file = fopen(cpf, "r");
    
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado!.\n");
        system("pause");
        return 1;
    }
    
    printf("\nEssas são as informações do usuário: ");
    
    while (fgets(conteudo, sizeof(conteudo), file) != NULL)
    {
        printf("%s", conteudo);
    }
    
    printf("\n\n");
    fclose(file);
    system("pause");
    return 0;
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuario a ser deletado: ");
    scanf("%s", cpf);
    
    if (remove(cpf) == 0)
    {
        printf("Usuário deletado com sucesso!\n");
    }
    else
    {
        printf("Erro ao deletar o usuário. O arquivo não foi encontrado.\n");
    }
    
    system("pause");
    return 0;
}

int main()
{
    int opcao = 0;
    int laco = 1;
    
    while (laco == 1)
    {
        system("cls"); // Limpa a tela no Windows
        setlocale(LC_ALL, "Portuguese");
        
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada no Menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 Sair do sistema\n\n");
        printf("Opção: ");
        
        scanf("%d", &opcao);
        system("cls");
        
        switch (opcao)
        {
            case 1:
                registro();
                break;
                
            case 2:
                consulta();
                break;
                
            case 3:
                deletar();
                break;

            case 4:
                printf("Obrigado por utilizar o sistema!");
                return 0;
                break;
                
            default:
                printf("Esta opção não está disponível!\n");
                system("pause");
                break;
        }
    }

    return 0;
}

