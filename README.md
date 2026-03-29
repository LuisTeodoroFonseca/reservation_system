# Trabalho 1: Room Reservation System
Neste projeto, implementamos um sistema para gerenciar as reservas de salas de aula durante uma semana. 
Um usuário pode solicitar a reserva de uma sala em um determinado dia e horário para a ministração de uma disciplina. O sistema verifica automaticamente se há alguma sala disponível naquela data. Caso exista, a reserva é criada e a primeira sala disponível é reservada. Caso contrário, o sistema retorna que não foi possível achar uma sala disponível para aquela data. 

## Instruções de compilação
Certifique-se de ter um compilador c++ instalado. 
Para compilar o projeto, digite no terminal:

"g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system"

## Instruções de execução
Após a compilação, execute: ".\reservation_system"

## Estrutura dos dados
<!-- Seja N o número de salas total, as salas foram numeradas de 0, 1, 2,..., N. Foi criada uma struct Reservation que contém uma variável do tipo ReservationRequest e um inteiro correspondente ao room_id (número da sala). Todas as reservas foram armazenadas em um array dinâmico reservations do tipo Reservation. Foi utilizado a variável do tipo int reservation_count para saber quantas reservas foram feitas. -->

A classe principal do nosso sistema, `ReservationSytem`, aramzena as seguintes informações:
- room_count: número de quartos. 
- room_capacities: array com a capacidade de cada quarto.
- capacidade: número máximo total de reservas do nosso sistema.
- reservations: array com as reservas feitas no nosso sistema.
- reservation_count: número de reservas total do sistema.

O número de salas do sistema é passado quando se instancia `ReservationSytem`, dessa forma, se for feito:

```cpp
ReservationSystem sistema {5, {40, 30, 20, 30, 50}};
```

Estamos passando para o nosso sistema que possuímos 5 salas com respectivas capacidades 40, 30, 20, 30 e 50. Para saber a capacidade máxima de uma sala específica, por exemplo a primeira sala:

```cpp
sistema.room_capacities[0];
```

Por esse motivo, foi criada uma struct `Reservation` que contém uma variável `request` que é uma instância da classe `ReservationRequest`, classe que armazena as informações de reserva:
- course_name
- weekday
- start_hour
- end_hour
- student_count 

e uma variável room_id, que depois de passar pelo processo de validação do sistema, é atribuído ao índice da sala correspondente no array `room_capacities`.