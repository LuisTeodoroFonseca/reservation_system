#include <iostream>
#include <windows.h>
using namespace std;

#include "ReservationRequest.hpp"
#include "ReservationSystem.hpp"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int room_count = 3;
    int room_capacities[room_count] = {30, 40, 50};
    ReservationSystem sistema {room_count, room_capacities};
    // --- Segunda-Feira ---
    ReservationRequest reserva1 {"estruturas de dados", "segunda", 7, 9, 40};
    ReservationRequest reserva2 {"tecnicas e algoritmos", "segunda", 9, 11, 35};
    ReservationRequest reserva3 {"teoria da probabilidade", "segunda", 11, 13, 45};

    // --- Terça-Feira ---
    ReservationRequest reserva4 {"banco de dados", "terca", 7, 9, 30};
    ReservationRequest reserva5 {"algebra linear numerica", "terca", 11, 13, 25};
    ReservationRequest reserva6 {"visao computacional", "terca", 16, 18, 20};

    // --- Quarta-Feira ---
    ReservationRequest reserva7 {"estruturas de dados", "quarta", 7, 9, 40};
    ReservationRequest reserva8 {"tecnicas e algoritmos", "quarta", 9, 11, 35};
    ReservationRequest reserva9 {"teoria da probabilidade", "quarta", 11, 13, 45};

    // --- Quinta-Feira ---
    ReservationRequest reserva10 {"banco de dados", "quinta", 7, 9, 30};
    ReservationRequest reserva11 {"algebra linear numerica", "quinta", 11, 13, 25};

    // --- Sexta-Feira ---
    ReservationRequest reserva12 {"teoria da probabilidade", "sexta", 11, 13, 45};
    ReservationRequest reserva13 {"visao computacional", "sexta", 16, 18, 20};
    
    sistema.reserve(reserva1);
    sistema.reserve(reserva2);
    sistema.reserve(reserva3);
    sistema.reserve(reserva4);
    sistema.reserve(reserva5);
    sistema.reserve(reserva6);
    sistema.reserve(reserva7);
    sistema.reserve(reserva8);
    sistema.reserve(reserva9);
    sistema.reserve(reserva10);
    sistema.reserve(reserva11);
    sistema.reserve(reserva12);
    sistema.reserve(reserva13);
    sistema.printSchedule();
    sistema.cancel("calculo");
    sistema.cancel("al");

    return 0;
}