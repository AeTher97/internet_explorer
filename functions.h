//
// Created by Sony on 07.11.2017.
//

#ifndef FRESHH_FUNCTIONS_H
#define FRESHH_FUNCTIONS_H

#include "math.h"


void crude_distillation(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount, long long int *steam_energy,double * products,int value,long long int current_cdu_feed,
                        double* new_array, double*new_array1, double*new_array2, double*new_array3, double * new_array4);

void lnht(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int lnht_feed,long int *lnht_products);

void hnht(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int hnht_feed,long int *hnht_products);

void isomer(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int isomer_feed,long int * isomer_products);

void ccr(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *catalyst,long long int ccr_feed,long int * ccr_products);

void goht(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int goht_feed,long int * goht_products);

long long int kilograms_to_barrels(long long int crude_in_kilograms, double api);


#endif //FRESHH_FUNCTIONS_H
