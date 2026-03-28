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
            printf("Reserva feita com sucesso\n");
            return true;
        }
    }
    printf("Não foi possível fazer uma reserva\n");
    return false;
}