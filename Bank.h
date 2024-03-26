#ifndef BANK_H
#define BANK_
#include <queue>
#include<vector>
#include <climits>
#include"Teller.h"
#include"Customer.h"
#include "CompareCustomer.h"
#include<iostream>

class Bank
{
   int const static numTeller=3;
    Teller tellers[numTeller];
    std::priority_queue <Customer, std::vector<Customer>,CompareCustomer> customerQueue;
    int totalCustomer=0;
    double totalWaitingTime=0;
    double totalServiceTime=0;
    int minServingTeller;

    public:

        Bank() {

          minServingTeller=0;

        }
        void addCustomer(int id, int arrivalTime, int serviceTime){
            Customer customer(id,arrivalTime, serviceTime);
            customerQueue.push(customer);
            totalCustomer++;

        }

        void simulateBank(){
            while(!customerQueue.empty()){
                Customer nextCustomer= customerQueue.top();
                customerQueue.pop();

                int availableTellerIndex=-1;
                for(int i=0;i<numTeller;i++){

                    if(tellers[i].getIsAvailble()){
                        availableTellerIndex=i;
                        break;
                    }
                }

                if(availableTellerIndex!=-1){

                    nextCustomer.setWaitingTime(0);
                    tellers[availableTellerIndex].servedCustomer(nextCustomer,minServingTeller);
                    tellers[availableTellerIndex].setServingTime(nextCustomer.getLivingTime());
                   totalWaitingTime+= nextCustomer.getWaitingTime();


                }else{

                    int minServingTime= INT_MAX;

                    for(int i=0;i<numTeller;i++){
                        if(tellers[i].getSrvingTime()<minServingTime){
                            minServingTime=tellers[i].getSrvingTime();
                            minServingTeller=i;


                        }
                    }

                 nextCustomer.setWaitingTime(minServingTime - nextCustomer.getArrivalTime());
                 tellers[minServingTeller].servedCustomer(nextCustomer,minServingTeller);
                tellers[minServingTeller].setServingTime(nextCustomer.getLivingTime());
                 totalWaitingTime+= nextCustomer.getWaitingTime();


                }
                totalServiceTime+= nextCustomer.getServiceTime();
                minServingTeller++;

        }
     }


     double getAvargeWaitingTime(){
       return  totalWaitingTime/totalCustomer;

     }

     double getAvargeServiceTime(){
       return  totalServiceTime/totalCustomer;

     }


     double getUtilizationRate(int tellerIndex){
    return (static_cast<double>(tellers[tellerIndex].getTotalServedCustomer()) / totalCustomer) * 100.0;
}


};

#endif // BANK_H
