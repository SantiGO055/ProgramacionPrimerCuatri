int buscarPorDni(ePersona personas[], int dni){
    int i;
    for(i=0;i<)
}

int obtenerEspacioLibre(ePersona lista[], int cantidad) //para que en el alta
{
    int i,retorno=-1;
    for(i=0;i<cantidad;i++){
        if(per[i].isEmpty==1){ //encontro un lugar libre

            retorno=i;
            break;
        }
    }
    return retorno;
}
void alta(ePersona personas[]){
    int index;
    index=obtenerEspacioLibre(per, CANT);
    if(index!=-1){
            //validar dni con funcion

            printf("Ingrese DNI: ");
            scanf("%ld",&per[i].dni);
            printf("Ingrese Apellido: ");
            scanf("%s",per[i].apellido);
            printf("Ingrese Nombre: ");
            scanf("%s",per[i].nombre);
            printf("Ingrese dia de nacimiento: "); //hacer funcion para comparar dni y ver si ya esta ingresado
            scanf("%d",&per[i].fechaNac.dia);
            printf("Ingrese mes de nacimiento: ");
            scanf("%d",&per[i].fechaNac.mes);
            printf("Ingrese año de nacimiento: ");
            scanf("%d",&per[i].fechaNac.anio);

    }
}

void baja(ePersona per[],int cantidad){
    int i;
    long int dniAux;
    char rta;
    printf("DNI: ")
    scanf("%ld"&dniAux)
    for(i=0;i<cantidad;i++){
        if(dniAux==per[i].dni){//lo encontro
            printf("%s %s %ld",per[i].apellido,per[i].nombre,per[i].dni);
        do{
            printf("Eliminar registro? S/N: "); //validad entre s y n
            fflush(stdin)
            rta=toupper(getch()); //lo que tecleo lo paso a mayuscula y lo asigno en rta
        }while(rta!='S'&&rta!='N');
            if(rta=='S'){
                per[i].isEmpty=0;
                break;
            }

        }

    }
}


