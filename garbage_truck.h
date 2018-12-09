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

    // Urcuje co zrovna sbira za surovinu.
    bool paper;
    bool plastic;
    bool glassc;
    bool glassw;
    bool bio;

    // Urcuje co muze sbirat za suroviny.
    bool allow_paper;
    bool allow_plastic;
    bool allow_glassc;
    bool allow_glassw;
    bool allow_bio;

    // Statistiky.
    int ujeto_metru;
    int nalozeno_l_odpadu;
    int ujeto_v_oblasti;
    int nalozeno_kontejneru;
    float cas_nakladani_kontejneru;
    float cas_ve_sbernem_dvore;
    float cas_jezdeni_v_oblasti;
    float cas_jezdeni_do_oblasti;
    int time_spend_way;

    int dump_ways;
    double time_in_dump;

    int liters_loaded;
    int weight_loaded;
    int bins_240_loaded;
    int bins_1100_loaded;
    double time_bins_emptying;

    int x_travels_between_areas;
    int distance_between_areas;
    double time_between_areas;

    int x_travels_between_places;
    int distance_between_places;
    double time_between_places;

    Garbage_truck(std::string p_name, std::vector<Area *> *city, int p_capacity);
    virtual ~Garbage_truck();
    void go_active();
    void go_passive();
    void Behavior();
    Area *get_area();

    void only_paper();
    void only_plastic();
    void only_glassc();
    void only_glassw();
    void only_bio();

    Area *get_area_allowed();
    void goto_location(t_id_area from, t_id_area to);
    Place *get_place_w_bins(Area *actual_area);
    void goto_place(Area *actual_area);
    void empty_the_containers(Place *place);
    void goto_dump(Area *actual_area);
    Area *get_area_by_id(t_id_area id);

protected:

private:
};

#endif // GARBAGE_TRUCK_H
