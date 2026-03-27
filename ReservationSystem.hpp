#ifndef RESERVATION_SYSTEM_HPP
#define RESERVATION_SYSTEM_HPP

#include <string>
#include "ReservationRequest.hpp"

struct Reservation {
    ReservationRequest request;
    int room_id;
};

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;
    int capacidade;
    int reservation_count;
    Reservation* reservations;

public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};

#endif