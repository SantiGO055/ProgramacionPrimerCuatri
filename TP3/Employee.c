
Employee* employee_new(FILE* pFile , LinkedList* pArrayListEmployee){

    Employee* this = malloc(sizeof(LinkedList));
        if(this!=NULL){
            employee_newParametros(this,id,name,horasTrabajadas,sueldo);
        }

}
Employee* employee_newParametros(LinkedList* this , LinkedList* pArrayListEmployee){
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
}
