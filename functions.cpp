//
// Created by Sony on 07.11.2017.
//
#include "values.h"
#include "functions.h"
#include "iostream"
#include "math.h"
void crude_distillation(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount, long long int *steam_energy,double * products_array,int current_ratio_number,long long int current_cdu_feed,
                        double* new_array, double*new_array1, double*new_array2, double*new_array3, double * new_array4)
{
    int i;

    for(i=0;i<13;i++)
    switch(current_ratio_number) {
        case 0:

            for(i=0;i<13;i++)
                products_array[i] = new_array[i]/100*current_cdu_feed;
            break;
        case 1:

            for(i=0;i<13;i++)
                products_array[i] = new_array1[i]/100*current_cdu_feed;
            break;
        case 2:

            for(i=0;i<13;i++)
                products_array[i] = new_array2[i]/100*current_cdu_feed;
            break;
        case 3:

            for(i=0;i<13;i++)
                products_array[i] = new_array3[i]/100*current_cdu_feed;
            break;
        case 4:
            for(i=0;i<13;i++)
                products_array[i] = new_array4[i]/100*current_cdu_feed;
            break;
    }



    (*fuel_gas_energy)=ceil(669*1000*current_cdu_feed);
    (*electricity_amount)=ceil(7.3/1000000*current_cdu_feed);
    (*cooling_water_amount)=ceil(3.5/1000*current_cdu_feed);
    (*steam_energy)=ceil(-28*1000*current_cdu_feed);


}

void lnht(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int lnht_feed,long int *lnht_products)
{
    lnht_products[0]=floor(2.12/100*lnht_feed);
    lnht_products[1]=floor(4.0/100*lnht_feed);
    lnht_products[2]=floor(93.88/100*lnht_feed);
    lnht_products[3]=floor(0.01/100*lnht_feed);
    lnht_products[4]=floor(0.19/100*lnht_feed);




    (*hydrogen)=(0.2/100*lnht_feed);
    (*fuel_gas_energy)=ceil(400*1000*lnht_feed);
    (*electricity_amount)=ceil(9/1000000*lnht_feed);
    (*cooling_water_amount)=ceil(12/1000*lnht_feed);
    (*catalyst)=(250/1000000)*lnht_feed;

}

void hnht(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int hnht_feed,long int *hnht_products)
{
    hnht_products[0]=floor(0.44/100*hnht_feed);
    hnht_products[1]=floor(99.56/100*hnht_feed);
    hnht_products[2]=floor(0.1/100*hnht_feed);
    hnht_products[3]=floor(0.2/100*hnht_feed);



    (*hydrogen)=(0.3/100*hnht_feed);
    (*fuel_gas_energy)=ceil(300*1000*hnht_feed);
    (*electricity_amount)=ceil(6/1000000*hnht_feed);
    (*cooling_water_amount)=ceil(8/1000*hnht_feed);
    (*catalyst)=(200/1000000)*hnht_feed;

}

void isomer(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int isomer_feed,long int *isomer_products)
{
    isomer_products[0]=floor(1.6/100*isomer_feed);
    isomer_products[1]=floor(81.36/100*isomer_feed);
    isomer_products[2]=floor(17.94/100*isomer_feed);
    isomer_products[3]=floor(0.1/100*isomer_feed);



    (*hydrogen)=(1/100*isomer_feed);
    (*fuel_gas_energy)=ceil(3000*1000*isomer_feed);
    (*electricity_amount)=ceil(40/1000000*isomer_feed);
    (*cooling_water_amount)=ceil(25/1000*isomer_feed);
    (*catalyst)=(500/1000000)*isomer_feed;
}

void ccr(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *catalyst,long long int ccr_feed,long int * ccr_products)

{
ccr_products[0]=floor(6.26/100*ccr_feed);
ccr_products[1]=floor(4.06/100*ccr_feed);
ccr_products[2]=floor(86.30/100*ccr_feed);
ccr_products[3]=floor(3.28/100*ccr_feed);
ccr_products[4]=floor(0.1/100*ccr_feed);

(*fuel_gas_energy)=ceil(4028*1000*ccr_feed);
(*electricity_amount)=ceil(127.5/1000000*ccr_feed);
(*cooling_water_amount)=ceil(18.8/1000*ccr_feed);
(*catalyst)=(670/1000000)*ccr_feed;
}

void goht(long long int * fuel_gas_energy,long long int * electricity_amount, long long int * cooling_water_amount,long long int *hydrogen,long long int *catalyst,long long int goht_feed,long int * goht_products)
{
    goht_products[0]=floor(0.56/100*goht_feed);
    goht_products[1]=floor(0.77/100*goht_feed);
    goht_products[2]=floor(7.84/100*goht_feed);
    goht_products[3]=floor(90.33/100*goht_feed);
    goht_products[4]=floor(1.05/100*goht_feed);
    goht_products[5]=floor(0.2/100*goht_feed);

    (*hydrogen)=(0.75/100*goht_feed);
    (*fuel_gas_energy)=ceil(290*1000*goht_feed);
    (*electricity_amount)=ceil(17/1000000*goht_feed);
    (*cooling_water_amount)=ceil(5.2/1000*goht_feed);
    (*catalyst)=(200/1000000)*goht_feed;
}

void hds(long long int * fuel_gas_energy,long long int * electricity_amount,long long int * cooling_water_amount, long long int * hydrogen,long long int * steam,long long int hds_feed,long int * hds_products,int mhchds)
{
    if(mhchds == 0) {
        hds_products[0] = floor(0.4 / 100 * hds_feed);
        hds_products[1] = floor(0.2 / 100 * hds_feed);
        hds_products[2] = floor(2.58 / 100 * hds_feed);
        hds_products[3] = floor(13.89 / 100 * hds_feed);
        hds_products[4] = floor(80.75 / 100 * hds_feed);
        hds_products[5] = floor(2.58 / 100 * hds_feed);
    }
    if(mhchds == 1){
        hds_products[0] = floor(0.76 / 100 * hds_feed);
        hds_products[1] = floor(0.25 / 100 * hds_feed);
        hds_products[2] = floor(3.8 / 100 * hds_feed);
        hds_products[3] = floor(21.43 / 100 * hds_feed);
        hds_products[4] = floor(71.78 / 100 * hds_feed);
        hds_products[5] = floor(2.58 / 100 * hds_feed);
    }
    (*hydrogen)=(1.00/100*hds_feed);
    (*fuel_gas_energy)=ceil(280*1000*hds_feed);
    (*electricity_amount)=ceil(36/1000000*hds_feed);
    (*cooling_water_amount)=ceil(5.2/1000*hds_feed);
    (*steam)=ceil(245/1000*hds_feed);


}


long long int kilograms_to_barrels(long long int crude_in_kilograms, double api)
{

    long long int crude_in_barrels = crude_in_kilograms/1000 * 1/(141.5/(api +131.5)*0.159);






    return crude_in_barrels;
}