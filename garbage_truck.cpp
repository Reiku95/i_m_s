
#include "garbage_truck.h"

#include <cmath>

Garbage_truck::Garbage_truck(std::string p_name, std::vector<Area *> *city, int p_capacity){
  this->name = p_name;
  this->capacity = p_capacity;
  this->city = city;
  this->load = 0;

  this->paper = false;
  this->plastic = false;
  this->glassc = false;
  this->glassw = false;
  this->bio = false;

  this->allow_paper = true;
  this->allow_plastic = true;
  this->allow_glassc = true;
  this->allow_glassw = true;
  this->allow_bio = true;

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

/*
 Najde oblast s vhodnym odpadem s nejvyssi prioritou.
 */
Area *Garbage_truck::get_area(){
  Area *result = NULL;
  // Najde oblast, kde neni vyneseny sbirany druh odpadu.
  int i;
  for (i = 0; i < this->city->size(); i++){
    Area *temp = this->city->at(i);
    // Pokud ma oblast surovinu, kterou sbira.
    if (this->paper){
      if (NULL != temp->get_place_w_bins(type_paper)){
        if (NULL == result || result->priority < temp->priority){
          result = temp;
        }
      }
    } else if (this->plastic){
      if (NULL != temp->get_place_w_bins(type_plastic)){
        if (NULL == result || result->priority < temp->priority){
          result = temp;
        }
      }
    } else if (this->glassc){
      if (NULL != temp->get_place_w_bins(type_glassc)){
        if (NULL == result || result->priority < temp->priority){
          result = temp;
        }
      }
    } else if (this->glassw){
      if (NULL != temp->get_place_w_bins(type_glassw)){
        if (NULL == result || result->priority < temp->priority){
          result = temp;
        }
      }
    } else if (this->bio){
      if (NULL != temp->get_place_w_bins(type_bio)){
        if (NULL == result || result->priority < temp->priority){
          result = temp;
        }
      }
    }
  }
  return result;
}

void Garbage_truck::only_paper(){
  this->paper = true;
  this->plastic = false;
  this->glassc = false;
  this->glassw = false;
  this->bio = false;
}

void Garbage_truck::only_plastic(){
  this->paper = false;
  this->plastic = true;
  this->glassc = false;
  this->glassw = false;
  this->bio = false;
}

void Garbage_truck::only_glassc(){
  this->paper = false;
  this->plastic = false;
  this->glassc = true;
  this->glassw = false;
  this->bio = false;
}

void Garbage_truck::only_glassw(){
  this->paper = false;
  this->plastic = false;
  this->glassc = false;
  this->glassw = true;
  this->bio = false;
}

void Garbage_truck::only_bio(){
  this->paper = false;
  this->plastic = false;
  this->glassc = false;
  this->glassw = false;
  this->bio = true;
}

Area *Garbage_truck::get_area_by_id(t_id_area id){
  int i;
  for (i = 0; i < this->city->size(); i++){
    Area *temp = this->city->at(i);
    if (id == temp->id){
      return temp;
    }
  }
  return NULL;
}

Area *Garbage_truck::get_area_allowed(){
  Area *actual_area = NULL;
  if (this->allow_paper){
    this->only_paper();
    actual_area = get_area();
    if (NULL != actual_area){
      return actual_area;
    }
  }
  if (this->allow_plastic){
    this->only_plastic();
    actual_area = get_area();
    if (NULL != actual_area){
      return actual_area;
    }
  }
  if (this->allow_glassc){
    this->only_glassc();
    actual_area = get_area();
    if (NULL != actual_area){
      return actual_area;
    }
  }
  if (this->allow_glassw){
    this->only_glassw();
    actual_area = get_area();
    if (NULL != actual_area){
      return actual_area;
    }
  }
  if (this->allow_bio){
    this->only_bio();
    actual_area = get_area();
    if (NULL != actual_area){
      return actual_area;
    }
  }
  return NULL;
}

void Garbage_truck::goto_location(t_id_area from, t_id_area to){
  int distance = 0;

  if (from == to){
    return;
  }

  // depo ->
  if (id_depo == from || id_depo == to){
    if (id_nova_borovina == from || id_nova_borovina == to){
      distance = 5400;
    }
    if (id_stara_borovina == from || id_stara_borovina == to){
      distance = 3300;
    }
    if (id_vnitrni_mesto == from || id_vnitrni_mesto == to){
      distance = 2500;
    }
    if (id_horka_domky == from || id_horka_domky == to){
      distance = 1900;
    }
    if (id_nove_mesto == from || id_nove_mesto == to){
      distance = 3200;
    }
    if (id_kopce == from || id_kopce == to){
      distance = 3900;
    }
    if (id_hajek == from || id_hajek == to){
      distance = 4100;
    }
    if (id_tyn == from || id_tyn == to){
      distance = 5100;
    }
  }

  // Nova borovina ->
  if (id_nova_borovina == from || id_nova_borovina == to){
    if (id_stara_borovina == from || id_stara_borovina == to){
      distance = 2220;
    }
    if (id_vnitrni_mesto == from || id_vnitrni_mesto == to){
      distance = 4100;
    }
    if (id_horka_domky == from || id_horka_domky == to){
      distance = 4500;
    }
    if (id_nove_mesto == from || id_nove_mesto == to){
      distance = 5900;
    }
    if (id_kopce == from || id_kopce == to){
      distance = 6300;
    }
    if (id_hajek == from || id_hajek == to){
      distance = 6100;
    }
    if (id_tyn == from || id_tyn == to){
      distance = 4800;
    }
  }

  // Stara borovina ->
  if (id_stara_borovina == from || id_stara_borovina == to){
    if (id_vnitrni_mesto == from || id_vnitrni_mesto == to){
      distance = 1500;
    }
    if (id_horka_domky == from || id_horka_domky == to){
      distance = 1800;
    }
    if (id_nove_mesto == from || id_nove_mesto == to){
      distance = 3100;
    }
    if (id_kopce == from || id_kopce == to){
      distance = 3700;
    }
    if (id_hajek == from || id_hajek == to){
      distance = 3900;
    }
    if (id_tyn == from || id_tyn == to){
      distance = 2600;
    }
  }

  // Vnitrni mesto ->
  if (id_vnitrni_mesto == from || id_vnitrni_mesto == to){
    if (id_horka_domky == from || id_horka_domky == to){
      distance = 1200;
    }
    if (id_nove_mesto == from || id_nove_mesto == to){
      distance = 1700;
    }
    if (id_kopce == from || id_kopce == to){
      distance = 2400;
    }
    if (id_hajek == from || id_hajek == to){
      distance = 2600;
    }
    if (id_tyn == from || id_tyn == to){
      distance = 2300;
    }
  }

  // Horka domky ->
  if (id_horka_domky == from || id_horka_domky == to){
    if (id_nove_mesto == from || id_nove_mesto == to){
      distance = 2500;
    }
    if (id_kopce == from || id_kopce == to){
      distance = 3200;
    }
    if (id_hajek == from || id_hajek == to){
      distance = 4600;
    }
    if (id_tyn == from || id_tyn == to){
      distance = 3000;
    }
  }

  // Nove mesto ->
  if (id_nove_mesto == from || id_nove_mesto == to){
    if (id_kopce == from || id_kopce == to){
      distance = 1500;
    }
    if (id_hajek == from || id_hajek == to){
      distance = 1100;
    }
    if (id_tyn == from || id_tyn == to){
      distance = 2100;
    }
  }

  // Kopce ->
  if (id_kopce == from || id_kopce == to){
    if (id_hajek == from || id_hajek == to){
      distance = 2500;
    }
    if (id_tyn == from || id_tyn == to){
      distance = 3000;
    }
  }

  // Hajek ->
  if (id_hajek == from || id_hajek == to){
    if (id_tyn == from || id_tyn == to){
      distance = 1800;
    }
  }

  if (0 != distance){
    float min = (float)distance / (float)GARBAGE_TRUCK_MAX_SPEED;
    float max = (float)distance / (float)GARBAGE_TRUCK_MIN_SPEED;
    if (DEBUG){
      std::cout << "Garbage truck: " << this->name << ", jede z : " << from << " do oblasti: " << to << ", vzdalenost: " << distance << "\n";
    }
    std::cout << "pred" << min << "\n";
    Uniform(min, max);
    std::cout << "po" << "\n";
  } else {
    if (DEBUG){
      std::cout << "Neznama distance Garbage truck: " << this->name << ", jede z : " << from << " do oblasti: " << to << ", vzdalenost: " << distance << "\n";
    }
  }
}

// Vozidlo odjede k mistu, kde jsou popelnice.
void Garbage_truck::goto_place(Area *actual_area){
  float r = (float)std::sqrt(actual_area->surface / M_PI)/6;
  float min = (float)r * 4.0;
  float max = (float)r * 5.0;
  if (DEBUG){
      std::cout << "Garbage truck: " << this->name << ", jede k popelnicim: min: " << min << " max: " << max << "\n";
  }
  Uniform(min, max);
}

Place *Garbage_truck::get_place_w_bins(Area *actual_area){
  // Zabere si misto se sbiranym odpadem.
  if (this->paper){
    return actual_area->get_place_w_bins(type_paper);
  } else if (this->plastic){
    return actual_area->get_place_w_bins(type_plastic);
  } else if (this->glassc){
    return actual_area->get_place_w_bins(type_glassc);
  } else if (this->glassw){
    return actual_area->get_place_w_bins(type_glassw);
  } else if (this->bio){
    return actual_area->get_place_w_bins(type_bio);
  }
  return NULL;
}

void Garbage_truck::empty_the_containers(Place *place){
  /*if (DEBUG){
    std::cout << "Garbage truck: " << this->name << ", Obsazuje misto." << "\n";
  }*/
  // Obsadi misto s popelnicemi.
  place->Seize(this);
  int containers_240 = 0;
  int containers_1100 = 0;

  int container_240_weight = 0;
  int container_1100_weight = 0;

  // Zacne vyvazet
  if (this->paper){
    containers_240 = place->bins_paper_240l;
    containers_1100 = place->bins_paper_1100l;
    container_240_weight = 41;
    container_1100_weight = 188;
  } else if (this->plastic){
    containers_240 = place->bins_plastic_240l;
    containers_1100 = place->bins_plastic_1100l;
    container_240_weight = 16;
    container_1100_weight = 73;
  } else if (this->glassc){
    containers_240 = place->bins_glassc_240l;
    containers_1100 = place->bins_glassc_1100l;
    container_240_weight = 76;
    container_1100_weight = 348;
  } else if (this->glassw){
    containers_240 = place->bins_glassw_240l;
    containers_1100 = place->bins_glassw_1100l;
    container_240_weight = 76;
    container_1100_weight = 348;
  } else if (this->bio){
    containers_240 = place->bins_bio_240l;
    container_240_weight = 48;
  }

  int i;
  for (i = 0; i < containers_240; i++){
    if ((this->load + container_240_weight) > this->capacity ){
      place->Release(this);
      return;
    }
    // Ma kapacitu na nalozeni.
    Uniform(CONTAINER_EMPTY_SPEED_240_MIN, CONTAINER_EMPTY_SPEED_240_MAX);
    this->load += container_240_weight;
    if (this->paper){
      place->bins_paper_240l -= 1;
    } else if (this->plastic){
      place->bins_plastic_240l -= 1;
    } else if (this->glassc){
      place->bins_glassc_240l -= 1;
    } else if (this->glassw){
      place->bins_glassw_240l -= 1;
    } else if (this->bio){
      place->bins_bio_240l -= 1;
    }
  }

  for (i = 0; i < containers_1100; i++){
    if ((this->load + container_1100_weight) > this->capacity ){
      place->Release(this);
      return;
    }
    // Ma kapacitu na nalozeni.
    Uniform(CONTAINER_EMPTY_SPEED_1100_MIN, CONTAINER_EMPTY_SPEED_1100_MAX);
    this->load += container_1100_weight;
    if (this->paper){
      place->bins_paper_1100l -= 1;
    } else if (this->plastic){
      place->bins_plastic_1100l -= 1;
    } else if (this->glassc){
      place->bins_glassc_1100l -= 1;
    } else if (this->glassw){
      place->bins_glassw_1100l -= 1;
    }
  }

  // Opusti misto s popelnicemi
  place->Release(this);
  /*if (DEBUG){
    std::cout << "Garbage truck: " << this->name << ", Opusti misto." << "\n";
  }*/
}

void Garbage_truck::goto_dump(Area *actual_area){
  if (DEBUG){
    std::cout << "Garbage truck: " << this->name << ", jede vylozit : " << actual_area->id << " do sberneho dvora, vzdalenost: " << actual_area->travel_length << "\n";
  }

  if (NULL == actual_area){
    // Nikam nejede jen vylozi.
    Uniform(4,5);
    this->load = 0;
  }

  float min = (float)actual_area->travel_length / (float)GARBAGE_TRUCK_MAX_SPEED;
  float max = (float)actual_area->travel_length / (float)GARBAGE_TRUCK_MIN_SPEED;

  Uniform(min, max);
  // vylozeni trva 4-5 minut.
  Uniform(4,5);
  this->load = 0;
  if (DEBUG){
    std::cout << "Garbage truck: " << this->name << ", Dokoncil vylozeni." << "\n";
  }
  /*switch (actual_area->id) {
    case id_nova_borovina:
    to_dump = 
    break;
    case id_stara_borovina:
    break;
    case id_vnitrni_mesto:
    break;
    case id_horka_domky:
    break;
    case id_nove_mesto:
    break;
    case id_kopce:
    break;
    case id_hajek:
    break;
    case id_tyn:
    break;
  }*/
}

void Garbage_truck::Behavior(){
  Area *actual_area = NULL;
  t_id_area old_area = id_depo;

  actual_area = get_area_allowed();
  // Jezdi dokud neni vse odvezeno.
  while (NULL != actual_area){
    // Odjizdi do zadane oblasti.
    goto_location(old_area, actual_area->id);
    old_area = actual_area->id;

    // Zabere si misto se sbiranym odpadem.
    Place *place_w_bins = this->get_place_w_bins(actual_area);
    while (NULL != place_w_bins){
      // Odjede na misto popelnic.
      goto_place(actual_area);
      // Sbira popelnice.
      empty_the_containers(place_w_bins);
      // Ma dodelane misto nebo nema dost mista pro odpad.
      if ((this->load + 348) > this->capacity){
        // Musi jet do sberneho dvora.
        goto_dump(actual_area);
        old_area = id_depo;
        break;
      }
      place_w_bins = this->get_place_w_bins(actual_area);
    }

    actual_area = get_area_allowed();
  }

  // Odjizdi do depa.
  goto_dump(get_area_by_id(old_area));
}