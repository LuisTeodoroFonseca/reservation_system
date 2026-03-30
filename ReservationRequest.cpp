#include <iostream>
#include <stdexcept>
using namespace std;

#include "ReservationRequest.hpp"

ReservationRequest::ReservationRequest(){
}

ReservationRequest::ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count){
    this->course_name = course_name;
    this->weekday = weekday;
    this->start_hour = start_hour;
    this->end_hour = end_hour;
    this->student_count = student_count;
    if(end_hour <= start_hour) { //tratamento de erro
        throw std::invalid_argument("O horário de começo deve ser mais cedo do que o horário de fim");
    }
    if(start_hour < 7 || end_hour < 7 || start_hour > 21 || end_hour > 21) { //tratamento de erro
        throw std::invalid_argument("O horário válido para reserva de salas é entre 7h e 21h");
    }
}

ReservationRequest::~ReservationRequest(){
} 

int ReservationRequest::getStartHour() {
    return start_hour;
}

int ReservationRequest::getEndHour() {
    return end_hour;
}

int ReservationRequest::getStudentCount() {
    return student_count;
}

std::string ReservationRequest::getCourseName() {
    return course_name;
}

std::string ReservationRequest::getWeekday() {
    return weekday;
}   