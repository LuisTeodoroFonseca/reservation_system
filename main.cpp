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
    ReservationRequest reserva1 {"calculo", "sexta", 7, 9, 45};
    ReservationRequest reserva2 {"probabilidade", "segunda", 7, 9, 36};
    ReservationRequest reserva3 {"estrutura de dados", "segunda", 7, 9, 25};
    ReservationRequest reserva4 {"analise", "quarta", 7, 9, 30};
    ReservationRequest reserva5 {"geometria", "terça", 7, 9, 35};
    ReservationRequest reserva6 {"fundamentos", "terça", 9, 11, 41};
    ReservationRequest reserva7 {"estatistica", "terça", 7, 9, 41};
    sistema.reserve(reserva1);
    sistema.reserve(reserva2);
    sistema.reserve(reserva3);
    sistema.reserve(reserva4);
    sistema.reserve(reserva5);
    sistema.reserve(reserva6);
    sistema.reserve(reserva7);
    sistema.printSchedule();
    sistema.cancel("calculo");
    sistema.cancel("al");

    return 0;
}