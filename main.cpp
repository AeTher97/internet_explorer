#include <iostream>
#include "iostream"
#include "values.h"
#include "functions.h"
#include "math.h"


//variables

long long int current_cash = 3000000000;
long long int current_credit = 0;
bool credit_taken = false;
double fcb_price = 50; //for a barrel
double ods_spread = -0.3;//for a barrel
double bio_ethanol_price = 884.4/1000; // for kg
double  fame = 990.4/1000;
long long int current_cdu_feed = 0;

double ethylen_price = 512.00/1000;
double propylen_price = 489.90/1000;
double lpg_price = 413.9/1000;
double virgin_naptha_price = 401.3/1000;
double mixed_aromatics_price = 446.9/1000;
double base_gasoline_price  = 406.9/1000;
double gasoline_price  = 471.9/1000;
double kerosene_price  = 431.6/1000;
double diesel_price  = 466.9/1000;                           //  kg
double base_gas_oil_price  = 403.9/1000;
double  hitting_oil_price  = 372/1000;
double light_fuel_oil_price  = 335.8/1000;
double heavy_fuel_oil_price  = 311.8/1000;
double  bitumen_price  = 357.1/1000;
double coke_price  = 209.3/1000;
double  sulfur_price  = 33.3/1000;
double  h2s_price  = 0/1000;
double  hydrogen_price  = 5000/1000;



//constans

double cdu_step = 1000;

double fcb_ods_ratio[5] = {100,70,50,30,0}; //representing fcb percentage
double intrest_rate = 0.10;
double penalty = 0.3;
long long int minimal_cdu_feed = 6000000000; //kg
long long int maximal_cdu_feed = 10000000000; //kg
double splitter1_step =0.01; //splits light naphta 1 ratio between lnht and virgin naphta
double splitter2_step =0.01; //splits middle+heavy naphta 1 ratio between lnht and virgin naphta
double splitter3_step = 0.01; //splits lago hago lvgo into goht ad heating oil
long int bbu_values[3] = {200,400,600};
long int hds_values[4] = {1750,2300,2900,3800}; //steps for hds building values
long int hds_cost[4] = {570000000,610*1000000,640000000,690000000};
long int bbu_cost[3] = {30000000,50000000,70000000};
long long int fuel_gas_power = 50000000; //in J/kg
long long int natural_gas_power = 50000000; //in J/kg
double fuel_gas_price = 10.5/1000000000; //F$/J
double electricity_price = 87;// F$/MWh
double cooling_water = 97/1000; //F$/m^3
double steam = 12.6/1000000000; //F$/J

double api_gravity_fcb = 31.32;
double api_gravity_ods = 29.95;

//calculations


double  ethylen_petchem = 0/1000000;
double  propylen_petchem = 0/1000000;
double  lpg_petchem = 0/1000000;
double  virgin_naptha_petchem = 0/1000000;
double  mixed_aromatics_petchem = 0/1000000;
double  base_gasoline_petchem  = 0/1000000;
double  gasoline_petchem  = 0/1000000;
double  kerosene_petchem  = 0/1000000;
double  diesel_petchem  = 0/1000000;                           //  kg
double  base_gas_oil_petchem  = 0/1000000;
double  hitting_oil_petchem  = 0/1000000;
double  light_fuel_oil_petchem  = 0/1000000;
double  heavy_fuel_oil_petchem  = 0/1000;
double  bitumen_petchem  = 0/1000;
double  coke_petchem  = 0/1000;
double  sulfur_petchem  = 0/1000;
double  h2s_petchem  = 0/1000;
double  hydrogen_petchem  = 0/1000;

double ethylen_refinery = 0/1000;
double propylen_refinery = 0/1000;
double lpg_refinery = 0/1000;
double  virgin_naptha_refinery = 0/1000;
double mixed_aromatics_refinery = 0/1000;
double base_gasoline_refinery  = 0/1000;
double gasoline_refinery  = 0/1000;
double kerosene_refinery  = 0/1000;
double diesel_refinery  = 0/1000;                           //  kg
double base_gas_oil_refinery  = 0/1000;
double  hitting_oil_refinery  = 0/1000;
double light_fuel_oil_refinery  = 0/1000;
double heavy_fuel_oil_refinery  = 0/1000;
double  bitumen_refinery  = 0/1000;
double coke_refinery  = 0/1000;
double  sulfur_refinery  = 0/1000;
double  h2s_refinery = 0/1000;
double  hydrogen_refinery  = 0/1000;

double ethylene_storage = 0;
double ethylene_total = 0;
double propylene_storage = 0;
double propylene_total = 0;
double lpg_storage = 0;
double lpg_total = 0;
double virgin_naphtha_storage = 0;
double virgin_naphtha_total = 0;
double mixed_aromathics_storage = 0;
double mixed_aromathics_total = 0;
double base_gasoline_storage = 0;
double base_gasoline_total = 0;
double gasoline_storage = 0;
double gasoline_total = 0;
double kerosene_storage = 0;
double kerosene_total = 0;
double diesel_storage = 0;
double diesel_total = 0;
double base_gas_oil_storage = 0;
double base_gas_oil_total = 0;
double heating_oil_storage = 0 ;           //kg
double heating_oil_total = 0;
double light_fuel_oil_storage = 0;
double light_fuel_oil_total = 0;
double heavy_fuel_oil_storage = 0;
double heavy_fuel_oil_total = 0;
double bitumen_storage = 0;
double bitumem_total = 0;
double coke_storage = 0;
double coke_total = 0;
double sulphur_storage = 0;
double sulphur_total = 0;
double h2s_storage = 0;
double h2s_total = 0;
double hydrogen_storage = 0;
double hydrogen_total = 0;

//results

long long int credit_intrest = 0;
long long int total_capex = 0;
long long int total_opex = 0;

double p_fuel_gas =0 ; //kg
double  p_lpg =0 ; //kg
double  p_light_naptha=0 ; //kg
double  p_middle_naptha =0 ; //kg
double  p_heavy_naptha =0 ; //kg
double  p_kerosene =0 ; //kg
double  p_lago=0 ; //kg
double  p_hago=0 ; //kg
double  p_lvgo=0 ; //kg
double  p_hvgo=0 ; //kg
double  p_slop_wax=0 ; //kg
double  p_vac_residue=0 ; //kg
double  p_losses=0 ; //kg
double  p_total=0 ; //kg

double new_array[]= {0.34, 0.99, 5.51, 1.64, 8.88, 7.53, 13.95, 6.18, 9.04, 26.61, 3.0, 15.83, 0.5};
double new_array1[] = {0.38, 1.13, 5.61, 1.56, 8.49, 7.17, 12.84, 5.88, 8.65, 27.26, 3.0, 17.53, 0.5};
double new_array2[] = {0.4,1.22,5.67,1.51,8.24,6.93,12.1,5.68,8.39,27.69,3.0,18.67,0.5};
double new_array3[] = {0.47,1.31,5.73,1.46,7.98,6.68,11.36,5.47,8.12,28.12,3.0,19.80,0.5};
double new_array4[] = {0.52,1.44,5.83,1.38,7.59,6.32,10.25,5.17,7.73,28.77,3.0,21.5,0.5};
long int lnht_products[5];
long int hnht_products[4];
long int isomer_products[4];
long int ccr_products[5];


int main() {
    int i;
    long long int steam=0,power=0,gas=0,water=0,hydrogen=0,catalyst=0;
    double fuels[13];
    double splitter1,splitter2;
    int current_iteration1;
    for(current_iteration1=0;current_iteration1<5;current_iteration1++) {

        for(current_cdu_feed=minimal_cdu_feed;current_cdu_feed<maximal_cdu_feed+1;current_cdu_feed+=cdu_step)
        {
            crude_distillation(&gas, &power, &water, &steam, fuels, current_iteration1,current_cdu_feed,new_array,new_array1,new_array2,new_array3,new_array4);
            for(splitter1=0;splitter1<1.01;splitter1+=splitter1_step)
            {
                lnht(&gas,&power,&water,&hydrogen,&catalyst,floor(splitter1*fuels[2]),lnht_products);
                isomer(&gas,&power,&water,&hydrogen,&catalyst,lnht_products[2],isomer_products);

                for(splitter2=0;splitter2<1.01;splitter2+=splitter2_step)
                {
                    hnht(&gas,&power,&water,&hydrogen,&catalyst,floor(splitter2*(fuels[3]+fuels[4])),hnht_products);
                    ccr(&gas,&power,&water,&catalyst,floor(hnht_products[1]),ccr_products);
                    for(i=0;i<4;i++)
                        std::cout << ccr_products[i]<<std::endl;
                    std::cout <<std::endl;

                }

            }


        }
    }






}
