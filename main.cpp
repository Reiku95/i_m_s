#include <iostream>
#include <vector>
#include <string>

#include <stdlib.h>
#include <unistd.h>
#include <iomanip>

#include "simlib.h"

#include "garbage_truck.h"
#include "area.h"

// Oblasti, kde probiha odpadove hospodarstvi.
std::vector<Area *> trebic;
std::vector<Garbage_truck *> vozy;

void generate_garbage_trucks(int count){
  Garbage_truck *truck;
  int i;
  for (i = 0; i < count; i++){
    std::string name = "Garbage truck " + std::to_string(i);
    truck = new Garbage_truck(name, &trebic, GARBAGE_TRUCK_CAPACITY);
    vozy.push_back(truck);
    truck->Activate();
  }
}

void create_trebic_one_area(){
  Area *n_bor = new Area("Nova Borovina", 5400, 66480.6, 1, id_nova_borovina);
  int bins_places = 10;
  int bins_paper_1100l = 14;
  int bins_plastic_1100l = 18;
  int bins_glassc_1100l = 10;
  int bins_glassw_1100l = 10;
  int bins_bio_240l = 9;
  n_bor->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  trebic.push_back(n_bor);
}

void create_trebic_paper_only(){
  // Vytvori oblast Boroviny.
  Area *n_bor = new Area("Nova Borovina", 5400, 66480.6, 8, id_nova_borovina);
  int bins_places = 10;
  int bins_paper_1100l = 14;
  n_bor->create_places(bins_places, 0, bins_paper_1100l, 0, 0, 0, 0, 0, 0, 0);

  Area *s_bor = new Area("Stara Borovina", 3300, 386000, 4, id_stara_borovina);
  bins_places = 11;
  bins_paper_1100l = 15;
  s_bor->create_places(bins_places, 0, bins_paper_1100l, 0, 0, 0, 0, 0, 0, 0);

  Area *v_mesto = new Area("Vnitrni Mesto", 2500, 200000, 2, id_vnitrni_mesto);
  bins_places = 10;
  bins_paper_1100l = 16;
  v_mesto->create_places(bins_places, 0, bins_paper_1100l, 0, 0, 0, 0, 0, 0, 0);

  Area *h_domky = new Area("Horka Domky", 1900, 870000, 1, id_horka_domky);
  bins_places = 27;
  bins_paper_1100l = 38;
  h_domky->create_places(bins_places, 0, bins_paper_1100l, 0, 0, 0, 0, 0, 0, 0);

  Area *n_mesto = new Area("Nove mesto", 3200, 628000, 3, id_nove_mesto);
  bins_places = 41;
  bins_paper_1100l = 58;
  n_mesto->create_places(bins_places, 0, bins_paper_1100l, 0, 0, 0, 0, 0, 0, 0);

  Area *kopce = new Area("Kopce", 3900, 55958, 5, id_kopce);
  bins_places = 6;
  bins_paper_1100l = 8;
  kopce->create_places(bins_places, 0, bins_paper_1100l, 0, 0, 0, 0, 0, 0, 0);

  Area *hajek = new Area("Hajek", 4100, 344000, 6, id_hajek);
  bins_places = 24;
  bins_paper_1100l = 29;
  hajek->create_places(bins_places, 0, bins_paper_1100l, 0, 0, 0, 0, 0, 0, 0);

  Area *tyn = new Area("Tyn", 5100, 1240000, 7, id_tyn);
  bins_places = 27;
  bins_paper_1100l = 35;
  tyn->create_places(bins_places, 0, bins_paper_1100l, 0, 0, 0, 0, 0, 0, 0);

  trebic.push_back(n_bor);
  trebic.push_back(s_bor);
  trebic.push_back(v_mesto);
  trebic.push_back(h_domky);
  trebic.push_back(n_mesto);
  trebic.push_back(kopce);
  trebic.push_back(hajek);
  trebic.push_back(tyn);
}

void create_trebic_month(){
  // Vytvori oblast Boroviny.
  Area *n_bor = new Area("Nova Borovina", 5400, 66480.6, 8, id_nova_borovina);
  int bins_places = 10;
  int bins_paper_1100l = 14*4;
  int bins_plastic_1100l = 18*4;
  int bins_glassc_1100l = 10;
  int bins_glassw_1100l = 10;
  int bins_bio_240l = 9*4;
  n_bor->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *s_bor = new Area("Stara Borovina", 3300, 386000, 4, id_stara_borovina);
  bins_places = 11;
  bins_paper_1100l = 15*4;
  bins_plastic_1100l = 20*4;
  bins_glassc_1100l = 11;
  bins_glassw_1100l = 11;
  bins_bio_240l = 10*4;
  s_bor->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *v_mesto = new Area("Vnitrni Mesto", 2500, 200000, 2, id_vnitrni_mesto);
  bins_places = 10;
  bins_paper_1100l = 16*4;
  bins_plastic_1100l = 21*4;
  bins_glassc_1100l = 10;
  bins_glassw_1100l = 10;
  bins_bio_240l = 8*4;
  v_mesto->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *h_domky = new Area("Horka Domky", 1900, 870000, 1, id_horka_domky);
  bins_places = 27;
  bins_paper_1100l = 38*4;
  bins_plastic_1100l = 49*4;
  bins_glassc_1100l = 27;
  bins_glassw_1100l = 27;
  bins_bio_240l = 22*4;
  h_domky->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *n_mesto = new Area("Nove mesto", 3200, 628000, 3, id_nove_mesto);
  bins_places = 41;
  bins_paper_1100l = 58*4;
  bins_plastic_1100l = 73*4;
  bins_glassc_1100l = 40;
  bins_glassw_1100l = 40;
  bins_bio_240l = 27*4;
  n_mesto->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *kopce = new Area("Kopce", 3900, 55958, 5, id_kopce);
  bins_places = 6;
  bins_paper_1100l = 8*4;
  bins_plastic_1100l = 11*4;
  bins_glassc_1100l = 7;
  bins_glassw_1100l = 7;
  bins_bio_240l = 3*4;
  kopce->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *hajek = new Area("Hajek", 4100, 344000, 6, id_hajek);
  bins_places = 24;
  bins_paper_1100l = 29*4;
  bins_plastic_1100l = 36*4;
  bins_glassc_1100l = 14;
  bins_glassw_1100l = 14;
  bins_bio_240l = 11*4;
  hajek->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *tyn = new Area("Tyn", 5100, 1240000, 7, id_tyn);
  bins_places = 27;
  bins_paper_1100l = 35*4;
  bins_plastic_1100l = 47*4;
  bins_glassc_1100l = 23;
  bins_glassw_1100l = 23;
  bins_bio_240l = 17*4;
  tyn->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  trebic.push_back(n_bor);
  trebic.push_back(s_bor);
  trebic.push_back(v_mesto);
  trebic.push_back(h_domky);
  trebic.push_back(n_mesto);
  trebic.push_back(kopce);
  trebic.push_back(hajek);
  trebic.push_back(tyn);
}

void create_trebic_priority(){
  // Vytvori oblast Boroviny.
  Area *n_bor = new Area("Nova Borovina", 5400, 66480.6, 1, id_nova_borovina);
  int bins_places = 10;
  int bins_paper_1100l = 14;
  int bins_plastic_1100l = 18;
  int bins_glassc_1100l = 10;
  int bins_glassw_1100l = 10;
  int bins_bio_240l = 9;
  n_bor->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *s_bor = new Area("Stara Borovina", 3300, 386000, 5, id_stara_borovina);
  bins_places = 11;
  bins_paper_1100l = 15;
  bins_plastic_1100l = 20;
  bins_glassc_1100l = 11;
  bins_glassw_1100l = 11;
  bins_bio_240l = 10;
  s_bor->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *v_mesto = new Area("Vnitrni Mesto", 2500, 200000, 7, id_vnitrni_mesto);
  bins_places = 10;
  bins_paper_1100l = 16;
  bins_plastic_1100l = 21;
  bins_glassc_1100l = 10;
  bins_glassw_1100l = 10;
  bins_bio_240l = 8;
  v_mesto->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *h_domky = new Area("Horka Domky", 1900, 870000, 8, id_horka_domky);
  bins_places = 27;
  bins_paper_1100l = 38;
  bins_plastic_1100l = 49;
  bins_glassc_1100l = 27;
  bins_glassw_1100l = 27;
  bins_bio_240l = 22;
  h_domky->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *n_mesto = new Area("Nove mesto", 3200, 628000, 6, id_nove_mesto);
  bins_places = 41;
  bins_paper_1100l = 58;
  bins_plastic_1100l = 73;
  bins_glassc_1100l = 40;
  bins_glassw_1100l = 40;
  bins_bio_240l = 27;
  n_mesto->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *kopce = new Area("Kopce", 3900, 55958, 4, id_kopce);
  bins_places = 6;
  bins_paper_1100l = 8;
  bins_plastic_1100l = 11;
  bins_glassc_1100l = 7;
  bins_glassw_1100l = 7;
  bins_bio_240l = 3;
  kopce->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *hajek = new Area("Hajek", 4100, 344000, 3, id_hajek);
  bins_places = 24;
  bins_paper_1100l = 29;
  bins_plastic_1100l = 36;
  bins_glassc_1100l = 14;
  bins_glassw_1100l = 14;
  bins_bio_240l = 11;
  hajek->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *tyn = new Area("Tyn", 5100, 1240000, 2, id_tyn);
  bins_places = 27;
  bins_paper_1100l = 35;
  bins_plastic_1100l = 47;
  bins_glassc_1100l = 23;
  bins_glassw_1100l = 23;
  bins_bio_240l = 17;
  tyn->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  trebic.push_back(n_bor);
  trebic.push_back(s_bor);
  trebic.push_back(v_mesto);
  trebic.push_back(h_domky);
  trebic.push_back(n_mesto);
  trebic.push_back(kopce);
  trebic.push_back(hajek);
  trebic.push_back(tyn);
}

void create_trebic(int num){
  int bins_places = 10;
  int bins_paper_1100l = 14;
  int bins_plastic_1100l = 18;
  int bins_glassc_1100l = 10;
  int bins_glassw_1100l = 10;
  int bins_bio_240l = 9;
  int i = 0;

  if (num > i){
    Area *n_bor = new Area("Nova Borovina", 5400, 66480.6, 8, id_nova_borovina);
    bins_places = 10;
    bins_paper_1100l = 14;
    bins_plastic_1100l = 18;
    bins_glassc_1100l = 10;
    bins_glassw_1100l = 10;
    bins_bio_240l = 9;
    n_bor->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);
    trebic.push_back(n_bor);
    i++;
  }

  if (num > i){
    Area *s_bor = new Area("Stara Borovina", 3300, 386000, 4, id_stara_borovina);
    bins_places = 11;
    bins_paper_1100l = 15;
    bins_plastic_1100l = 20;
    bins_glassc_1100l = 11;
    bins_glassw_1100l = 11;
    bins_bio_240l = 10;
    s_bor->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);
    trebic.push_back(s_bor);
    i++;
  }

  if (num > i){
    Area *v_mesto = new Area("Vnitrni Mesto", 2500, 200000, 2, id_vnitrni_mesto);
    bins_places = 10;
    bins_paper_1100l = 16;
    bins_plastic_1100l = 21;
    bins_glassc_1100l = 10;
    bins_glassw_1100l = 10;
    bins_bio_240l = 8;
    v_mesto->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);
    trebic.push_back(v_mesto);
    i++;
  }

  if (num > i){
    Area *h_domky = new Area("Horka Domky", 1900, 870000, 1, id_horka_domky);
    bins_places = 27;
    bins_paper_1100l = 38;
    bins_plastic_1100l = 49;
    bins_glassc_1100l = 27;
    bins_glassw_1100l = 27;
    bins_bio_240l = 22;
    h_domky->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);
    trebic.push_back(h_domky);
    i++;
  }

  if (num > i){
    Area *n_mesto = new Area("Nove mesto", 3200, 628000, 3, id_nove_mesto);
    bins_places = 41;
    bins_paper_1100l = 58;
    bins_plastic_1100l = 73;
    bins_glassc_1100l = 40;
    bins_glassw_1100l = 40;
    bins_bio_240l = 27;
    n_mesto->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);
    trebic.push_back(n_mesto);
    i++;
  }

  if (num > i){
    Area *kopce = new Area("Kopce", 3900, 55958, 5, id_kopce);
    bins_places = 6;
    bins_paper_1100l = 8;
    bins_plastic_1100l = 11;
    bins_glassc_1100l = 7;
    bins_glassw_1100l = 7;
    bins_bio_240l = 3;
    kopce->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);
    trebic.push_back(kopce);
    i++;
  }

  if (num > i){
    Area *hajek = new Area("Hajek", 4100, 344000, 6, id_hajek);
    bins_places = 24;
    bins_paper_1100l = 29;
    bins_plastic_1100l = 36;
    bins_glassc_1100l = 14;
    bins_glassw_1100l = 14;
    bins_bio_240l = 11;
    hajek->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);
    trebic.push_back(hajek);
    i++;
  }

  if (num > i){
    Area *tyn = new Area("Tyn", 5100, 1240000, 7, id_tyn);
    bins_places = 27;
    bins_paper_1100l = 35;
    bins_plastic_1100l = 47;
    bins_glassc_1100l = 23;
    bins_glassw_1100l = 23;
    bins_bio_240l = 17;
    tyn->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);
    trebic.push_back(tyn);
    i++;
  }
}

void print_trebic(){
  int i;
  for (i = 0; i < trebic.size(); i++){
    std::cout << "\n------------------------------------------\n";
    std::cout << "||| AREA\n";
    std::cout << "||| * name: " << trebic[i]->name << "\n";
    std::cout << "||| * travel_length: " << trebic[i]->travel_length << "\n";
    std::cout << "||| * surface: " << trebic[i]->surface << "\n";
    std::cout << "||| * PLACES " << "\n";
    int i_1;
    for (i_1 = 0; i_1 < trebic[i]->places.size(); i_1++){
      std::cout << "||| ||| * PLACE " << i_1 << "\n";
      std::cout << "||| ||| * bins_paper_240l: " << trebic[i]->places[i_1]->bins_paper_240l << "\n";
      std::cout << "||| ||| * total_bins_paper_240l: " << trebic[i]->places[i_1]->total_bins_paper_240l << "\n";

      std::cout << "||| ||| * bins_paper_1100l: " << trebic[i]->places[i_1]->bins_paper_1100l << "\n";
      std::cout << "||| ||| * total_bins_paper_1100l: " << trebic[i]->places[i_1]->total_bins_paper_1100l << "\n";

      std::cout << "||| ||| * bins_plastic_240l: " << trebic[i]->places[i_1]->bins_plastic_240l << "\n";
      std::cout << "||| ||| * total_bins_plastic_240l: " << trebic[i]->places[i_1]->total_bins_plastic_240l << "\n";

      std::cout << "||| ||| * bins_plastic_1100l: " << trebic[i]->places[i_1]->bins_plastic_1100l << "\n";
      std::cout << "||| ||| * total_bins_plastic_1100l: " << trebic[i]->places[i_1]->total_bins_plastic_1100l << "\n";

      std::cout << "||| ||| * bins_glassc_240l: " << trebic[i]->places[i_1]->bins_glassc_240l << "\n";
      std::cout << "||| ||| * total_bins_glassc_240l: " << trebic[i]->places[i_1]->total_bins_glassc_240l << "\n";

      std::cout << "||| ||| * bins_glassc_1100l: " << trebic[i]->places[i_1]->bins_glassc_1100l << "\n";
      std::cout << "||| ||| * total_bins_glassc_1100l: " << trebic[i]->places[i_1]->total_bins_glassc_1100l << "\n";

      std::cout << "||| ||| * bins_glassw_240l: " << trebic[i]->places[i_1]->bins_glassw_240l << "\n";
      std::cout << "||| ||| * total_bins_glassw_240l: " << trebic[i]->places[i_1]->total_bins_glassw_240l << "\n";

      std::cout << "||| ||| * bins_glassw_1100l: " << trebic[i]->places[i_1]->bins_glassw_1100l << "\n";
      std::cout << "||| ||| * total_bins_glassw_1100l: " << trebic[i]->places[i_1]->total_bins_glassw_1100l << "\n";

      std::cout << "||| ||| * bins_bio_240l: " << trebic[i]->places[i_1]->bins_bio_240l << "\n";
      std::cout << "||| ||| * total_bins_bio_240l: " << trebic[i]->places[i_1]->total_bins_bio_240l << "\n";
    }
    std::cout << "------------------------------------------\n";
  }
}

void gt_print_final(int i){
  std::cout << "\n------------------------------------------\n";
  std::cout << "||| GARBAGE TRUCK FINAL\n";
  std::cout << "||| * name: " << vozy[i]->name << "\n";
  std::cout << "||| * garbage truck capacity: " << vozy[i]->capacity <<  ", garbage truck load: " << vozy[i]->load <<"\n";
  std::cout << "||| * pocet vylozeni ve sbernem dvore: "<< vozy[i]->dump_ways << "\n";
  std::cout << "||| * cas ve sbernem dvore: "<< vozy[i]->time_in_dump << "\n";

  std::cout << "  ||| * odvezeno litru: "<< vozy[i]->liters_loaded << ", odvezeno kg: "<< vozy[i]->weight_loaded << "\n";
  std::cout << "  ||| * obslouzeno 240l kontejneru: "<< vozy[i]->bins_240_loaded << ", obslouzeno 1100l kontejneru: "<< vozy[i]->bins_1100_loaded << "\n";
  std::cout << "  ||| * doba vysypavani kontejneru: "<< vozy[i]->time_bins_emptying << "\n";

  std::cout << "||| * pocet cest mezi oblastmi: "<< vozy[i]->x_travels_between_areas << "\n";
  std::cout << "||| * ujeta vzdalenost mezi oblastmi: "<< vozy[i]->distance_between_areas << "\n";
  std::cout << "||| * doba jezdeni mezi oblastmi: "<< vozy[i]->time_between_areas << "\n";

  std::cout << "  ||| * pocet cest mezi misty s kontejnery: "<< vozy[i]->x_travels_between_places << "\n";
  std::cout << "  ||| * ujeta vzdalenost mezi misty: "<< vozy[i]->distance_between_places << "\n";
  std::cout << "  ||| * doba jezdeni mezi misty: "<< vozy[i]->time_between_places << "\n";

  double time;
  time += vozy[i]->time_in_dump;
  time += vozy[i]->time_bins_emptying;
  time += vozy[i]->time_between_areas;
  time += vozy[i]->time_between_places;

  int dist;
  dist += vozy[i]->distance_between_areas;
  dist += vozy[i]->distance_between_places;

  std::cout << "||| * celkova doba prace: "<< time << "\n";
  std::cout << "||| * celkova ujeta vzdalenost: "<< dist << "\n";
  std::cout << "------------------------------------------\n";
}

// Jedno vozidlo
void scenario1(int num){
  Init(0);
  RandomSeed(time(NULL));
  std::cout << "SCENARIO1------------------------------\n";
  trebic.clear();
  create_trebic(num);
  vozy.clear();
  generate_garbage_trucks(1);
  Run();
  std::cout << "+++ * " << " Oblasti: "<< num << "\n";
  std::cout << "+++ * " << " Za jednu cestu do sberneho dvora odvezeno kg: "<< vozy[0]->weight_loaded / vozy[0]->dump_ways << "\n";
  std::cout << "------------------------------\n";
}

void scenario2(){
  Init(0);
  RandomSeed(time(NULL));
  std::cout << "SCENARIO2------------------------------\n";
  trebic.clear();
  create_trebic(8);
  vozy.clear();
  generate_garbage_trucks(1);
  Run();
  gt_print_final(0);
  std::cout << "------------------------------\n";
}

void scenario3(int num){
  Init(0);
  RandomSeed(time(NULL));
  std::cout << "SCENARIO3------------------------------\n";
  trebic.clear();
  create_trebic_month();
  vozy.clear();
  generate_garbage_trucks(num);
  Run();
  int i;
  std::cout << "+++ * " << " pouzitych vozu: "<< num << "\n";
  double time = 0.0;
  int dist = 0;
  for (i = 0; i < num; i++){
    
    time += vozy[i]->time_in_dump;
    time += vozy[i]->time_bins_emptying;
    time += vozy[i]->time_between_areas;
    time += vozy[i]->time_between_places;

    dist += vozy[i]->distance_between_areas;
    dist += vozy[i]->distance_between_places;
  }
  std::cout << "+++ * " << " cas potrebny k odvezeni odpadu: "<< time/num/60 << ", najeto km: " << dist / 1000 << "\n";
  std::cout << "------------------------------\n";
}

void scenario4(){
  Init(0);
  RandomSeed(time(NULL));
  std::cout << "SCENARIO4------------------------------\n";
  trebic.clear();
  create_trebic_priority();
  vozy.clear();
  int num = 3;
  generate_garbage_trucks(num);
  Run();
  double time = 0.0;
  int dist = 0;
  int i;
  for (i = 0; i < num; i++){
    
    time += vozy[i]->time_in_dump;
    time += vozy[i]->time_bins_emptying;
    time += vozy[i]->time_between_areas;
    time += vozy[i]->time_between_places;

    dist += vozy[i]->distance_between_areas;
    dist += vozy[i]->distance_between_places;
  }
  std::cout << "+++ * " << " cas potrebny k odvezeni odpadu: "<< time/num/60 << ", najeto km: " << dist / 1000 << "\n";
  std::cout << "------------------------------\n";
}

void scenario4_1(){
  Init(0);
  RandomSeed(time(NULL));
  std::cout << "SCENARIO4------------------------------\n";
  trebic.clear();
  create_trebic(8);
  vozy.clear();
  int num = 3;
  generate_garbage_trucks(num);
  Run();
  double time = 0.0;
  int dist = 0;
  int i;
  for (i = 0; i < num; i++){
    
    time += vozy[i]->time_in_dump;
    time += vozy[i]->time_bins_emptying;
    time += vozy[i]->time_between_areas;
    time += vozy[i]->time_between_places;

    dist += vozy[i]->distance_between_areas;
    dist += vozy[i]->distance_between_places;
  }
  std::cout << "+++ * " << " cas potrebny k odvezeni odpadu: "<< time/num/60 << ", najeto km: " << dist / 1000 << "\n";
  std::cout << "------------------------------\n";
}

int main(int argc, char const *argv[]){

  int i;
  for (i = 1; i < argc; i++){
    if (0 == std::string("--scenario").compare(argv[i])){
      if (argc > (i + 1)){
        i++;
        if (0 == std::string("1").compare(argv[i])){
          scenario1(1);
          scenario1(2);
          scenario1(3);
          scenario1(4);
          scenario1(5);
          scenario1(6);
          scenario1(7);
          scenario1(8);
        }
        if (0 == std::string("2").compare(argv[i])){
          scenario2();
        }
        if (0 == std::string("3").compare(argv[i])){
          scenario3(1);
          scenario3(2);
          scenario3(3);
          scenario3(4);
          scenario3(5);
          scenario3(6);
          scenario3(7);
          scenario3(8);
          scenario3(9);
          scenario3(10);
        }
        if (0 == std::string("4").compare(argv[i])){
          scenario4();
          scenario4_1();
        }
      } else {
        return 1;
      }
    }
  }

  return 0;
}
