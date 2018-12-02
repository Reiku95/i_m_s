#include <iostream>
#include <vector>
#include <string>

#include <stdlib.h>

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

void create_test(){
  Area *n_bor = new Area("Nova Borovina", 5400, 66480.6);
  int bins_places = 10;
  int bins_paper_1100l = 14;
  int bins_plastic_1100l = 18;
  int bins_glassc_1100l = 10;
  int bins_glassw_1100l = 10;
  int bins_bio_240l = 9;
  n_bor->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  trebic.push_back(n_bor);
}

void create_trebic(){
  // Vytvori oblast Boroviny.
  Area *n_bor = new Area("Nova Borovina", 5400, 66480.6);
  int bins_places = 10;
  int bins_paper_1100l = 14;
  int bins_plastic_1100l = 18;
  int bins_glassc_1100l = 10;
  int bins_glassw_1100l = 10;
  int bins_bio_240l = 9;
  n_bor->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *s_bor = new Area("Stara Borovina", 3300, 386000);
  bins_places = 11;
  bins_paper_1100l = 15;
  bins_plastic_1100l = 20;
  bins_glassc_1100l = 11;
  bins_glassw_1100l = 11;
  bins_bio_240l = 10;
  s_bor->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *v_mesto = new Area("Vnitrni Mesto", 2500, 200000);
  bins_places = 10;
  bins_paper_1100l = 16;
  bins_plastic_1100l = 21;
  bins_glassc_1100l = 10;
  bins_glassw_1100l = 10;
  bins_bio_240l = 8;
  v_mesto->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *h_domky = new Area("Horka Domky", 1900, 870000);
  bins_places = 27;
  bins_paper_1100l = 38;
  bins_plastic_1100l = 49;
  bins_glassc_1100l = 27;
  bins_glassw_1100l = 27;
  bins_bio_240l = 22;
  h_domky->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *n_mesto = new Area("Nove mesto", 3200, 628000);
  bins_places = 41;
  bins_paper_1100l = 58;
  bins_plastic_1100l = 73;
  bins_glassc_1100l = 40;
  bins_glassw_1100l = 40;
  bins_bio_240l = 27;
  n_mesto->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *kopce = new Area("Kopce", 3900, 55958);
  bins_places = 6;
  bins_paper_1100l = 8;
  bins_plastic_1100l = 11;
  bins_glassc_1100l = 7;
  bins_glassw_1100l = 7;
  bins_bio_240l = 3;
  kopce->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *hajek = new Area("Hajek", 4100, 344000);
  bins_places = 24;
  bins_paper_1100l = 29;
  bins_plastic_1100l = 36;
  bins_glassc_1100l = 14;
  bins_glassw_1100l = 14;
  bins_bio_240l = 11;
  hajek->create_places(bins_places, 0, bins_paper_1100l, 0, bins_plastic_1100l, 0, bins_glassc_1100l, 0, bins_glassw_1100l, bins_bio_240l);

  Area *tyn = new Area("Tyn", 5100, 1240000);
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

void print_final(){
  int i;

  for (i = 0; i < vozy.size(); i++){
    std::cout << "\n------------------------------------------\n";
    std::cout << "||| GARBAGE TRUCK FINAL\n";
    std::cout << "||| * name: " << vozy[i]->name << "\n";
    std::cout << "||| * garbage truck capacity: " << vozy[i]->capacity << "\n";
    std::cout << "||| * garbage truck load: " << vozy[i]->load << "\n";
    std::cout << "||| * nalozeno litru odpadu: " << vozy[i]->nalozeno_l_odpadu << "\n";
    std::cout << "||| * nalozeno kontejneru: " << vozy[i]->nalozeno_kontejneru << "\n";
    std::cout << "||| * cas nakladani kontejneru: "<< vozy[i]->cas_nakladani_kontejneru << "\n";
    std::cout << "||| * cas ve sbernem dvore: "<< vozy[i]->cas_ve_sbernem_dvore << "\n";
    std::cout << "||| * cas jezdeni v oblasti: "<< vozy[i]->cas_jezdeni_v_oblasti << "\n";
    std::cout << "||| * cas jezdeni do oblasti: "<< vozy[i]->cas_jezdeni_do_oblasti << "\n";
    std::cout << "------------------------------------------\n";
  }
}

void test(){
  trebic.clear();
  create_test();
  vozy.clear();
  generate_garbage_trucks(1);

  print_trebic();
}

void scenario1(){
  trebic.clear();
  create_trebic();
  vozy.clear();
  generate_garbage_trucks(1);
}

int main(int argc, char const *argv[]){

  Init(0);
  RandomSeed(time(NULL));

  int i;
  for (i = 1; i < argc; i++){
    if (0 == std::string("--test").compare(argv[i])){
      test();
      Run();
      print_final();
    }
    if (0 == std::string("--scenario").compare(argv[i])){
      if (argc > (i + 1)){
        i++;
        if (0 == std::string("1").compare(argv[i])){
          scenario1();
          Run();
          print_final();
        }
        if (0 == std::string("2").compare(argv[i])){
          scenario1();
        }
        if (0 == std::string("3").compare(argv[i])){
          scenario1();
        }
        if (0 == std::string("4").compare(argv[i])){
          scenario1();
        }
        if (0 == std::string("5").compare(argv[i])){
          scenario1();
        }
        if (0 == std::string("6").compare(argv[i])){
          scenario1();
        }
      } else {
        return 1;
      }
    }
  }

  return 0;
}
