
#include "garbage_truck.h"

Garbage_truck::Garbage_truck(std::string p_name, std::vector<Area *> *city, int p_capacity){
  this->name = p_name;
  this->capacity = p_capacity;
  this->city = city;
  this->load = 0;
  this->ujeto_metru = 0;
  this->ujeto_v_oblasti = 0;
  this->nalozeno_l_odpadu = 0;
  this->nalozeno_kontejneru = 0;
  this->cas_nakladani_kontejneru = 0.0;
  this->cas_ve_sbernem_dvore = 0.0;
  this->cas_jezdeni_v_oblasti = 0.0;
  this->cas_jezdeni_do_oblasti = 0.0;
}

void Garbage_truck::go_active(){
  if (true == DEBUG){
    std::cout << this->name << " go_active\n";
  }
  
  this->Activate();
}

void Garbage_truck::go_passive(){
  if (true == DEBUG){
     std::cout << this->name << " go_passive\n";
  }

  this->Passivate();
}

void Garbage_truck::Behavior(){
  
}