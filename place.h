#ifndef PLACE_H
#define PLACE_H

#include <iostream>
#include <vector>
#include <string>

#include "simlib.h"

class Place : public Facility {
public:
    bool finished;

    // Pocet popelnic.
    int bins_paper_240l;
    int bins_paper_1100l;
    int bins_plastic_240l;
    int bins_plastic_1100l;
    int bins_glassc_240l;
    int bins_glassc_1100l;
    int bins_glassw_240l;
    int bins_glassw_1100l;
    int bins_bio_240l;

    int total_bins_paper_240l;
    int total_bins_paper_1100l;
    int total_bins_plastic_240l;
    int total_bins_plastic_1100l;
    int total_bins_glassc_240l;
    int total_bins_glassc_1100l;
    int total_bins_glassw_240l;
    int total_bins_glassw_1100l;
    int total_bins_bio_240l;

    Place();
    virtual ~Place();
    void set_bins_paper_240l(int num);
    void set_bins_paper_1100l(int num);
    void set_bins_plastic_240l(int num);
    void set_bins_plastic_1100l(int num);
    void set_bins_glassc_240l(int num);
    void set_bins_glassc_1100l(int num);
    void set_bins_glassw_240l(int num);
    void set_bins_glassw_1100l(int num);
    void set_bins_bio_240l(int num);

protected:

private:
};

#endif // PLACE_H
