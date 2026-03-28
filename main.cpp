#include <iostream>
using namespace std;

#include "ReservationRequest.hpp"
#include "ReservationSystem.hpp"

int main() {
    int room_count = 1;
    int room_capacities[room_count] = {30};
    ReservationSystem sistema {room_count, room_capacities};
    ReservationRequest reserva1 {"calculo", "segunda", 7, 9, 30};
    sistema.reserve(reserva1);
    sistema.cancel("calculo");
    sistema.cancel("al");

    return 0;
}