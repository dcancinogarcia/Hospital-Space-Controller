#include <iostream>
#include <unistd.h>

using namespace std;

//Variables
int i,c,m,x,y,d,pp,bu;
int opcion,hab;
int contador1,contador2,contador3=1,contador4,contadorh;

//Datos del paciente
string np[36]={"N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A","N/A"}; 
string ap[36]={" "}, am[36]={" "};

//Datos habitacion
string p[36]={"1","1","1","1","1","1","1","1","1","1","1","1","2","2","2","2","2","2","2","2","2","2","2","2","3","3","3","3","3","3","3","3","3","3","3","3"},
cu[36]={"1","2","3","4","5","6","1","2","3","4","5","6","1","2","3","4","5","6","1","2","3","4","5","6","1","2","3","4","5","6","1","2","3","4","5","6"},
ca[36]={"1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2","1","2"}; 

string f[36]={" "}, h[36]={" "}; //Datos fecha y hora
string dm[36]={" "}, dap[36]={" "}, dam[36]={" "}, dc[36]={" "}, dn[36]={" "}; //Datos doctor 
string pa[36]={" "}, rc[36]={" "}, t[36]={" "}; //Datos clinicos
string r[36]={" "}; //Razon de ingreso

//Numeracion de habitaciones
string v[36]={};
int num[36]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};

//Variables comparacion
string pas,bus;

//Actualizar
int act()
{
	
	for(x=0;x<36;x++)
	{
		if(np[x] ==  "N/A") 
		{
			v[x]="L";	
		}
		else
		{
			v[x]="O";	
		}
	}
	
}

//Imprimir diagrama del hospital
int diagrama()
{
	for(x=0;x<36;x++)
	{
		if(np[x] ==  "N/A") 
		{
			v[x]="L";	
		}
		else
		{
			v[x]="O";	
		}
	}
	cout<<"---------------------------------- \n";
	
	cout<<"-Diagrama del hospital- \n";
	cout<<"[L]=libre - [O]=ocupado \n\n";
	for(y=0;y<36;y++) 
	{
		if(contador4==2 || contador4==0)
		{
			cout<<"-";
			contador4=0;
		}
		
		cout<<num[y]<<"["<<v[y]<<"]";
		contador1++;
		contador2++;
		contador4++;
		
		if(contador4==2 || contador4==0)
		{
			cout<<"-";
			contador4=0;
		}
		if(contador1==4)
		{
			cout<<endl;
			contador1=0;
		}
		
		if(contador2==12)
		{
			cout<<"piso: "<<contador3<<endl;
			cout<<"---- \n";
			contador3++;
			contador2=0;
		}
	}
	
	cout<<"---------------------------------- \n";
		contador3=1;
}

//Dar alta
int alta()
{
	cout<<"---------------------------------- \n";
	
	cout<<"Revisa la habitacion disponibles en el diagrama y selecciona en cual quieres ingresar al paciente \n";
	cout<<"Ingresa la habitacion seleccionada para realizar la alta: ";
	cin>>hab;
	if(v[hab] == "L")
	{
		cout<<"------------------------------------------ \n";
		
		cout<<"Ingresa el nombre del paciente: ";
		cin>>np[hab];
		
		cout<<"Ingresa el apellido paterno del paciente: ";
		cin>>ap[hab];
		
		cout<<"Ingresa el apellido materno del paciente: ";
		cin>>am[hab];
		
		cout<<"------------------------------------------ \n";
		
		cout<<"ingresa la fecha (dd/mm/aaaa): ";
		cin>>f[hab];
		
		cout<<"ingresa la hora (hh:mm): ";
		cin>>h[hab];
		
		cout<<"------------------------------------------ \n";
		
		cout<<"ingresa el nombre de el doctor: ";
		cin>>dm[hab];
		
		cout<<"ingresa el apellido paterno del doctor: ";
		cin>>dap[hab];
		
		cout<<"ingresa el apellido materno del doctor: ";
		cin>>dam[hab];
		
		cout<<"ingresa la clave del doctor: ";
		cin>>dc[hab];
		
		cout<<"ingresa el numero de el doctor (xxx xxx xxxx): ";
		cin>>dn[hab];
		
		cout<<"------------------------------------------ \n";
		
		cout<<"ingresa la presion arterial del paciente: ";
		cin>>pa[hab];
		
		cout<<"ingresa el ritmo cardiaco del paciente: ";
		cin>>rc[hab];
		
		cout<<"ingresa la temperatura del paciente: ";
		cin>>t[hab];
		
		cout<<"------------------------------------------ \n";
		
		cout<<"ingresa el motivo de ingreso del paciente: ";
		cin>>r[hab];
		
		cout<<"------------------------------------------ \n";
	}
	else
	{
		cout<<"---------------------------------- \n";
		
		cout<<"este cuarto esta ocupado \n";
		
		cout<<"---------------------------------- \n";
		
		system("CLS");
		alta();
	}
}

//Dar baja
int baja()
{
	cout<<"---------------------------------- \n";

	cout<<"Ingresa la habitacion seleccionada para realizar la baja: ";
	
	cout<<"---------------------------------- \n";
	
	cin>>hab;
	np[hab]="N/A";
	ap[hab]=" ";
	am[hab]=" ";
	f[hab]=" ";
	h[hab]=" ";
	dm[hab]=" ";
	dap[hab]=" ";
	dam[hab]=" ";
	dc[hab]=" ";
	dn[hab]=" ";
	pa[hab]=" ";
	rc[hab]=" ";
	t[hab]=" ";
	r[hab]=" ";
	
}

//Disponibilidad
int disponibilidad()
{
	
	for(d=0;d<36;d++)
	{
		if(v[d]=="L")
		{
			cout<<"---------------------------------- \n";
			
			cout<<"Habitacion: "<<num[d]<<" Disponible \n";
			
			cout<<"---------------------------------- \n";
		}
		
		else
		{
			cout<<"---------------------------------- \n";
			
			cout<<"Habitacion: "<<num[d]<<" No disponible \n";
			
			cout<<"---------------------------------- \n";
		}
	}	
	
}

//Revisar alta
int revalta()
{
	cout<<"---------------------------------- \n";
	
	cout<<"Introduce el nombre del paciente que quieres revisar si esta dado de alta (revisa que este correctamente escrito) \n";
	cin>>pas;
	
	for(pp=0;pp<36;pp++)
	{
		if(pas==np[pp])
		{
			cout<<"Paciente encontrado en la habitacion: "<<pp<<endl;
			contadorh++;
		}
	}
	
		if(contadorh==0)
		{
			cout<<"Paciente no encontrado \n";	
			contadorh=0;
		}
		
	cout<<"---------------------------------- \n";	

}

//Buscar paciente
int buscar()
{
	cout<<"---------------------------------- \n";
	
	cout<<"Introduce el nombre del paciente que quieres buscar (revisa que este correctamente escrito) \n";
	cin>>bus;
	
	for(bu=0;bu<36;bu++)
	{
		if(bus==np[bu])
		{
			cout<<"Paciente encontrado en la habitacion: "<<bu<<endl;
			contadorh++;
			
			cout<<"Paciente: "<<bu<<": "<<np[bu]<<" "<<ap[bu]<<" "<<am[bu]<<endl;
			cout<<"Piso: "<<p[bu]<<" Cuarto: "<<cu[bu]<<" Cama: "<<ca[bu]<<endl;
			cout<<"Fecha y hora: "<<f[bu]<<" "<<h[bu]<<endl;
			cout<<"Doctor: "<<dm[bu]<<" "<<dap[bu]<<" "<<dam[bu]<<endl;
			cout<<"Presion arterial: "<<pa[bu]<<" Ritmo cardiaco: "<<rc[bu]<<" Temperatura: "<<t[bu]<<endl;
			cout<<"Razon: "<<r[bu]<<endl<<endl;
	
		}
		
	}
	
	if(contadorh==0)
		{
			cout<<"Paciente no encontrado \n";	
			contadorh=0;
		}
	
	cout<<"---------------------------------- \n";
}

//Imprimir totales
int imprimirtotales()
{
	for(m=0;m<36;m++)
	{
		cout<<"---------------------------------- \n";
		
		cout<<"Paciente: "<<m<<": "<<np[m]<<" "<<ap[m]<<" "<<am[m]<<endl;
		cout<<"Piso: "<<p[m]<<" Cuarto: "<<cu[m]<<" Cama: "<<ca[m]<<endl;
		cout<<"Fecha y hora: "<<f[m]<<" "<<h[m]<<endl;
		cout<<"Doctor: "<<dm[m]<<" "<<dap[m]<<" "<<dam[m]<<endl;
		cout<<"Presion arterial: "<<pa[m]<<" Ritmo cardiaco: "<<rc[m]<<" Temperatura: "<<t[m]<<endl;
		cout<<"Razon: "<<r[m]<<endl<<endl;
		
		cout<<"---------------------------------- \n";
	}
}



int main()
{	
	cout<<"---------------------------------- \n";
	cout<<"Bienvenido al sistema del hospital \n"; //Bienvenida y datos
	cout<<"---------------------------------- \n";
	
	system("PAUSE");
	
	for(int c=1;c<101;c+=9)
	{
		system("CLS");
		cout<<"Cargando..."<<c;
		sleep(1);
	}
	
	system("CLS");
	cout<<endl;
	
	do //ciclado 
	{
		//Listado de opciones
		cout<<"---------------------------------- \n";
		cout<<"Introduce la opcion que requieras (1-7) \n";
		cout<<"1-Dar alta \n";
		cout<<"2-Dar baja \n";
		cout<<"3-Disponibilidad \n";
		cout<<"4-Revisar alta \n";
		cout<<"5-Buscar paciente \n";
		cout<<"6-Imprimir totales \n";
		cout<<"7-Cerrar sistema \n";
		cout<<"---------------------------------- \n";
		cin>>opcion;
		system("CLS");
		
		switch(opcion)
		{
		
			case 1: //Dar alta
			diagrama();
			alta();
			break;
			
			case 2: //Dar baja
			diagrama();
			baja();
			break;
			
			case 3: //Disponibilidad
			act();
			disponibilidad();
			break;
			
			case 4: //Revisar alta
			act();
			revalta();
			break;
			
			case 5: //Buscar paciente
			act();
			buscar();
			break;
			 	
			case 6: //Imprimir totales
			act();
			imprimirtotales();
			break;
			
			case 7: //Cerrar sistema
			cout<<"Cerrando sesion... \n";	 
			return 0;
		}
	}while (opcion != 7);
	
	system("CLS");
	
}
