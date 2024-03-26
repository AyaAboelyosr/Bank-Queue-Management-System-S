#ifndef TELLER_H
#define TELLER_H
#include"Customer.h"
#include<iostream>

class Teller
{
     bool isAvailable;
     int servingTime;
     int totalServedCustomer;
    public:

        Teller() {
            isAvailable =true;
            servingTime=0;
            totalServedCustomer=0;
        }
        bool getIsAvailble(){
            return isAvailable;
        }
        void setServingTime(int servTime){
            servingTime=servTime;
        }
        int getSrvingTime(){
            return servingTime;

        }

        int getTotalServedCustomer(){
            return totalServedCustomer;
        }




        void servedCustomer(Customer&c, int tellerId){
            isAvailable=false;
           c.setLeavingTime(c.getArrivalTime()+c.getServiceTime()+c.getWaitingTime());
          std::cout <<" Teller ID: " << (tellerId +1)<< "    Customer Id: " << c.getID() << "     Arrival Time: " << c.getArrivalTime() <<"     service Time: " << c.getServiceTime() << "     waiting Time:  " << c.getWaitingTime() << "     Leaving Time :" << c.getLivingTime() <<  std::endl;
            totalServedCustomer++;

        }


    protected:

    private:
};

#endif // TELLER_H
