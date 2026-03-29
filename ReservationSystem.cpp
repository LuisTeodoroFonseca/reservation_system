#include <iostream>
using namespace std;

#include <string>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"


ReservationSystem::ReservationSystem(int room_count, int* room_capacities){
    this->room_count = room_count;
    this->room_capacities = new int[room_count];
    for(int i = 0; i < room_count; i++) {
        this->room_capacities[i] = room_capacities[i];
    }
    capacidade = room_count*5*14; //consideramos que não existe horário de menos de uma hora
    reservations = new Reservation[capacidade];
    reservation_count = 0;
}

ReservationSystem::~ReservationSystem(){
    delete[] room_capacities;
    delete[] reservations;
}

bool ReservationSystem::reserve(ReservationRequest request) {
    for(int room = 0; room < room_count; room++) { //passa por cada sala existente
        if(room_capacities[room] < request.getStudentCount()) //verifica a capacidade da sala
            continue;
        bool ocupada = false;

        for(int i = 0; i < reservation_count; i++) { //verifica cada reserva uma a uma
            if(reservations[i].room_id == room) { //verifica se estamos analisando a mesma sala
                if(reservations[i].request.getWeekday() == request.getWeekday()) { //verifica o dia da semana e depois verifica o horário
                    if(request.getEndHour() > reservations[i].request.getStartHour() && request.getStartHour() < reservations[i].request.getEndHour()) {
                        ocupada = true; //se entrar nesse if é porque a sala está ocupada nesse horário
                        break; //vai para a próxima sala
                    }
                }
            }
        }
        if(ocupada == false) { //se depois de todas as verificações a sala continuar desocupada então reservamos ela
            reservations[reservation_count].request = request;
            reservations[reservation_count].room_id = room;
            reservation_count++;
            cout << "Reserva feita com sucesso" << endl;
            return true;
        }
    }
    cout << "Não foi possível fazer uma reserva" << endl;
    return false;
}

bool ReservationSystem::cancel(std::string course_name) {
    int iterador = 0;
    for(int i = 0; i < reservation_count; i++) { //passa por cada reserva
        if(reservations[i].request.getCourseName() == course_name) { //verifica se o nome do curso é igual
            iterador++; //iterador para contar se existe um curso com esse nome
            for(int j = i; j < (reservation_count-1); j++) { //aqui nós andamos todos os cursos uma casa para a esquerda e passamos o curso que queremos cancelar para a última posição conhecida do array
                reservations[j].request = reservations[j+1].request;
                reservations[j].room_id = reservations[j+1].room_id; //realizamos as trocas dois a dois
            }
            reservation_count--; //diminuimos em uma unidade a quantidade de reservas, fazendo com que não seja necessário apagar a reserva cancelada porque agora na próxima reserva feita, ela será sobreescrita
            //e se não tiver próxima reserva feita, ela ficará lá mas não será utilizada porque diminuimos o reservation_count, que é o valor até onde utilizamos o array reservations
            i--; //voltamos uma iteração porque andamos todas as reservas uma posição a menos no array
        }
    }
    if(iterador == 0) { //verifica se algum cancelamento foi feito
        cout << "Não existe disciplina com esse nome" << endl;
        return false;
    }
    else {
        cout << "Aula cancelada com sucesso" << endl;
        return true;
    }
}

int dia_to_num(string dia){
    if(dia == "segunda"){
        return 0;
    }else if(dia == "terça"){
        return 1;
    }else if(dia == "quarta"){
        return 2;
    }else if(dia == "quinta"){
        return 3;
    }else {
        return 4;
    }
}

void ReservationSystem::ordenarReservations(){ //bubble sort para ordenar o array reservations

    for(int i = 0; i < reservation_count - 1; i++){
        
        for(int j = 0; j < reservation_count - 1 - i; j++){
            bool troca = false;

            if(reservations[j+1].room_id < reservations[j].room_id){
            troca = true;
            }
            
            else if(reservations[j+1].room_id == reservations[j].room_id){
                if(dia_to_num(reservations[j+1].request.getWeekday()) < dia_to_num(reservations[j].request.getWeekday())){
                troca = true;
                }
            

                else if(dia_to_num(reservations[j+1].request.getWeekday()) == dia_to_num(reservations[j].request.getWeekday())){
                    if(reservations[j+1].request.getStartHour() < reservations[j].request.getStartHour()){
                troca = true;
                    }
                }
            }

            if(troca == true){
                Reservation res = reservations[j];
                reservations[j] = reservations[j+1];
                reservations[j+1] = res;
            }

        }
    }
}



void ReservationSystem::printSchedule(){
    ordenarReservations();

    for(int i = 0; i < reservation_count; i++){
        if(i >= 1){

            if(reservations[i].room_id == reservations[i - 1].room_id){

                if(reservations[i].request.getWeekday() == reservations[i - 1].request.getWeekday()){
                    cout << reservations[i].request.getCourseName() << ": " << reservations[i].request.getStartHour() << "h~" << reservations[i].request.getEndHour() << "h" << endl;
                }

                else{
                    cout << endl;
                    cout << reservations[i].request.getWeekday() << ":" << endl;
                    cout << reservations[i].request.getCourseName() << ": " << reservations[i].request.getStartHour() << "h~" << reservations[i].request.getEndHour() << "h" << endl;
                }
            }
            else{
                cout << endl;
                cout << "Room " << reservations[i].room_id << endl;
                cout << reservations[i].request.getWeekday() << ":" << endl;
                cout << reservations[i].request.getCourseName() << ": " << reservations[i].request.getStartHour() << "h~" << reservations[i].request.getEndHour() << "h" << endl;

                }
        }
        else{
            cout << endl;
            cout << "---------------------------- GRADE DE HORÁRIOS ----------------------------" << endl;
            cout << "Room " << reservations[i].room_id << endl;
            cout << reservations[i].request.getWeekday() << ":" << endl;
            cout << reservations[i].request.getCourseName() << ": " << reservations[i].request.getStartHour() << "h~" << reservations[i].request.getEndHour() << "h" << endl;
        }
    }
    cout << "---------------------------------------------------------------------------";
    cout << endl;
        
}
