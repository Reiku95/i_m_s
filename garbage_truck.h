#ifndef GARBAGE_TRUCK_H
#define GARBAGE_TRUCK_H

#include <iostream>
#include <vector>
#include <string>

#include "simlib.h"

#include "globals.h"
#include "area.h"

class Garbage_truck : public Process {
  
  public:
    std::string name;
    std::vector<Area *> *city;

    int capacity;
    int load;

    // Statistiky.
    int ujeto_metru;
    int nalozeno_l_odpadu;
    int ujeto_v_oblasti;
    int nalozeno_kontejneru;
    float cas_nakladani_kontejneru;
    float cas_ve_sbernem_dvore;
    float cas_jezdeni_v_oblasti;
    float cas_jezdeni_do_oblasti;

    Garbage_truck(std::string p_name, std::vector<Area *> *city, int p_capacity);
    void go_active();
    void go_passive();
    void Behavior();

  protected:

  private:
};

#endif // GARBAGE_TRUCK_H