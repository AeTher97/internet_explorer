#include <iostream>

#include "iostream"
#include "values.h"
#include "functions.h"
#include "math.h"
#include "stdlib.h"


//variables

long long int current_cash = 3000000000;
long long int minumum_cash = -3000000000;
long long int current_credit = 0;
bool credit_taken = false;
double fcb_price = 50; //for a barrel
double ods_spread = -0.3;//for a barrel
double bio_ethanol_price = 884.4/1000; // for kg
double  fame = 990.4/1000;
long long int current_cdu_feed = 0;
double best_splitter1=0;
double best_splitter2=0;
double best_splitter3=0;
double best_fcb_ods_ratio=0;
double best_cdu_feed=0;


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
double  heating_oil_price  = 372/1000;
double light_fuel_oil_price  = 335.8/1000;
double heavy_fuel_oil_price  = 311.8/1000;
double  bitumen_price  = 357.1/1000;
double coke_price  = 209.3/1000;
double  sulfur_price  = 33.3/1000;
double  h2s_price  = 0/1000;
double  hydrogen_price  = 5000/1000;



//constans

double cdu_step = 10000000;

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
double cooling_water_price = 97/1000; //F$/m^3
double steam_price = 12.6/1000000000; //F$/J

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
double  heating_oil_refinery  = 0/1000;
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
long int lnht_products[5]={0};
long int hnht_products[4]={0};
long int isomer_products[4]={0};
long int ccr_products[5]={0};
long int goht_products[6]={0};


int main() {
    int i;
    long long int steam=0,power=0,gas=0,water=0,hydrogen=0,catalyst=0,gas_cost=0,hydrogen_cost=0,steam_cost =0,power_cost=0,water_cost=0,total_utility_cost=0;
    double ods_barrles =0,fcb_barrels=0,ods_cost=0,fcb_cost=0,total_crude_oil_cost=0;
    double lpg_revenue = 0,virgin_naptha_revenue = 0,kerosene_revenue = 0,base_gasoline_revenue = 0,heating_oil_revenue=0,light_fuel_oil_revenue=0,heavy_fuel_oil_revenue=0;
    double base_gas_oil_revenue=0,splitter1_virgin_naphta=0,splitter2_virgin_naphta=0,profit =0,expenditures=0,final_balance=0;
    double fuels[13];
    double splitter1,splitter2,splitter3;
    int current_iteration1;
    for(current_iteration1=0;current_iteration1<1;current_iteration1++) {

        for(current_cdu_feed=8000000000;current_cdu_feed<8200000000;current_cdu_feed+=cdu_step)
        {

                std::cout << current_cdu_feed << std::endl;



            crude_distillation(&gas, &power, &water, &steam, fuels, current_iteration1,current_cdu_feed,new_array,new_array1,new_array2,new_array3,new_array4);
            fcb_barrels = kilograms_to_barrels(fcb_ods_ratio[current_iteration1]/100*current_cdu_feed,api_gravity_fcb);
            ods_barrles = kilograms_to_barrels((1-(fcb_ods_ratio[current_iteration1]/100))*current_cdu_feed,api_gravity_ods);
            fcb_cost = fcb_barrels * fcb_price;
            ods_cost = ods_barrles * (fcb_price+ods_spread);
            total_crude_oil_cost = fcb_cost + ods_cost;

            kerosene_refinery = fuels[5];
            kerosene_revenue = kerosene_refinery*kerosene_price;

            light_fuel_oil_refinery = fuels[9];
            light_fuel_oil_revenue = light_fuel_oil_refinery*light_fuel_oil_price;

            heavy_fuel_oil_refinery = fuels[10]+fuels[11];
            heavy_fuel_oil_revenue = heavy_fuel_oil_refinery*heavy_fuel_oil_price;

           for(splitter1=0.00;splitter1<0.02;splitter1+=splitter1_step)
            {
                lnht(&gas,&power,&water,&hydrogen,&catalyst,floor(splitter1*fuels[2]),lnht_products);
                isomer(&gas,&power,&water,&hydrogen,&catalyst,lnht_products[2],isomer_products);

                splitter1_virgin_naphta = (1-splitter1)*fuels[2];
                splitter1_virgin_naphta += isomer_products[2];



                for(splitter2=0.63;splitter2<0.66;splitter2+=splitter2_step)
                {

                    hnht(&gas,&power,&water,&hydrogen,&catalyst,floor(splitter2*(fuels[3]+fuels[4])),hnht_products);
                    ccr(&gas,&power,&water,&catalyst,floor(hnht_products[1]),ccr_products);



                    base_gasoline_refinery = isomer_products[1]+ccr_products[2];
                    base_gasoline_revenue = base_gasoline_refinery*base_gasoline_price;

                    for(splitter3=0.98;splitter3<1.01;splitter3+=splitter3_step)
                    {
                        goht(&gas,&power,&water,&hydrogen,&catalyst,floor(splitter3*(fuels[6]+fuels[7]+fuels[8])),goht_products);
                        splitter2_virgin_naphta = (1-splitter2)*(fuels[3]+fuels[4]);
                        splitter2_virgin_naphta+=goht_products[2];

                        lpg_refinery = fuels[1]+lnht_products[1]+ccr_products[1]+goht_products[1];
                        lpg_revenue = lpg_refinery * lpg_price;

                        virgin_naptha_refinery = splitter1_virgin_naphta+splitter2_virgin_naphta;
                        virgin_naptha_revenue = virgin_naptha_refinery*virgin_naptha_price;

                        heating_oil_refinery = (1-splitter3)*(fuels[6]+fuels[7]+fuels[8]);
                        heating_oil_revenue = heating_oil_refinery*heating_oil_price;

                        base_gas_oil_refinery = goht_products[3];
                        base_gas_oil_revenue = base_gas_oil_refinery*base_gas_oil_price;

                        if((hydrogen-ccr_products[3])>0)
                            hydrogen_cost =  floor((hydrogen-ccr_products[3])*hydrogen_price);
                        else
                            hydrogen_cost = 0;
                        if((gas-fuel_gas_power*(fuels[0]+lnht_products[0]+hnht_products[0]+isomer_products[0]+ccr_products[0]+goht_products[0]))>0)
                            gas_cost=floor((gas-fuel_gas_power*(fuels[0]+lnht_products[0]+hnht_products[0]+isomer_products[0]+ccr_products[0]+goht_products[0]))*fuel_gas_price);
                        else
                            gas_cost=0;
                        power_cost =floor(power*electricity_price);
                        water_cost=floor(water*cooling_water_price);
                        if(steam>0)
                            steam_cost = floor(steam*steam_price);
                        else
                            steam_cost = 0;

                        total_utility_cost = hydrogen_cost+steam_cost+water_cost+power_cost+catalyst+gas_cost;

                        profit = lpg_revenue + kerosene_revenue + virgin_naptha_revenue + light_fuel_oil_revenue + heavy_fuel_oil_revenue + heating_oil_revenue +base_gasoline_revenue + base_gas_oil_revenue;
                        expenditures = total_utility_cost + total_crude_oil_cost;
                        final_balance = profit  - expenditures;
                        if( final_balance > minumum_cash)
                        {
                            minumum_cash = final_balance;
                            best_splitter1 = splitter1;
                            best_splitter2 = splitter2;
                            best_splitter3 = splitter3;
                            best_fcb_ods_ratio = current_iteration1;
                            best_cdu_feed = current_cdu_feed;


                        }
                        hydrogen=0;
                        power =0;
                        gas=0;
                        water =0;
                        steam =0;
                        catalyst=0;


                    }

                }

            }


        }
    }



    std::cout << best_splitter1 <<std::endl;
    std::cout << best_splitter2 <<std::endl;
    std::cout << best_splitter3 <<std::endl;
    std::cout << best_fcb_ods_ratio <<std::endl;
    std::cout << best_cdu_feed <<std::endl;
    std::cout << minumum_cash << std::endl;


}
