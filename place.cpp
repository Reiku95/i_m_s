#include "place.h"

Place::Place() {
    this->bins_paper_240l = 0;
    this->total_bins_paper_240l = 0;
    this->bins_paper_1100l = 0;
    this->total_bins_paper_1100l = 0;

    this->bins_plastic_240l = 0;
    this->total_bins_plastic_240l = 0;

    this->bins_plastic_1100l = 0;
    this->total_bins_plastic_1100l = 0;

    this->bins_glassc_240l = 0;
    this->total_bins_glassc_240l = 0;

    this->bins_glassc_1100l = 0;
    this->total_bins_glassc_1100l = 0;

    this->bins_glassw_240l = 0;
    this->total_bins_glassw_240l = 0;

    this->bins_glassw_1100l = 0;
    this->total_bins_glassw_1100l = 0;

    this->bins_bio_240l = 0;
    this->total_bins_bio_240l = 0;

    this->finished = false;
}

void Place::set_bins_paper_240l(int num) {
    this->bins_paper_240l = num;
    this->total_bins_paper_240l = num;
}

void Place::set_bins_paper_1100l(int num) {
    this->bins_paper_1100l = num;
    this->total_bins_paper_1100l = num;
}

void Place::set_bins_plastic_240l(int num) {
    this->bins_plastic_240l = num;
    this->total_bins_plastic_240l = num;
}

void Place::set_bins_plastic_1100l(int num) {
    this->bins_plastic_1100l = num;
    this->total_bins_plastic_1100l = num;
}

void Place::set_bins_glassc_240l(int num) {
    this->bins_glassc_240l = num;
    this->total_bins_glassc_240l = num;
}

void Place::set_bins_glassc_1100l(int num) {
    this->bins_glassc_1100l = num;
    this->total_bins_glassc_1100l = num;
}

void Place::set_bins_glassw_240l(int num) {
    this->bins_glassw_240l = num;
    this->total_bins_glassw_240l = num;
}

void Place::set_bins_glassw_1100l(int num) {
    this->bins_glassw_1100l = num;
    this->total_bins_glassw_1100l = num;
}

void Place::set_bins_bio_240l(int num) {
    this->bins_bio_240l = num;
    this->total_bins_bio_240l = num;
}

Place::~Place() {
    //dtor
}
