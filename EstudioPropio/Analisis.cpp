/* Nombre programa: Modulo 2. 
   Autor: grupo 4*/
  
// gcc matesuem.c -o matesuem.exe
   
#include <stdio.h>
#include <math.h>

void bolzano(){
	
	int salto=1, x=0, z=-1, i=0, n, m, res1, res2, res3, resfinal, res4, res5, res6, resfinal2;
	float intervalo, intervalor;
	float int1, int2, resto, limite, interAnterior, resAnterior=0;
	float arrIntervalos[20];
	float salida1, salida2, interac;
	int ex=0, a;
	int cont=0, cont2=-2, funcion;
	
	int valor=(25);
	
	printf ("\nEscoja la funcion que desee realizar.");
	printf ("\n3x^5-25x^3+60x+25=0");
	printf ("\n3x^5-25x^3+60x-15=0");
	printf ("\n3x^5-25x^3+60x-25=0\n");
	scanf ("%d",&funcion);
	
	if(funcion==1){
		valor=(25);
	}
	else if(funcion==2){
		valor=(-15);
	}
	else if(funcion==3){
		valor=(-25);
	}
	
	int royale=valor;
	
	do{
	
		res1=0;
		res1=pow(x, 5);
		res1=res1*3;
	
		res2=0;
		res2=pow(x, 3);
		res2=res2*25;
	
		res3=0;
		res3=(60*x)+valor;
	
		resfinal=0;
		resfinal=res1-res2+res3;
		
		n=x;
		//x++;
	
		res4=0;
		res4=pow(z, 5);
		res4=res4*3;
	
		res5=0;
		res5=pow(z, 3);
		res5=res5*25;
	
		res6=0;
		res6=(60*z)+valor;
	
		resfinal2=0;
		resfinal2=res4-res5+res6;
		
		m=z;
		//z--;
	
		if (salto%2==0)
		{
			z--;
		}
		else{
			x++;
		}
		
		salto++;
	
	}while ((resfinal > 0 && resfinal2 > 0) || ( resfinal < 0 && resfinal2 < 0));
	
	printf("Seria con %d y %d\n", n, m);
	printf("Nos daria %d y %d\n", resfinal, resfinal2);
	printf("\n");
		
	int1=n;
	int2=m;
	interAnterior=n;
		
	do{
			
		a=i;
		
		intervalo=0;
		intervalo=(int1+int2);
		intervalo=intervalo/2;
		
		arrIntervalos[i++]=intervalo;
		
		//printf("intervalo primero %f y %f\n", intervalo, interAnterior);
		
		float res04=0;
		res04=pow(intervalo, 5);
		res04=res04*3;
		
		float res05=0;
		res05=pow(intervalo, 3);
		res05=res05*25;
		
		float res06=0;
		res06=(60*intervalo)+valor;
		
		float resC=0;
		resC=res04-res05+res06;
		printf("Resultado Intervalo %f \n", resC);
		

		if ((resC >= 0 && resAnterior >= 0) || ( resC < 0 && resAnterior < 0)){
			
			cont=cont-cont2;
			
			interac=arrIntervalos[a-cont];
			intervalor=(interac+intervalo);
			intervalor=intervalor/2;
			printf("Existe un valor c para x perteneciente a [%f,%f] donde f(c)=0\n", intervalo, interac);
			
			resto=arrIntervalos[a-cont]-intervalo;
			
			if(royale!=25){
				cont2--;
				royale=0;
				
			}
			
			if (resto<0){ //Conversor de signo
				resto=(resto)*(-2);
				resto=resto/2;
			}
			else{
				
			}
		}
		else{
			cont2++;
			
			intervalor=(interAnterior+intervalo);
			intervalor=intervalor/2;
			printf("Existe un valor c para x perteneciente a [%f,%f] donde f(c)=0\n", intervalo, interAnterior);
			
			resto=interAnterior-intervalo;
			
			if (resto<0){ //Conversor de signo
				resto=(resto)*(-2);
				resto=resto/2;
			}
			else{
				
			}
		}
		cont++;
		
		printf("Diferencia entre intervalos: %f \n", resto);
		//printf("interAnterior %f y arrIntervalos %f\n", interAnterior, arrIntervalos[a]);
		//printf("intervaloor %f \n", intervalor);	
		printf("\n");	
		int1=intervalor;
		int2=intervalor;
		interAnterior=intervalo;
		resAnterior=resC;
		
		float res004=0;
		res004=pow(interac, 5);
		res004=res004*3;
		
		float res005=0;
		res005=pow(interac, 3);
		res005=res005*25;
		
		float res006=0;
		res006=(60*interac)+valor;
		
		float resS=0;
		resS=res004-res005+res006;
			
		salida1 = resC;	
		salida2 = resS;
		limite=0.1;
		
		if(resto <= limite){
		
			if((salida1 >= 0 && salida2 >= 0) || ( salida1 < 0 && salida2 < 0)){
			ex=0;
			}
			else{
			ex=1;
			}
		}
		else{
			ex=0;
		}
		
	}while (ex==0);
}

void role(){
	
	float salto=1, z=-1, i=0, n, m, res1, res2, res3, resfinal, res4, res5, res6, resfinal2;
	float valor, valor2;
	int funcion, exit=1;
	
	printf ("\nEscoja la funcion que desee realizar.");
	printf ("\n3x^5-25x^3+60x+25=0");
	printf ("\n3x^5-25x^3+60x-15=0");
	printf ("\n3x^5-25x^3+60x-25=0\n");
	scanf ("%d",&funcion);
	
	if(funcion==1){
		valor=(-0.4375);
		valor2=(-0.5);
	}
	else if(funcion==2){
		valor=(0.3125);
		valor2=(0.25);
	}
	else if(funcion==3){
		valor=(0.4375);
		valor2=(0.5);
	}
	
	//15x^4 - 75x^2 +60
	
	while(exit!=3){
		
		float x;
		
		if(exit==1){
			x=valor;
		}
		else{
			x=valor2;
		}
		
		res1=0;
		res1=pow(x, 4);
		res1=res1*15;
		
		res2=0;
		res2=pow(x, 2);
		res2=res2*75;
		
		res3=0;
		res3=60;
		
		resfinal=0;
		resfinal=res1-res2+res3;
		
		if(exit==1){
			printf("Nos estaria dando dando %f con %f\n", resfinal, valor);	
		}
		else{
			printf("Nos estaria dando dando %f con %f\n", resfinal, valor2);
		}
		exit++;
	}
	if(resfinal>-1){
		printf("Como la funcion es derivable y se cumple que signo de f'(a)=f'(b)\n"); 
		printf("podemos deducir que la funcion es creciente (segun el signo que de la derivada)\n");
		printf("y no es posible que corte un valor d al eje una segunda vez, f(d)=0\n");
	}
	else{
		printf("Como la funcion es derivable y se cumple que signo de f'(a)=f'(b)\n"); 
		printf("podemos deducir que la funcion es decreciente (segun el signo que de la derivada)\n");
		printf("y no es posible que corte un valor d al eje una segunda vez, f(d)=0\n");
	}
}

int main(){
	
	int f=0; 
	int accion;

	printf ("\nBienvenido");
	printf ("\n---------------------------------------------");
	printf ("\nEscoja la accion que desee realizar.");
	printf ("\n---------------------------------------------");
	printf ("\nSelecione 1 para  Teorema de Bolzano.");
	printf ("\nSelecione 2 para  Teorema de Role.");
	printf ("\nSelecione 3 para salir.\n");
	printf ("\nIntroduzca el numero de la actividad que desee realizar: ");

	do{
	scanf ("%d",&accion);
		
		switch (accion){
		
		case 1:
			bolzano();
			f=0;
			break;
		case 2:
			role();
			f=0;
			break;
		case 3:
			printf ("\nHasta la proxima!!");
			f=0;
			break;
		default:
			printf ("Error, opccion inexistente.\n");
			printf ("\nEscoja una opccion correcta: ");
			f=1;
			}
	}
	while(f==1);

    return 0;
}