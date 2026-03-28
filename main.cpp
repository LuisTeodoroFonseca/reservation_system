#include <iostream>
using namespace std;

#include "ReservationRequest.hpp"
#include "ReservationSystem.hpp"

int main() {
    int room_count = 1;
    int room_capacities[room_count] = {30};
    ReservationSystem sistema {room_count, room_capacities};
    ReservationRequest reserva1 {"calculo", "segunda", 7, 9, 30};
    ReservationRequest reserva2 {"al", "segunda", 7, 9, 30};
    sistema.reserve(reserva1);
    sistema.reserve(reserva2);

    return 0;
}