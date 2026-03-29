# Trabalho 1: Room Reservation System
Neste projeto, implementamos um sistema para gerenciar as reservas de salas de aula durante uma semana. 
Um usuário pode solicitar a reserva de uma sala em um determinado dia e horário para a ministração de uma disciplina. O sistema verifica automaticamente se há alguma sala disponível naquela data. Caso exista, a reserva é criada e a primeira sala disponível é reservada. Caso contrário, o sistema retorna que não foi possível achar uma sala disponível para aquela data. 

## Instruções de compilação
Certifique-se de ter um compilador c++ instalado. 
Para compilar o projeto, digite no terminal:
"g++ main.cpp ReservationRequest.cpp ReservationSystem.cpp -o main"

## Instruções de execução
Após a compilação, execute: "./main.exe"

## Estrutura dos dados
Foi criada uma struct Reservation que contém uma variável do tipo ReservationRequest e um inteiro correspondente ao room_id. Todas as reservas foram armazenadas em um array dinâmico reservations do tipo Reservation.
