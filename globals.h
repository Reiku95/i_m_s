#ifndef GLOBALS_H
#define GLOBALS_H

#define DEBUG false

#define GARBAGE_TRUCK_CAPACITY 9000

#define GARBAGE_TRUCK_MIN_SPEED 580
#define GARBAGE_TRUCK_MAX_SPEED 640

#define CONTAINER_EMPTY_SPEED_240_MIN 0.15
#define CONTAINER_EMPTY_SPEED_240_MAX 0.20

#define CONTAINER_EMPTY_SPEED_1100_MIN 0.20
#define CONTAINER_EMPTY_SPEED_1100_MAX 0.25

# define M_PI 3.14159265358979323846

typedef enum type_container{
  type_paper,
  type_plastic,
  type_glassc,
  type_glassw,
  type_bio
} t_type_container;

typedef enum id_area{
  id_nova_borovina,
  id_stara_borovina,
  id_vnitrni_mesto,
  id_horka_domky,
  id_nove_mesto,
  id_kopce,
  id_hajek,
  id_tyn,
  id_depo
}t_id_area;

#endif // GLOBALS_H