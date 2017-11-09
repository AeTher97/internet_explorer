//
// Created by Sony on 07.11.2017.
//

#ifndef FRESHH_FUNCTIONS_H
#define FRESHH_FUNCTIONS_H

#include "math.h"


double fcc_SPG = 0.75;
double fcc_RON = 93.5;
double fcc_MON = 82.5;
double fcc_RVP = 56;
double fcc_Olefin = 0.27;
double fcc_Aromatics = 0.26;

double reformatre_SPG = 0.83;
double reformatre_RON = 103;
double reformatre_MON = 92;
double reformatre_RVP = 30;
double reformatre_Olefin = 0;
double reformatre_Aromatics = 0.81;

double isomerate_SPG = 0.68;
double isomerate_RON = 90;
double isomerate_MON = 85;
double isomerate_RVP = 80;
double isomerate_Olefin = 0.01;
double isomerate_Aromatics = 0;


//Diesel Blending constans


double fcc_loco_spg = 0.925;
double fcc_loco_polyaromathic = 0.25;

double goht_gas_oil_spg = 0.835;
double goht_gas_oil_polyaromathic = 0.02;

double hds_gas_oil_spg = 0.858;
double hds_gas_oil_polyaromathic = 0.053;


void crude_distillation(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount, long long int *steam_energy,double * products,int value,long long int current_cdu_feed,
                        double* new_array, double*new_array1, double*new_array2, double*new_array3, double * new_array4);

void lnht(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int lnht_feed,long int *lnht_products);

void hnht(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int hnht_feed,long int *hnht_products);

void isomer(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int isomer_feed,long int * isomer_products);

void ccr(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *catalyst,long long int ccr_feed,long int * ccr_products);

void goht(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int goht_feed,long int * goht_products);

void hds(long long int * fuel_gas_energy,long long int * electricy_amount,long long int * cooling_water_amount, long long int * hydrogen,long long int *steam,long long int hds_feed,long int * hds_products,int mhchds);

void fcc(long long int * fuel_gas_energy,long long int * electricity_amount,long long int * cooling_water_amount,long long int *catalyst,long long int * steam,long long int fcc_feed,long int * fcc_products,int fcc_mode);

void bbu(long long int * fuel_gas_energy,long long int * electricity_amount,long long int * cooling_water_amount,long long int * steam,long long int bbu_feed,long int * bbu_products);

bool isGasolineBlended(double fcc_gasoline_feed, double reformate_feed, double isomerate_feed);
bool isDieselBlended(double fcc_LCO_feed, double goht_gas_oil_feed, double hds_oil_feed);
bool isBlendedAsHeatingOil(double fcc_LCO_feed, double goht_gas_oil_feed, double hds_oil_feed);

long long int kilograms_to_barrels(long long int crude_in_kilograms, double api);


#endif //FRESHH_FUNCTIONS_H
