#include <stdio.h>

struct CONTATO
{
    char nome[100];
    char Numero[100];
    char aniversario[100];
};

struct LOGIN
{
    char utilizador[100];
    char senha[100];
};

int op;
FILE*arquivo;
FILE*arquivoTemp;
char excluir[100];
char encontrar[100];
char comparadorLogin[100];
char comparadorSenha[100];
char letra[10];


void Cadastro()
{
    arquivo=fopen("contatos.txt","ab");
    struct CONTATO contato;

    if(arquivo==NULL)
    {
        printf("Erro ao executar!\n");
    }else
    {
        do
        {
        system("cls");
        printf("Informe o nome do contato:\n");
        scanf("%s",&contato.nome);
        printf("Informe o numero do contato:\n");
        scanf("%s",&contato.Numero);
        printf("Informe o aniversario:\n");
        scanf("%s",&contato.aniversario);

        fwrite(&contato, sizeof(struct CONTATO),1,arquivo);

        printf("Contato salvo com sucesso!\n");
        printf("deseja adcionar um novo contato ? (1 - SIM/2 - NAO)\n");
        scanf("%d",&op);
        fclose(arquivo);
        MenuPrincipal();
        }while(op!=2);
    }

}
void Pesquisar()
{
    arquivo=fopen("contatos.txt","rb");
    struct CONTATO contatoPesquisar;

    if(arquivo==NULL)
    {
        printf("Erro ao executar!\n");
    }else
    {
        while(fread(&contatoPesquisar, sizeof(struct CONTATO),1,arquivo)==1)
        {
            printf("%s\n", &contatoPesquisar.nome);
            printf("%s\n", &contatoPesquisar.Numero);
            printf("%s\n", &contatoPesquisar.aniversario);
            printf("--------------------------------------------\n");

        }
        fclose(arquivo);
        system("pause");
        MenuPrincipal();

    }
}

void PesquisarEspecifico()
{
    arquivo=fopen("contatos.txt","rb");
    struct CONTATO Filtrar;

    if(arquivo==NULL)
    {
        printf("erro ao executar!\n");
    }else
    {
        printf("digite o numero do contato:\n");
        scanf("%s",&encontrar);

        while(fread(&Filtrar,sizeof(struct CONTATO),1,arquivo)==1)
        {
            if(strcmp(encontrar,Filtrar.Numero)==0)
            {
            printf("%s\n", &Filtrar.nome);
            printf("%s\n", &Filtrar.Numero);
            printf("%s\n", &Filtrar.aniversario);
            printf("--------------------------------------------\n");
            }
        }
        system("pause");
        fclose(arquivo);
        MenuPrincipal();
    }

}

void Excluir()
{
    arquivo=fopen("contatos.txt","rb");
    arquivoTemp=fopen("contatosTemp.txt","ab");
    struct CONTATO contatosExclu;

     if(arquivo==NULL || arquivoTemp==NULL)
     {
         printf("erro ao executar!\n");
     }else
     {
        printf("informe o numero do contato para ser excluido:\n");
        scanf("%s",&excluir);
        while(fread(&contatosExclu, sizeof(struct CONTATO),1,arquivo)==1)
        {
            if(strcmp(excluir,contatosExclu.Numero)!=0)
            {
                fwrite(&contatosExclu,sizeof(struct CONTATO),1,arquivoTemp);
            }
        }

    }
    fclose(arquivo);
    fclose(arquivoTemp);
    remove("contatos.txt");
    rename("contatosTemp.txt","contatos.txt");
    printf("contato excluido!\n");
    system("pause");
    MenuPrincipal();





}

void listar_por_inicial()
{
    arquivo=fopen("contatos.txt","rb");
    if(arquivo==NULL)
    {
         printf("erro ao executar!\n");
    }else
    {
        printf("informe a letra inicial do contato:");
        scanf("%s");
    }
}

void MenuConfiguracoes()
{
    system("cls");
    printf("=====================================\n");
    printf("AGENDA ELETRONICA\n");
    printf("=====================================\n\n");
    printf("1 - cadastrar usuario do sistema\n");
    printf("2 - listar usuarios do sistema\n");
    printf("3 - excluir usuario\n");
    printf("4 - voltar\n");
    scanf("%d", &op);

    switch(op)
    {
    case 1:
        CadastroUsuario();
        break;
    case 2 :
        ListarUsuario();
        break;
    case 3 :
        ExcluirUsuario();
        break;
    case 4:
         MenuPrincipal();
        break;


    }


}


void CadastroUsuario()
{
    arquivo=fopen("usuarios.txt","ab");
    struct LOGIN login;

    if(arquivo==NULL)
    {
        printf("Erro ao executar!\n");
    }else
    {
        do
        {
        system("cls");
        printf("Informe o nome do login:\n");
        scanf("%s",&login.utilizador);
        printf("Informe a senha:\n");
        scanf("%s",&login.senha);

        fwrite(&login, sizeof(struct LOGIN),1,arquivo);

        printf("login salvo com sucesso!\n");
        printf("deseja adcionar um novo login ? (1 - SIM/2 - NAO)\n");
        scanf("%d",&op);
        fclose(arquivo);
        MenuConfiguracoes();
        }while(op!=2);
   }

}

void ListarUsuario()
{
    arquivo=fopen("usuarios.txt","rb");
    struct LOGIN loginListar;

    if(arquivo==NULL)
    {
        printf("Erro ao executar!\n");
    }else
    {
        while(fread(&loginListar, sizeof(struct LOGIN),1,arquivo)==1)
        {
            printf("Login: %s\n", &loginListar.utilizador);
            printf("Senha: %s\n", &loginListar.senha);
            printf("--------------------------------------------\n");

        }
        fclose(arquivo);
        system("pause");
        MenuConfiguracoes();

    }
}

void ExcluirUsuario()
{
    arquivo=fopen("usuarios.txt","rb");
    arquivoTemp=fopen("usuariosTemp.txt","ab");
    struct LOGIN loginExclu;

     if(arquivo==NULL || arquivoTemp==NULL)
     {
         printf("erro ao executar!\n");
     }else
     {
        printf("informe o login para ser excluido:\n");
        scanf("%s",&excluir);
        while(fread(&loginExclu, sizeof(struct LOGIN),1,arquivo)==1)
        {
            if(strcmp(excluir,loginExclu.utilizador)!=0)
            {
                fwrite(&loginExclu,sizeof(struct LOGIN),1,arquivoTemp);
            }
        }

    }
    fclose(arquivo);
    fclose(arquivoTemp);
    remove("usuarios.txt");
    rename("usuariosTemp.txt","usuarios.txt");
    printf("usuario excluido!\n");
    system("pause");
    MenuConfiguracoes();

}

void TelaLogin()
{
    arquivo=fopen("usuarios.txt","rb");
    struct LOGIN telalogin;

    if(arquivo==NULL)
    {
        printf("erro ao executar!\n");

    }else
    {
        printf("login:\n");
        scanf("%s",&comparadorLogin);

        printf("senha:\n");
        scanf("%s",&comparadorSenha);

      while(fread(&telalogin,sizeof(struct LOGIN),1,arquivo)==1)
      {
          if(strcmp(comparadorLogin,telalogin.utilizador)==0&&strcmp(comparadorSenha,telalogin.senha)==0)
          {
              break;
          }
      }
          if(strcmp(comparadorLogin,telalogin.utilizador)==0&&strcmp(comparadorSenha,telalogin.senha)==0)
          {
              printf("login efetuado com sucesso!\n");
              system("pause");
              fclose(arquivo);
              MenuPrincipal();
          }else
          {
              printf("usuario ou senha incorretos\n");
              system("pause");
              system("cls");
              TelaLogin();
          }
    }
}

void MenuPrincipal()
{

    while(op!=7)
    {
    system("cls");
    printf("=====================================\n");
    printf("AGENDA ELETRONICA\n");
    printf("=====================================\n\n");
    printf("1 - Registrar contato novo\n");
    printf("2 - Contatos cadastrados\n");
    printf("3 - Pesquisar contato\n");
    printf("4 - Excluir Contato\n");
    printf("5 - Listar por inicial\n");
    printf("6 - Configuracoes\n");
    printf("7 - Sair\n");
    scanf("%d",&op);

    switch(op)
          {
          case 1:
            Cadastro();
            break;
          case 2:
            Pesquisar();
            break;
          case 3:
            PesquisarEspecifico();
            break;
          case 4:
            Excluir();
            break;
          case 5:
            //
            break;
          case 6:
             MenuConfiguracoes();
            break;
          case 7:
            printf("FIM DO PROGRAMA\n");
            break;

          }
    }
}

int main()
{
TelaLogin();

}

