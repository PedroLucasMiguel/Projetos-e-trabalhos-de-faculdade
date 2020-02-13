/* ########CompuCrypto########
    Sistema simples de criptografia.
    By: Predo
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void generateKey(){
    char key[3];
    int KOK, bkp[3]; //Chave para descriptografar a chave original
    
    printf("\nDigite uma sequencia de no maximo 3 letras: ");
    setbuf(stdin, NULL);
    scanf("%s", key);

    //Escrevendo valores originais no array de backup para fazer as alterações dos valores em bytes
    for(int i = 0; i < 3; i++)
    {
        bkp[i] = (int)key[i];
    }

    KOK = ((((((int)key[0])+((int)key[1])+((int)key[2]))*12)+24)-48)+12; 

    //Codificandio a chave
    bkp[0] = (bkp[0]*KOK);
    bkp[1] = (bkp[1]*KOK);
    bkp[2] = (bkp[2]*KOK);

    printf("\nChave gerada com sucesso!\n");
    printf("Chave codificada: ");

    //Mostra chave na tela
    for(int i = 0; i < 3; i++)
        printf("%d ", bkp[i]);

    printf("\nKOK: %d\n", KOK);
}

void decryptKey(char *cryptedKey, int KOK){

    int key[3];

    sscanf(cryptedKey, "%d %d %d", &key[0], &key[1], &key[2]);

    //Decodifica o valor da chave
    key[0] = (key[0]/KOK);
    key[1] = (key[1]/KOK);
    key[2] = (key[2]/KOK);

    printf("\nDecodificado com sucesso!\n");
    printf("Valor da chave decodificada: ");

    for(int i = 0; i < 3; i++)
    {
        printf("%c", key[i]);
    }

    printf("\n\n");
}

void encryptFile(){
    FILE *fp, *fpOUT; //fpOUT = ponteiro para o arquivo de saida
    unsigned char fileName[64], letra, cryptedKey[128], key[3];
    int op, KOK, keyElement = 0, keyValue, i; //Opção do usuario nos menus
    bool error = true; //Validação de entrada

    printf("\nDigite o nome do arquivo com extensão: ");
    setbuf(stdin, NULL);
    scanf("%s", fileName);

    if((fp = fopen(fileName, "r+")) == NULL)
        printf("\nERRO NA ABERTURA DO ARQUIVO! VERIFIQUE SUA EXISTENCIA OU O QUE DIGITOU ANTERIORMENTE!\n");
    
    else{
        fpOUT = fopen("output.txt", "w+");

        while (error)
        {
            printf("\nVoce ja possui a chave codificada?\n");
            printf("1-Sim || 2-Nao\n");
            printf("Resposta: ");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                error = false;
                break;
            
            case 2:
                generateKey();
                error = false;
                break;

            default:
                printf("Opcao invalida! Entradas validas (1/2)\n");
                break;
            }
        }

        printf("\nDigite o valor chave codificada: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", cryptedKey);
        printf("Digite o valor da KOK: ");
        scanf("%d", &KOK);
        decryptKey(cryptedKey, KOK);
        printf("Digite o valor da chave decodificada: ");
        setbuf(stdin, NULL);
        scanf("%s", key);

        //Agora é a hora da verdade, criptografar a merda do arquivo
        fprintf(fpOUT, "%s\n", cryptedKey); //Escreve a chave codificada junto com o seu KOK no arquivo de saida
        fprintf(fpOUT, "%d\n", KOK);
        while (!feof(fp))
        {
            letra = fgetc(fp);
            keyValue = (int)key[keyElement];;
            keyValue = ((int)letra)+keyValue;
            letra = keyValue;

            fputc(letra, fpOUT);
            
            keyElement++;

            if(keyElement > 2)
                keyElement = 0;
        }
        fclose(fp);
        fclose(fpOUT);
        printf("\nArquivo criptografado com sucesso!\n");
    }
}

void decryptFile(){
    FILE *fp, *fpOUT; //fpOUT = ponteiro para o arquivo de saida
    unsigned char fileName[64], letra, cryptedKey[128], key[3];
    int KOK, fraseLen, keyElement = 0, keyValue; //Opção do usuario nos menus
    fpos_t position;

    printf("\nDigite o nome do arquivo com extensão: ");
    setbuf(stdin, NULL);
    scanf("%s", fileName);

    if((fp = fopen(fileName, "r")) == NULL)
        printf("\nERRO NA ABERTURA DO ARQUIVO! VERIFIQUE SUA EXISTENCIA OU O QUE DIGITOU ANTERIORMENTE!\n");
    
    else{
        fpOUT = fopen("outputDECRYPTED.txt", "w+");

        fgets(cryptedKey, 128, fp);
        fscanf(fp, "%d", &KOK);
        decryptKey(cryptedKey, KOK);

        printf("Digite o valor da chave decodificada: ");
        setbuf(stdin, NULL);
        scanf("%s", key);
        

        //Agora é a hora da verdade, criptografar a merda do arquivo
        letra = fgetc(fp);

        while (!feof(fp))
        {
            letra = fgetc(fp);
            keyValue = (int)key[keyElement];
            keyValue = ((int)letra)-keyValue;
            letra = keyValue;
        
            fputc(letra, fpOUT);
            
            keyElement++;

            if(keyElement > 2)
                keyElement = 0;
        }
        fseek(fpOUT , 0 , SEEK_END );
        fgetc(fpOUT);
        fclose(fp);
        fclose(fpOUT);
        printf("\nArquivo descriptografado com sucesso!\n");
    }
}

int main(){
    encryptFile();
    printf("\n\n----Descriptografando arquivo----\n\n");
    decryptFile();
    return 0;
}