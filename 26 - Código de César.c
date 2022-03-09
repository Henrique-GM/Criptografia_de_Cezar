#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


//A LIMITAÇÃO DO PROGRAMA É: NÚMEROS SÓ EM EXTENSO E NÃO PERMITE CARACTERES ESPECIAS.
//SERÁ CODIFICADA E DESCODIFICADA EM MINÚSCULAS PARA O FUNCIONAMENTO CORRETO DO CÓDIGO.
//COMPILAR EM COMPILADORES BAIXADOS...NÃO FUNCIONA EM COMPILADORES ONLINE, PORQUE NÃO ACEITÃO STRLWR().TESTAR NO "DEV C++".
int main (void)
{
	setlocale (LC_ALL, "portuguese") ;
	
	char frase[100] ;	
    char frase_criptografada[100];
	char alfabeto[54] = "abcdefghijklmnopqrstuvxwyz!@#$&*()_-+=~^<>|[`.,?{}" ;
	int i, j ;
    char Z = 'Z';
    int auxiliar = 0;
	
	printf ("\n Digite uma frase...: ") ;
	fgets (frase, 100, stdin) ;
	
	//PARA QUE NÃO DE PROBLEMA COM LETRAS MAIÚSCULAS, COMO EXEMPLO "Y".
	if (auxiliar == 0) {
		strlwr (frase);
	}

	//LÓGICA PARA TRANFORMAR UMA FRASE EM CÓDIGO DE CÉSAR.	
	for (i = 0; i < strlen (frase); i++)
	{
		for (j = 0; j < strlen (alfabeto); j++)
		{
		  if (frase[i] == alfabeto[j])
		  {
			frase[i] = alfabeto[j = j + 24]  ; 	
		  }	
		  
	      if (frase[i] == alfabeto[52]) 
	      {
	          
	        frase[i] = alfabeto[0 + 18];
	      }
		}
	}

 	printf ("\n O código de César ficou...: %s", frase) ; 

 	printf ("\n");

  	printf ("\n Digite o coodigo criptografado..: ");
 	fgets (frase_criptografada, 100, stdin);

  	printf ("\n");

  	//PARA DESCRIPTOGRRAFAR O CÓDIGO
  	for (i = 0; i < strlen (frase_criptografada); i++)
	{
		for (j = 0; j < strlen (alfabeto); j++)
		{
			if (frase_criptografada[i] == alfabeto[j])
		  	{
				frase_criptografada[i] = alfabeto[j = j - 24]; 	
		  	}	
		    
	      	if (frase_criptografada[i] == alfabeto[52]) 
	      	{
	      		//PARA FAZER O "Z" MAIÚSCULO FUNCIONAR
	        	frase_criptografada[i] = Z;
	      	}	  	
		}	
	}

    printf ("\n A frase descriptografada..: %s", frase_criptografada);
			
	return 0 ;
	system ("pause") ;
}