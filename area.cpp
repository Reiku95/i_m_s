#include "area.h"

Area::Area(std::string name, int travel_length, float surface, int priority, id_area id) {
    this->name = name;
    this->travel_length = travel_length;
    this->surface = surface;
    this->priority = priority;

    this->id = id;

    this->places.clear();
}

Place *Area::get_place_w_bins(t_type_container type) {
    int i;
    for (i = 0; i < places.size(); i++) {
        if (type_paper == type) {
            if (0 != places[i]->bins_paper_240l || 0 != places[i]->bins_paper_1100l) {
                return places[i];
            }
        } else if (type_plastic == type) {
            if (0 != places[i]->bins_plastic_240l || 0 != places[i]->bins_plastic_1100l) {
                return places[i];
            }
        } else if (type_glassc == type) {
            if (0 != places[i]->bins_glassc_240l || 0 != places[i]->bins_glassc_1100l) {
                return places[i];
            }
        } else if (type_glassw == type) {
            if (0 != places[i]->bins_glassw_240l || 0 != places[i]->bins_glassw_1100l) {
                return places[i];
            }
        } else if (type_bio == type) {
            if (0 != places[i]->bins_bio_240l) {
                return places[i];
            }
        }
    }
    return NULL;
}

void Area::create_places(int bins_places, int bins_paper_240l, int bins_paper_1100l, int bins_plastic_240l, int bins_plastic_1100l,
                         int bins_glassc_240l, int bins_glassc_1100l, int bins_glassw_240l, int bins_glassw_1100l, int bins_bio_240l) {
    // Rozdeli vsechny kontejnery mezi mista.
    places.clear();
    int i;
    for (i = 0; i < bins_places; i++) {
        Place *place;
        place = new Place();
        places.push_back(place);
    }

    int i_1 = 0;;
    for (i = 0; i < bins_paper_240l; i++) {
        places[i_1]->set_bins_paper_240l(places[i_1]->bins_paper_240l + 1);
        i_1++;
        if (bins_places == i_1) {
            i_1 = 0;
        }
    }

    for (i = 0; i < bins_paper_1100l; i++) {

        places[i_1]->set_bins_paper_1100l(places[i_1]->bins_paper_1100l + 1);
        i_1++;
        if (bins_places == i_1) {
            i_1 = 0;
        }
    }

    for (i = 0; i < bins_plastic_240l; i++) {
        places[i_1]->set_bins_plastic_240l(places[i_1]->bins_plastic_240l + 1);
        i_1++;
        if (bins_places == i_1) {
            i_1 = 0;
        }
    }

    for (i = 0; i < bins_plastic_1100l; i++) {
        places[i_1]->set_bins_plastic_1100l(places[i_1]->bins_plastic_1100l + 1);
        i_1++;
        if (bins_places == i_1) {
            i_1 = 0;
        }
    }

    for (i = 0; i < bins_glassc_240l; i++) {
        places[i_1]->set_bins_glassc_240l(places[i_1]->bins_glassc_240l + 1);
        i_1++;
        if (bins_places == i_1) {
            i_1 = 0;
        }
    }

    for (i = 0; i < bins_glassc_1100l; i++) {
        places[i_1]->set_bins_glassc_1100l(places[i_1]->bins_glassc_1100l + 1);
        i_1++;
        if (bins_places == i_1) {
            i_1 = 0;
        }
    }

    for (i = 0; i < bins_glassw_240l; i++) {
        places[i_1]->set_bins_glassw_240l(places[i_1]->bins_glassw_240l + 1);
        i_1++;
        if (bins_places == i_1) {
            i_1 = 0;
        }
    }

    for (i = 0; i < bins_glassw_1100l; i++) {
        places[i_1]->set_bins_glassw_1100l(places[i_1]->bins_glassw_1100l + 1);
        i_1++;
        if (bins_places == i_1) {
            i_1 = 0;
        }
    }

    for (i = 0; i < bins_bio_240l; i++) {
        places[i_1]->set_bins_bio_240l(places[i_1]->bins_bio_240l + 1);
        i_1++;
        if (bins_places == i_1) {
            i_1 = 0;
        }
    }
}

Area::~Area() {
    //dtor
}
