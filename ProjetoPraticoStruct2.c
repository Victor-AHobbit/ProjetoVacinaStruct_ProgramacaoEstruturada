//Nome completo: Victor Araújo da Silva Brito
//Matricula: UC21105910
//Curso: Ciências da Computação

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

//Variavel Global
int contador = 0;

//Struct Endereco
typedef struct
{
    char estado[100], cidade[100], rua[100], casa[100], CEP[100];

} cadastra_endereco;

//Struct Usuario
typedef struct
{
    int Id;
    char nome[100], email[100], sexo[100];
    cadastra_endereco endereco;
    double altura;
    bool vacina;
} cadastra_usuario;

//Struct Endereco Backuo
typedef struct
{
    char estadoBackup[100], cidadeBackup[100], ruaBackup[100], casaBackup[100], CEPBackup[100];

} backup_endereco;

//Struct Usuario Backup
typedef struct
{
    int IdBackup;
    char nomeBackup[100], emailBackup[100], sexoBackup[100];
    backup_endereco enderecoBackup;
    double alturaBackup;
    bool vacinaBackup;
} backup_usuario;

//Struct Procurar
typedef struct
{
    int procurarId;
    char procurarEmail[100];
} procurarInfos;

//Funções==============================================================
//Cadastrar Usuario
void adicionarUsuario(cadastra_usuario *addUsuario);
void criaId(cadastra_usuario *addUsuario);
void criaNome(cadastra_usuario *addUsuario, int numeroUsuario);
void criaEmail(cadastra_usuario *addUsuario, int numeroUsuario);
void criaSexo(cadastra_usuario *addUsuario, int numeroUsuario);
void criaEndereco(cadastra_usuario *addUsuario, int numeroUsuario);
void criaEstado(cadastra_usuario *addUsuario, int numeroUsuario);
void criaCidade(cadastra_usuario *addUsuario, int numeroUsuario);
void criaAltura(cadastra_usuario *addUsuario, int numeroUsuario);
void criaVacina(cadastra_usuario *addUsuario, int numeroUsuario);
//Editar Usuario
void editarUsuario(cadastra_usuario *addUsuario, procurarInfos *procurarUser);
//Excluir Usuario
void excluirUsuario(cadastra_usuario *excluirUsuario, procurarInfos *procurarUser);
//Buscar Usuario ID/Email
void buscarMenu(cadastra_usuario *addUsuario, procurarInfos *procurarUser);
int buscarId(cadastra_usuario *addUsuario, procurarInfos *procurarUser);
int buscarEmail(cadastra_usuario *addUsuario, procurarInfos *procurarUser);
//Listar Usuario
void listarUsuario(cadastra_usuario *addUsuario);
//Backup Usuario
void backupUsuarios(cadastra_usuario *usuario, backup_usuario *backup);
//Mostrar Usuario
void apresentarUsuario(cadastra_usuario *addUsuario, int numeroUsuario);
//INT MAIN============================================================

int main()
{
    int menu = 0;
    cadastra_usuario usuario[1000];
    procurarInfos procurado[1000];
    backup_usuario backupUser[1000];

    //MENU
    do
    {
        system("cls");
        printf("\t\t\t     _-_-_-_-_-_-[BEM VINDO AO PROGRAMA USUARIO]-_-_-_-_-_-_\n");
        printf("\n\n\t\t\t\t|| [1]Adicionar Usuario || [2]Editar Usuario   ||");
        printf("\n\n\t\t\t\t|| [3]Excluir Usuario   || [4]Buscar Usuario   ||");
        printf("\n\n\t\t\t\t|| [5]Listar Usuarios   || [6]Realizar Backup  ||");
        printf("\n\n\t\t\t\t|| [7]Creditos...       || [8]Fechar Programa  ||");
        printf("\n\n\t\t\t  SELECIONE UMA DAS OPCOES A CIMA PARA CONTINUAR O PROGRAMA: ");
        fflush(stdin);
        scanf("%d", &menu);

        while (menu < 1 || menu > 8)
        {
            printf("\n\t\t\t\t  Menu invalido, digite apenas os disponiveis: ");
            fflush(stdin);
            scanf("%d", &menu);
        }

        switch (menu)
        {
        case 1:
            adicionarUsuario(usuario);
            break;
        case 2:
            editarUsuario(usuario, procurado);
            break;
        case 3:
            excluirUsuario(usuario, procurado);
            break;
        case 4:
            buscarMenu(usuario, procurado);
            break;
        case 5:
            listarUsuario(usuario);
            break;
        case 6:
            backupUsuarios(usuario, backupUser);
            break;
        case 7:
            system("cls");
            printf("Codigo feito por Victor Araujo da Silva Brito...\n");
            printf("Matricula: UC21105910...\n");
            printf("Curso: Ciencias da Computacao\n");
            getch();
            break;
        default:
            break;
        }

    } while (menu != 8);

    return 0;
}

void adicionarUsuario(cadastra_usuario *addUsuario)
{
    int menu = 1;

    //ADICIONAR USUARIO
    do
    {
        system("cls");
        printf("_-_-_-_-_-_-_-_ ADICIONAR USUARIO _-_-_-_-_-_-_-_\n");
        criaId(addUsuario);
        criaNome(addUsuario, contador);
        criaEmail(addUsuario, contador);
        //criaSexo(addUsuario, contador);
        //criaEndereco(addUsuario, contador);
        //criaAltura(addUsuario, contador);
        //criaVacina(addUsuario, contador);

        //MOSTRAR USUARIO
        apresentarUsuario(addUsuario, contador);
        contador++;
        do
        {
            printf("\nDeseja cadastrar outro usuario?( 1 - [SIM] || 2 - [NAO] ): ");
            fflush(stdin);
            scanf("%d", &menu);
        } while (menu < 1 || menu > 2);
    } while (menu == 1);
}

void criaId(cadastra_usuario *addUsuario)
{
    int i = 0;
    srand(time(NULL));
    addUsuario[contador].Id = (rand() % 1000);
    for (i = 0; i < contador; i++)
    {
        if (addUsuario[contador].Id == addUsuario[i].Id)
        {
            addUsuario[contador].Id = (rand() % 1000);
            i = 0;
        }
    }
}

void criaNome(cadastra_usuario *addUsuario, int numeroUsuario)
{
    do
    {
        printf("\nDigite o nome a ser cadastrado: ");
        fflush(stdin);
        gets(addUsuario[numeroUsuario].nome);
        if (strlen(addUsuario[numeroUsuario].nome) < 2)
        {
            printf("\nNome invalido! Digite novamente: ");
            fflush(stdin);
            gets(addUsuario[numeroUsuario].nome);
        }
    } while (strlen(addUsuario[numeroUsuario].nome) < 2);
}

void criaEmail(cadastra_usuario *addUsuario, int numeroUsuario)
{
    do
    {
        printf("\nDigite o email a ser cadastrado(Necessario um @): ");
        fflush(stdin);
        gets(addUsuario[numeroUsuario].email);
        if (strchr(addUsuario[numeroUsuario].email, '@') == NULL)
        {
            printf("\nEmail nao identificado! Digite novamente: ");
            fflush(stdin);
            gets(addUsuario[numeroUsuario].email);
        }

    } while (strchr(addUsuario[numeroUsuario].email, '@') == NULL);
}

void criaSexo(cadastra_usuario *addUsuario, int numeroUsuario)
{
    do
    {
        printf("\nDigite o sexo a ser registrado(Masculino, Feminino ou Nao declarar): ");
        fflush(stdin);
        gets(addUsuario[numeroUsuario].sexo);
        if ((stricmp(addUsuario[numeroUsuario].sexo, "Feminino") != 0) && (stricmp(addUsuario[numeroUsuario].sexo, "Masculino")) != 0 && (stricmp(addUsuario[numeroUsuario].sexo, "Nao declarar")))
        {
            printf("\nSexo digitado invalido! Digite novamente: ");
            fflush(stdin);
            gets(addUsuario[numeroUsuario].sexo);
        }

    } while ((stricmp(addUsuario[numeroUsuario].sexo, "Feminino") != 0) && (stricmp(addUsuario[numeroUsuario].sexo, "Masculino")) != 0 && (stricmp(addUsuario[numeroUsuario].sexo, "Nao declarar")));
}

void criaEndereco(cadastra_usuario *addUsuario, int numeroUsuario)
{
    criaEstado(addUsuario, contador);
    criaCidade(addUsuario, contador);
    criaRua(addUsuario, contador);
    criaCasa(addUsuario, contador);
    criaCEP(addUsuario, contador);
}

void criaEstado(cadastra_usuario *addUsuario, int numeroUsuario)
{
    do
    {
        printf("\nDigite o estado onde mora: ");
        fflush(stdin);
        gets(addUsuario[numeroUsuario].endereco.estado);
        if (strlen(addUsuario[numeroUsuario].endereco.estado) > 3 || strlen(addUsuario[numeroUsuario].endereco.estado) < 1)
        {
            printf("\nEstado invalido! Digite novamente: ");
            fflush(stdin);
            gets(addUsuario[numeroUsuario].endereco.estado);
        }

    } while (strlen(addUsuario[numeroUsuario].endereco.estado) > 3 || strlen(addUsuario[numeroUsuario].endereco.estado) < 1);
}

void criaCidade(cadastra_usuario *addUsuario, int numeroUsuario)
{
    do
    {
        printf("\nDigite a cidade aonde mora: ");
        fflush(stdin);
        gets(addUsuario[numeroUsuario].endereco.cidade);
        if (strlen(addUsuario[numeroUsuario].endereco.cidade) < 2)
        {
            printf("\nCidade invalida! Digite novamente: ");
            fflush(stdin);
            gets(addUsuario[numeroUsuario].endereco.cidade);
        }

    } while (strlen(addUsuario[numeroUsuario].endereco.cidade) < 2);
}

void criaRua(cadastra_usuario *addUsuario, int numeroUsuario)
{
    do
    {
        printf("\nDigite o nome/numero da rua aonde mora: ");
        fflush(stdin);
        gets(addUsuario[numeroUsuario].endereco.rua);
        if (strlen(addUsuario[numeroUsuario].endereco.rua) < 1)
        {
            printf("\nRua invalida! Digite novamente(Exemplo: Rua 1): ");
            fflush(stdin);
            gets(addUsuario[numeroUsuario].endereco.rua);
        }

    } while (strlen(addUsuario[numeroUsuario].endereco.rua) < 1);
}

void criaCasa(cadastra_usuario *addUsuario, int numeroUsuario)
{
    do
    {
        printf("\nDigite o numero da casa onde mora: ");
        fflush(stdin);
        gets(addUsuario[numeroUsuario].endereco.casa);
        if (strlen(addUsuario[numeroUsuario].endereco.casa) < 1 || strlen(addUsuario[numeroUsuario].endereco.casa) > 4)
        {
            printf("\nCasa invalida! Digite novamente: ");
            fflush(stdin);
            gets(addUsuario[numeroUsuario].endereco.casa);
        }

    } while (strlen(addUsuario[numeroUsuario].endereco.casa) < 1 || strlen(addUsuario[numeroUsuario].endereco.casa) > 4);
}

void criaCEP(cadastra_usuario *addUsuario, int numeroUsuario)
{
    do
    {
        printf("\nDigite seu CEP: ");
        fflush(stdin);
        gets(addUsuario[numeroUsuario].endereco.CEP);
        if (strlen(addUsuario[numeroUsuario].endereco.CEP) < 8 || strlen(addUsuario[numeroUsuario].endereco.CEP) > 8)
        {
            printf("\nCEP invalido! Digite novamente: ");
            fflush(stdin);
            gets(addUsuario[numeroUsuario].endereco.CEP);
        }

    } while (strlen(addUsuario[numeroUsuario].endereco.CEP) < 8 || strlen(addUsuario[numeroUsuario].endereco.CEP) > 8);
}

void criaAltura(cadastra_usuario *addUsuario, int numeroUsuario)
{
    do
    {
        printf("\nDigite a altura a ser cadastrada: ");
        fflush(stdin);
        scanf("%lf", &addUsuario[numeroUsuario].altura);
        if (addUsuario[numeroUsuario].altura < 1 || addUsuario[numeroUsuario].altura > 2)
        {
            printf("\nAltura invalida! Digite novamente: ");
            fflush(stdin);
            scanf("%lf", &addUsuario[numeroUsuario].altura);
        }

    } while (addUsuario[numeroUsuario].altura < 1 || addUsuario[numeroUsuario].altura > 2);
}

void criaVacina(cadastra_usuario *addUsuario, int numeroUsuario)
{
    int confirmador = 1;
    char vacinado[10];

    do
    {
        printf("\nDigite se ja tomou a vacina(Responder com sim ou nao): ");
        fflush(stdin);
        gets(vacinado);
        if (stricmp(vacinado, "Sim") == 0)
        {
            addUsuario[numeroUsuario].vacina = true;
            confirmador = 0;
        }
        else if ((stricmp(vacinado, "Nao") == 0))
        {
            addUsuario[numeroUsuario].vacina = false;
            confirmador = 0;
        }
        else
        {
            printf("\nInvalido, digite apenas sim ou nao");
        }

    } while (confirmador == 1);
}

void editarUsuario(cadastra_usuario *addUsuario, procurarInfos *procurarUser)
{
    int menu, i;

    system("cls");
    printf("_-_-_-_-_-_-_-_-_-_-_EDICAO DE USUARIO-_-_-_-_-_-_-_-_-_\n");
    printf("\n1 - Procurar por Id");
    printf("\n2 - Procurar por Email");
    printf("\n3 - Voltar ao Menu");
    printf("\n_-_-_-_-_-_-_-_ DIGITE O NUMERO DA OPCAO PARA PROSSEGUIR_-_-_-_-_-_-_-_ \n");
    fflush(stdin);
    scanf("%d", &menu);
    switch (menu)
    {

    case 1:
        system("cls");
        printf("Digite o ID que deseja procurar: ");
        fflush(stdin);
        scanf("%d", &procurarUser->procurarId);
        for (i = 0; i < contador; i++)
        {
            if (addUsuario[i].Id == procurarUser->procurarId)
            {
                apresentarUsuario(addUsuario, i);
                do
                {
                    system("cls");
                    printf("_-_-_-_-_-_-_-_ SELECIONE A OPCAO QUE DESEJA _-_-_-_-_-_-_-_\n\n");
                    printf("1 - Editar nome\n");
                    printf("2 - Editar email\n");
                    printf("3 - Editar sexo\n");
                    printf("4 - Editar endereco\n");
                    printf("5 - Editar altura\n");
                    printf("6 - Editar vacina\n");
                    printf("7 - Voltar ao menu\n");
                    fflush(stdin);
                    scanf("%d", &menu);
                    do
                    {
                        switch (menu)
                        {
                        case 1:
                            criaNome(addUsuario, i);
                            break;
                        case 2:
                            criaEmail(addUsuario, i);
                            break;
                        case 3:
                            criaSexo(addUsuario, i);
                            break;
                        case 4:
                            criaEndereco(addUsuario, i);
                            break;
                        case 5:
                            criaAltura(addUsuario, i);
                            break;
                        case 6:
                            criaVacina(addUsuario, i);
                            break;
                        default:
                            break;
                        }
                        apresentarUsuario(addUsuario, i);
                    } while (menu < 1 || menu > 7);
                    do
                    {
                        printf("\nDeseja editar outra informacao?( 1 - [SIM] || 2 - [NAO] ): ");
                        fflush(stdin);
                        scanf("%d", &menu);
                    } while (menu < 1 || menu > 2);
                } while (menu == 1);

                break;
            }
        }

        break;
    case 2:
        system("cls");
        printf("Digite o EMAIL que deseja procurar: ");
        fflush(stdin);
        gets(procurarUser->procurarEmail);
        for (i = 0; i < contador; i++)
        {
            if (stricmp(procurarUser->procurarEmail, addUsuario[i].email) == 0)
            {
                apresentarUsuario(addUsuario, i);
            }
            do
            {
                system("cls");
                printf("_-_-_-_-_-_-_-_ SELECIONE A OPCAO QUE DESEJA _-_-_-_-_-_-_-_\n\n");
                printf("1 - Editar nome\n");
                printf("2 - Editar email\n");
                printf("3 - Editar sexo\n");
                printf("4 - Editar endereco\n");
                printf("5 - Editar altura\n");
                printf("6 - Editar vacina\n");
                printf("7 - Voltar ao menu\n");
                fflush(stdin);
                scanf("%d", &menu);
                do
                {
                    switch (menu)
                    {
                    case 1:
                        criaNome(addUsuario, i);
                        break;
                    case 2:
                        criaEmail(addUsuario, i);
                        break;
                    case 3:
                        criaSexo(addUsuario, i);
                        break;
                    case 4:
                        criaEndereco(addUsuario, i);
                        break;
                    case 5:
                        criaAltura(addUsuario, i);
                        break;
                    case 6:
                        criaVacina(addUsuario, i);
                        break;
                    default:
                        break;
                    }
                    apresentarUsuario(addUsuario, i);
                } while (menu < 1 || menu > 7);
                do
                {
                    printf("\nDeseja editar outra informacao?( 1 - [SIM] || 2 - [NAO] ): ");
                    fflush(stdin);
                    scanf("%d", &menu);
                } while (menu < 1 || menu > 2);
            } while (menu == 1);
            break;
        }

    default:
        break;
    }
}

void excluirUsuario(cadastra_usuario *excluirUsuario, procurarInfos *procurarUser)
{
    int menu, usuarioExcluir;
    do
    {
        do
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_EXCLUIR USUARIO-_-_-_-_-_-_-_-_-_\n");
            printf("\n1 - Procurar por Id");
            printf("\n2 - Procurar por Email");
            printf("\n3 - Voltar ao Menu");
            printf("\n_-_-_-_-_-_-_-_ DIGITE O NUMERO DA OPCAO PARA PROSSEGUIR_-_-_-_-_-_-_-_ \n");
            fflush(stdin);
            scanf("%d", &menu);
        } while (menu < 1 || menu > 3);
        switch (menu)
        {
        case 1:
            usuarioExcluir = buscarId(excluirUsuario, procurarUser);
            for (usuarioExcluir; usuarioExcluir < contador; usuarioExcluir)
            {
                excluirUsuario[usuarioExcluir].Id = excluirUsuario[++usuarioExcluir].Id;
                strcpy(excluirUsuario[usuarioExcluir].nome, excluirUsuario[++usuarioExcluir].nome);
                strcpy(excluirUsuario[usuarioExcluir].email, excluirUsuario[++usuarioExcluir].email);
                strcpy(excluirUsuario[usuarioExcluir].sexo, excluirUsuario[++usuarioExcluir].sexo);
                strcpy(excluirUsuario[usuarioExcluir].endereco.estado, excluirUsuario[++usuarioExcluir].endereco.estado);
                strcpy(excluirUsuario[usuarioExcluir].endereco.cidade, excluirUsuario[++usuarioExcluir].endereco.cidade);
                strcpy(excluirUsuario[usuarioExcluir].endereco.rua, excluirUsuario[++usuarioExcluir].endereco.rua);
                strcpy(excluirUsuario[usuarioExcluir].endereco.casa, excluirUsuario[++usuarioExcluir].endereco.casa);
                strcpy(excluirUsuario[usuarioExcluir].endereco.CEP, excluirUsuario[++usuarioExcluir].endereco.CEP);
                excluirUsuario[usuarioExcluir].altura = excluirUsuario[++usuarioExcluir].altura;
                excluirUsuario[usuarioExcluir].vacina = excluirUsuario[++usuarioExcluir].vacina;
            }
            contador--;
            break;
        case 2:
            usuarioExcluir = buscarEmail(excluirUsuario, procurarUser);
            for (usuarioExcluir; usuarioExcluir < contador; usuarioExcluir)
            {
                excluirUsuario[usuarioExcluir].Id = excluirUsuario[++usuarioExcluir].Id;
                strcpy(excluirUsuario[usuarioExcluir].nome, excluirUsuario[++usuarioExcluir].nome);
                strcpy(excluirUsuario[usuarioExcluir].email, excluirUsuario[++usuarioExcluir].email);
                strcpy(excluirUsuario[usuarioExcluir].sexo, excluirUsuario[++usuarioExcluir].sexo);
                strcpy(excluirUsuario[usuarioExcluir].endereco.estado, excluirUsuario[++usuarioExcluir].endereco.estado);
                strcpy(excluirUsuario[usuarioExcluir].endereco.cidade, excluirUsuario[++usuarioExcluir].endereco.cidade);
                strcpy(excluirUsuario[usuarioExcluir].endereco.rua, excluirUsuario[++usuarioExcluir].endereco.rua);
                strcpy(excluirUsuario[usuarioExcluir].endereco.casa, excluirUsuario[++usuarioExcluir].endereco.casa);
                strcpy(excluirUsuario[usuarioExcluir].endereco.CEP, excluirUsuario[++usuarioExcluir].endereco.CEP);
                excluirUsuario[usuarioExcluir].altura = excluirUsuario[++usuarioExcluir].altura;
                excluirUsuario[usuarioExcluir].vacina = excluirUsuario[++usuarioExcluir].vacina;
            }
            contador--;
            break;
        default:
            break;
        }
        do
        {
            printf("\nDeseja excluir outro usuario?( 1 - [SIM] || 2 - [NAO] ): ");
            fflush(stdin);
            scanf("%d", &menu);
        } while (menu < 1 || menu > 2);

    } while (menu == 1);
}

void buscarMenu(cadastra_usuario *addUsuario, procurarInfos *procurarUser)
{
    int menu;
    system("cls");
    printf("_-_-_-_-_-_-_-_-_-_-_EDICAO DE USUARIO-_-_-_-_-_-_-_-_-_\n");
    printf("\n1 - Procurar por Id");
    printf("\n2 - Procurar por Email");
    printf("\n3 - Voltar ao Menu");
    printf("\n_-_-_-_-_-_-_-_ DIGITE O NUMERO DA OPCAO PARA PROSSEGUIR_-_-_-_-_-_-_-_ \n");
    fflush(stdin);
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        buscarId(addUsuario, procurarUser);
        break;
    case 2:
        buscarEmail(addUsuario, procurarUser);
        break;
    default:
        break;
    }
}

int buscarId(cadastra_usuario *addUsuario, procurarInfos *procurarUser)
{
    int menu, i;
    do
    {
        system("cls");
        printf("Digite o ID que deseja procurar: ");
        scanf("%d", &procurarUser->procurarId);
        for (i = 0; i < contador; i++)
        {
            if (addUsuario[i].Id == procurarUser->procurarId)
            {
                apresentarUsuario(addUsuario, i);
                return i;
            }
        }
        do
        {
            printf("\nDeseja procurar outro usuario?( 1 - [SIM] || 2 - [NAO] ): ");
            fflush(stdin);
            scanf("%d", &menu);
        } while (menu < 1 || menu > 2);

    } while (menu == 1);
}

int buscarEmail(cadastra_usuario *addUsuario, procurarInfos *procurarUser)
{
    int menu, i;
    do
    {
        system("cls");
        printf("Digite o email que deseja procurar: ");
        fflush(stdin);
        gets(procurarUser->procurarEmail);
        for (i = 0; i < contador; i++)
        {
            if (stricmp(procurarUser->procurarEmail, addUsuario[i].email) == 0)
            {
                apresentarUsuario(addUsuario, i);
                return i;
            }
        }
        do
        {
            printf("\nDeseja procurar outro usuario?( 1 - [SIM] || 2 - [NAO] ): ");
            fflush(stdin);
            scanf("%d", &menu);
        } while (menu < 1 || menu > 2);

    } while (menu == 1);
}

void listarUsuario(cadastra_usuario *addUsuario)
{
    int menu, i;
    do
    {
        for (i = 0; i < contador; i++)
        {
            apresentarUsuario(addUsuario, i);
        }
        do
        {
            printf("\nDeseja repetir a lista ?( 1 - [SIM] || 2 - [NAO] ): ");
            fflush(stdin);
            scanf("%d", &menu);
        } while (menu < 1 || menu > 2);

    } while (menu == 1);
}

void backupUsuarios(cadastra_usuario *usuario, backup_usuario *backup)
{
    int menu, i, backupContador;
    bool backupValidar;

    system("cls");
    printf("\t\t\t     _-_-_-_-_-_-[BACKUP USUARIO]-_-_-_-_-_-_\n");
    printf("\n\n\t\t\t\t|| [1]Realizar Backup || [2]Restaurar Backup  ||");
    printf("\n\n\t\t\t\t|| [1]Voltar ao menu  ||                      ||");
    fflush(stdin);
    scanf("%d", &menu);

    while (menu < 1 || menu > 3)
    {
        printf("\n\t\t\t\t  Menu invalido, digite apenas os disponiveis: ");
        fflush(stdin);
        scanf("%d", &menu);
    }

    switch (menu)
    {
    case 1:
        for (i = 0; i < contador; i++)
        {
            backup[i].IdBackup = usuario[i].Id;
            strcpy(backup[i].nomeBackup, usuario[i].nome);
            strcpy(backup[i].emailBackup, usuario[i].email);
            strcpy(backup[i].sexoBackup, usuario[i].sexo);
            strcpy(backup[i].enderecoBackup.estadoBackup, usuario[i].endereco.estado);
            strcpy(backup[i].enderecoBackup.cidadeBackup, usuario[i].endereco.cidade);
            strcpy(backup[i].enderecoBackup.ruaBackup, usuario[i].endereco.rua);
            strcpy(backup[i].enderecoBackup.casaBackup, usuario[i].endereco.casa);
            strcpy(backup[i].enderecoBackup.CEPBackup, usuario[i].endereco.CEP);
            backup[i].alturaBackup = usuario[i].altura;
            backup[i].vacinaBackup = usuario[i].vacina;
        }
        backupContador = contador;
        backupValidar = true;
        printf("\nBackup realizado com sucesso! Quantidade de usuario salvos: %d", contador);
        getch();

        break;
    case 2:
        if (backupValidar = true)
        {
            for (i = 0; i < contador; i++)
            {
                usuario[i].Id = backup[i].IdBackup;
                strcpy(usuario[i].nome, backup[i].nomeBackup);
                strcpy(usuario[i].email, backup[i].emailBackup);
                strcpy(usuario[i].sexo, backup[i].sexoBackup);
                strcpy(usuario[i].endereco.estado, backup[i].enderecoBackup.estadoBackup);
                strcpy(usuario[i].endereco.cidade, backup[i].enderecoBackup.cidadeBackup);
                strcpy(usuario[i].endereco.rua, backup[i].enderecoBackup.ruaBackup);
                strcpy(usuario[i].endereco.casa, backup[i].enderecoBackup.casaBackup);
                strcpy(usuario[i].endereco.CEP, backup[i].enderecoBackup.CEPBackup);
                usuario[i].altura = backup[i].alturaBackup;
                usuario[i].vacina = backup[i].vacinaBackup;
            }
            contador = backupContador;
        } else
        {
            printf("\nBackup nao encontrado! Realize um primeiro antes de restaurar.");
            getch();
        }
        break;
    default:
        break;
    }
}

void apresentarUsuario(cadastra_usuario *addUsuario, int numeroUsuario)
{
    system("cls");
    printf("_-_-_-_-_-_-_-_-_-_-_INFORMACAO-_-_-_-_-_-_-_-_-_\n");
    printf("Id: %d\n", addUsuario[numeroUsuario].Id);
    printf("Nome: %s\n", addUsuario[numeroUsuario].nome);
    printf("Email: %s\n", addUsuario[numeroUsuario].email);
    printf("Sexo: %s\n", addUsuario[numeroUsuario].sexo);
    printf("Estado: %s\n", addUsuario[numeroUsuario].endereco.estado);
    printf("Cidade: %s\n", addUsuario[numeroUsuario].endereco.cidade);
    printf("Rua: %s\n", addUsuario[numeroUsuario].endereco.rua);
    printf("Numero da casa: %s\n", addUsuario[numeroUsuario].endereco.casa);
    printf("CEP: %s\n", addUsuario[numeroUsuario].endereco.CEP);
    printf("Altura: %0.2lf\n", addUsuario[numeroUsuario].altura);
    addUsuario[numeroUsuario].vacina ? printf("Vacina: Dose aplicada!\n") : printf("Vacina: Dose nao aplicada!\n");
    getch();
}

//BUGS PARA RESOLVER!!!!
//Não conseguir fazer outro backup ao restaurar o primeiro??
//Usar o comando listarUsuarios após o backup faz com que ele passe por todos os 1000 usuario
//Procurar outros...