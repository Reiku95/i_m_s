#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <vector>
#include <string>

#include "simlib.h"
#include "place.h"

class Area {
  public:
    std::string name;
    // Delka cesty z centraly.
    int travel_length;
    // Plocha uzemi.
    float surface;
    // Pocet popelnic.
    std::vector<Place *> places;

    Area(std::string name, int travel_length, float surface);
    void create_places(int bins_places, int bins_paper_240l, int bins_paper_1100l, int bins_plastic_240l, int bins_plastic_1100l,
      int bins_glassc_240l, int bins_glassc_1100l, int bins_glassw_240l, int bins_glassw_1100l, int bins_bio_240l);

  protected:

  private:
};

#endif // AREA_H