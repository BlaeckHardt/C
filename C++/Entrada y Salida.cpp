#include<iostream> //entrada y salida de datos
using namespace std;
int main(){ //Creo que todo el programa estará dentro de esto xd
	// El basico "Hola, Mundo"
	cout<<"No mames, esto es un problemon D:<"<<endl;//cout es imprimir, endl es un salto de linea
	// Tipos de datos
	int entero = 15; //int es entero :v
	cout<<entero<<endl;
	float flotante = 20.45; //de coma flotante :v
	cout<<flotante<<endl;
	double mayor = 16.3235; //de coma flotante :v
	cout<<mayor<<endl;
	char letra = '1'; //cadenas ,:v
	cout<<letra<<endl;
	// Lectura o entrada de datos
	float numero; //definiendo la variable
	cout<<"Digite un numero: ";
	cin>>numero; // Variable
	cout<<"\nEl numero que digitaste es: "<<numero<<endl; // Imprime la varuiable
	cout<<"Wow, ahora puedo decir que me la pelan >:D"<<endl;
	// Problema
	// 1. Escribe un programa que lea de la entrada estandar dos numeros y muestre en la salida estandar su suma, resta, multiplicacion y division
	int n1, n2, suma = 0, resta = 0, multiplicacion = 0, division = 0;
	cout<<"Primer numero: "; cin>>n1;
	cout<<"Segundo numero : "; cin>>n2;
	suma = n1+n2;
	resta = n1-n2;
	multiplicacion = n1*n2;
	division = n1/n2;
	cout<<"\nSuma: "<<suma<<endl;
	cout<<"Resta: "<<resta<<endl;
	cout<<"Multiplicacion: "<<multiplicacion<<endl;
	cout<<"Division: "<<division<<endl;
	// 2. Escribir un programa que de la entrada estandar el precio de un producto y muestre en la salida estandar el precio del producto al aplicarle el iva
	float precio, iva,precio_final;
	cout<<"Digite el precio del producto: "; cin>>precio;
	iva = precio*0.16;
	precio_final = precio+iva;
	cout<<"\nEl precio final es: "<<precio_final<<endl;
	/* 3. Realice un programa que lea de la entrada estandar los siguientes datos de una persona:
		Edad: dato de tipo entero
		Sexo: dato de tipo caracter
		Altura en metros: dato de tipo real
	Tras leer los datos, el programa debe mostrarlos en la salida estandar
	*/
	int edad;
	char sexo[10];
	float altura;
	cout<<"Digite su edad: "; cin>>edad;
	cout<<"\nDigite su sexo: "; cin>>sexo;
	cout<<"\nDigite su altura en metros: "; cin>>altura;
	cout<<"\nSu edad es: "<<edad<<" años"<<endl;
	cout<<"Su sexo es: "<<sexo<<endl;
	cout<<"Su altura es: "<<altura<<" metros"<<endl;
	return 0;
}
