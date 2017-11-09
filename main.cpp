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
double fcb_price = 55; //for a barrel
double ods_spread = -0.2;//for a barrel
double bio_ethanol_price = 884.4/1000; // for kg
double  fame = 990.4/1000;
long long int current_cdu_feed = 0;
double best_splitter1=0;
double best_splitter2=0;
double best_splitter3=0;
double best_splitter4=0;
double best_splitter5=0;
double best_splitter6=0;
double best_splitter7=0;
double best_splitter8=0;
double best_splitter9=0;
double best_splitter10=0;
double best_splitter11=0;
double best_splitter12=0;
double best_fcb_ods_ratio=0;
double best_cdu_feed=0;

double cdu_step = 10000000;
double splitter1_step =0.1; //splits light naphta 1 ratio between lnht and virgin naphta
double splitter2_step =0.1; //splits middle+heavy naphta 1 ratio between lnht and virgin naphta
double splitter3_step = 0.1; //splits lago hago lvgo into goht ad heating oil
double splitter4_step = 0.1;
double splitter5_step = 0.1;
double splitter6_step = 0.1;
double splitter7_step = 0.1;
double splitter8_step = 0.1;
double splitter9_step = 0.1;
double splitter10_step = 0.1;
double splitter11_step = 0.1;
double splitter12_step = 0.1;



double ethylen_price = 553.20/1000;
double propylen_price = 528.20/1000;
double lpg_price = 451.2/1000;
double virgin_naptha_price = 429.9/1000;
double mixed_aromatics_price = 480.1/1000;
double base_gasoline_price  = 443.2/1000;
double gasoline_price  = 508.2/1000;
double kerosene_price  = 468.1/1000;
double diesel_price  = 506.1/1000;                           //  kg
double base_gas_oil_price  = 441.2/1000;
double  heating_oil_price  = 408.8/1000;
double light_fuel_oil_price  = 372.2/1000;
double heavy_fuel_oil_price  = 347.3/1000;
double  bitumen_price  = 393.3/1000;
double coke_price  = 201.6/1000;
double  sulfur_price  = 29.5/1000;
double  h2s_price  = 0/1000;
double  hydrogen_price  = 5000/1000;



//constans



double fcb_ods_ratio[5] = {100,70,50,30,0}; //representing fcb percentage
double intrest_rate = 0.10;
double penalty = 0.3;
long long int minimal_cdu_feed = 6000000000; //kg
long long int maximal_cdu_feed = 10000000000; //kg
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

double best_lpg_refinery;
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
long int hds_products[6]={0};
long int bbu_products[1]={0};
long int fcc_products[7]={0};


double best_profit;
double best_expenditures;
double best_oil_cost;


int main() {
    int i,fcc_tick,hds_tick;
    long long int steam = 0, power = 0, gas = 0, water = 0, hydrogen = 0, catalyst = 0;
    long long int input_steam = 0, input_power = 0, input_gas = 0, input_water = 0;
    long long int lnht_power = 0, lnht_gas = 0, lnht_water = 0, lnht_hydrogen = 0, lnht_catalyst = 0;
    long long int hnht_power = 0, hnht_gas = 0, hnht_water = 0, hnht_hydrogen = 0, hnht_catalyst = 0;
    long long int hds_power = 0, hds_gas = 0, hds_water = 0, hds_hydrogen = 0, hds_catalyst = 0 , hds_steam =0;
    long long int bbu_power = 0, bbu_gas = 0, bbu_water = 0, bbu_hydrogen = 0, bbu_catalyst = 0, bbu_steam=0;
    long long int fcc_power = 0, fcc_gas = 0, fcc_water = 0, fcc_hydrogen = 0, fcc_catalyst = 0,fcc_steam=0;
    long long int lni_power = 0, lni_gas = 0, lni_water = 0, lni_hydrogen = 0, lni_catalyst = 0;
    long long int ccr_power = 0, ccr_gas = 0, ccr_water = 0, ccr_catalyst = 0;
    long long int goht_power = 0, goht_gas = 0, goht_water = 0, goht_hydrogen = 0, goht_catalyst = 0;
    double gas_cost = 0, hydrogen_cost = 0, steam_cost = 0, power_cost = 0, water_cost = 0, total_utility_cost = 0;
    double ods_barrles = 0, fcb_barrels = 0, ods_cost = 0, fcb_cost = 0, total_crude_oil_cost = 0;
    double lpg_revenue = 0, virgin_naptha_revenue = 0, kerosene_revenue = 0, base_gasoline_revenue = 0, heating_oil_revenue = 0, light_fuel_oil_revenue = 0, heavy_fuel_oil_revenue = 0;
    double base_gas_oil_revenue = 0, splitter1_virgin_naphta = 0, splitter2_virgin_naphta = 0, profit = 0, expenditures = 0, final_balance = 0;
    double fuels[13];
    double splitter1, splitter2, splitter3, splitter4, splitter5, splitter6, splitter7, splitter8, splitter9, splitter10, splitter11, splitter12;
    int current_iteration1;


    for (current_iteration1 = 0; current_iteration1 < 5; current_iteration1++) {

        for (current_cdu_feed = minimal_cdu_feed; current_cdu_feed < maximal_cdu_feed; current_cdu_feed += cdu_step) {

            // std::cout << final_balance <<std::endl;



            crude_distillation(&input_gas, &input_power, &input_water, &input_steam, fuels, current_iteration1,
                               current_cdu_feed, new_array, new_array1, new_array2, new_array3, new_array4);


            fcb_barrels = kilograms_to_barrels(fcb_ods_ratio[current_iteration1] / 100 * current_cdu_feed,
                                               api_gravity_fcb);
            ods_barrles = kilograms_to_barrels((1 - (fcb_ods_ratio[current_iteration1] / 100)) * current_cdu_feed,
                                               api_gravity_ods);

            fcb_cost = fcb_barrels * fcb_price;
            ods_cost = ods_barrles * (fcb_price + ods_spread);
            total_crude_oil_cost = fcb_cost + ods_cost;

            kerosene_refinery = fuels[5];
            kerosene_revenue = kerosene_refinery * kerosene_price;

            light_fuel_oil_refinery = fuels[9];
            light_fuel_oil_revenue = light_fuel_oil_refinery * light_fuel_oil_price;

            heavy_fuel_oil_refinery = fuels[10] + fuels[11];
            heavy_fuel_oil_revenue = heavy_fuel_oil_refinery * heavy_fuel_oil_price;

            for (splitter1 = 0.0; splitter1 < 1.01; splitter1 += splitter1_step) {
                lnht(&lnht_gas, &lnht_power, &lnht_water, &lnht_hydrogen, &lnht_catalyst, floor(splitter1 * fuels[2]),
                     lnht_products);
                isomer(&lni_gas, &lni_power, &lni_water, &lni_hydrogen, &lni_catalyst, lnht_products[2],
                       isomer_products);

                splitter1_virgin_naphta = (1 - splitter1) * fuels[2];
                splitter1_virgin_naphta += isomer_products[2];


                for (splitter2 = 0.0; splitter2 < 1.01; splitter2 += splitter2_step) {

                    hnht(&hnht_gas, &hnht_power, &hnht_water, &hnht_hydrogen, &hnht_catalyst,
                         floor(splitter2 * (fuels[3] + fuels[4])), hnht_products);
                    ccr(&ccr_gas, &ccr_power, &ccr_water, &ccr_catalyst, floor(hnht_products[1]), ccr_products);



//TO DO

                    for (splitter3 = 0.0; splitter3 < 1.01; splitter3 += splitter3_step) {
                        goht(&goht_gas, &goht_power, &goht_water, &goht_hydrogen,
                             &goht_catalyst,
                             floor(splitter3 * (fuels[6] + fuels[7] + fuels[8])),
                             goht_products);
                        for (splitter4 = 0.00; splitter4 < 1.01; splitter4 += splitter4_step) {

                            for (splitter5 = 0.00; splitter5 < 1.01; splitter5 += splitter5_step) {

                                for (splitter6 = 0.00; splitter6 < 1.01; splitter6 += splitter6_step) {
                                    for (splitter7 = 0.00; splitter7 < 1.01; splitter7 += splitter7_step) {
                                        hds(&hds_gas, &hds_power, &hds_water, &hds_hydrogen,
                                             &hds_steam,fuels[9]*splitter6,hds_products,hds_tick);

                                        for (splitter8 = 0.00; splitter8 < 1.01; splitter8 += splitter8_step) {
                                            for (splitter9 = 0.00; splitter9 < 1.01; splitter9 += splitter9_step) {
                                                for (splitter10 = 0.00;
                                                     splitter10 < 1.01; splitter10 += splitter10_step) {
                                                    fcc(&fcc_gas, &fcc_power, &fcc_water, &fcc_catalyst,
                                                        &fcc_steam,hds_products[4]*splitter10,fcc_products,fcc_tick);
                                                    for (splitter11 = 0.00;
                                                         splitter11 < 1.01; splitter11 += splitter11_step) {
                                                        base_gasoline_refinery = isomer_products[1]*(1-splitter4)+ccr_products[2]*(1-splitter5)+fcc_products[3]*(1-splitter10);
                                                        base_gasoline_revenue = base_gasoline_refinery * base_gasoline_price;
                                                        for (splitter12 = 0.00;
                                                             splitter12 < 1.01; splitter12 += splitter12_step) {
                                                            bbu(&bbu_gas, &bbu_power, &bbu_water,
                                                                &bbu_steam,splitter12*(fuels[10]+fuels[11]),bbu_products);

                                                            splitter2_virgin_naphta =
                                                                    (1 - splitter2) * (fuels[3] + fuels[4]);
                                                            splitter2_virgin_naphta += goht_products[2];

                                                            lpg_refinery =
                                                                    fuels[1] + lnht_products[1] + ccr_products[1] +
                                                                    goht_products[1]+hds_products[1]+fcc_products[1];
                                                            lpg_revenue = lpg_refinery * lpg_price;

                                                            virgin_naptha_refinery =
                                                                    splitter1_virgin_naphta + splitter2_virgin_naphta+isomer_products[2]*(1-splitter4)
                                                                    +(1-splitter5)*goht_products[2]+hds_products[2];
                                                            virgin_naptha_revenue =
                                                                    virgin_naptha_refinery * virgin_naptha_price;

                                                            heating_oil_refinery =
                                                                    (1 - splitter3) * (fuels[6] + fuels[7] + fuels[8])+fcc_products[4]*(1-splitter11);
                                                            heating_oil_revenue =
                                                                    heating_oil_refinery * heating_oil_price;

                                                            base_gas_oil_refinery = goht_products[3] * (1 - splitter6);
                                                            base_gas_oil_revenue =
                                                                    base_gas_oil_refinery * base_gas_oil_price;


                                                            steam = input_steam;
                                                            hydrogen = lnht_hydrogen + hnht_hydrogen + goht_hydrogen +
                                                                       lni_hydrogen;
                                                            water = input_water + lnht_water + hnht_water + lni_water +
                                                                    ccr_water + goht_water;
                                                            gas = input_gas + lnht_gas + hnht_gas + lni_gas + ccr_gas +
                                                                  goht_gas;
                                                            power = input_power + lnht_power + hnht_power + lni_power +
                                                                    ccr_power + goht_power;
                                                            catalyst = lnht_catalyst + ccr_catalyst + goht_catalyst +
                                                                       hnht_catalyst + lni_catalyst;

                                                            if ((hydrogen - ccr_products[3]) > 0)
                                                                hydrogen_cost = floor(
                                                                        (hydrogen - ccr_products[3]) * hydrogen_price);
                                                            else
                                                                hydrogen_cost = 0;
                                                            if ((gas - fuel_gas_power *
                                                                       (fuels[0] + lnht_products[0] + hnht_products[0] +
                                                                        isomer_products[0] +
                                                                        ccr_products[0] + goht_products[0])) > 0)
                                                                gas_cost = floor((gas - fuel_gas_power *
                                                                                        (fuels[0] + lnht_products[0] +
                                                                                         hnht_products[0] +
                                                                                         isomer_products[0] +
                                                                                         ccr_products[0] +
                                                                                         goht_products[0])) *
                                                                                 fuel_gas_price);
                                                            else
                                                                gas_cost = 0;
                                                            power_cost = power * electricity_price;
                                                            water_cost = water * cooling_water_price;

                                                            if (steam > 0)
                                                                steam_cost = steam * steam_price;
                                                            else
                                                                steam_cost = 0;


                                                            total_utility_cost =
                                                                    hydrogen_cost + steam_cost + water_cost +
                                                                    power_cost + catalyst + gas_cost;


                                                            profit = lpg_revenue + kerosene_revenue +
                                                                     virgin_naptha_revenue + light_fuel_oil_revenue +
                                                                     heavy_fuel_oil_revenue + heating_oil_revenue +
                                                                     base_gasoline_revenue +
                                                                     base_gas_oil_revenue;

                                                            expenditures = total_utility_cost + total_crude_oil_cost;

                                                            /*
                                                                    if (current_iteration1 ==0 && splitter1 == 0 &&splitter2 == 0.7 && splitter3>0.9 &&current_cdu_feed == 6000000000 )
                                                                                   {
                                                                                      std::cout << std::endl << std::endl<< profit << std::endl;
                                                                                       std::cout << total_utility_cost << std::endl;
                                                                                       std::cout << total_crude_oil_cost << std::endl;
                                                                                       std::cout << splitter3;
                                                                                        std::cout << lpg_refinery<<std::endl;
                                                    std::cout << virgin_naptha_refinery<<std::endl;
                                                     std::cout << kerosene_refinery<<std::endl;

                                                            }
                                                    */
                                                            final_balance = profit - expenditures;
                                                            if (final_balance > minumum_cash) {

                                                                minumum_cash = floor(final_balance);
                                                                best_splitter1 = splitter1;
                                                                best_splitter2 = splitter2;
                                                                best_splitter3 = splitter3;
                                                                best_fcb_ods_ratio = current_iteration1;
                                                                best_cdu_feed = current_cdu_feed;
                                                                best_profit = profit;
                                                                best_expenditures = total_utility_cost;
                                                                best_oil_cost = total_crude_oil_cost;


                                                            }


                                                            hydrogen_cost = 0;
                                                            water_cost = 0;
                                                            power_cost = 0;
                                                            gas_cost = 0;
                                                            steam_cost = 0;
                                                            hydrogen = 0;
                                                            power = 0;
                                                            gas = 0;
                                                            water = 0;
                                                            steam = 0;
                                                            catalyst = 0;

                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                }

            }


        }
    }


    std::cout << std::endl;


    std::cout << std::endl << best_profit << std::endl;
    std::cout << best_expenditures << std::endl;
    std::cout << best_oil_cost << std::endl << std::endl;

    std::cout << best_splitter1 << std::endl;
    std::cout << best_splitter2 << std::endl;
    std::cout << best_splitter3 << std::endl;
    std::cout << best_fcb_ods_ratio << std::endl;
    std::cout << best_cdu_feed << std::endl;
    std::cout << minumum_cash << std::endl;


}
