#ifndef CUSTOMER_H
#define CUSTOMER_H


class Customer
{

    int id;
    int arrivalTime;
    int serviceTime;
    int waitingTime;
    int leavingTime;


    public:
        Customer(int ID, int arriveTime, int servTime) {
            id= ID;
            arrivalTime=arriveTime;
            serviceTime=servTime;
            waitingTime=0;
            leavingTime=arriveTime+serviceTime;

        }

        void setWaitingTime( int time){
            waitingTime=time;
        }
        void setLeavingTime(int leaveTime){
            leavingTime=leaveTime;
        }

        int getWaitingTime() const{
            return waitingTime;
        }
        int getLivingTime() const{
            return leavingTime;

        }

        int getArrivalTime() const{
            return arrivalTime;
        }
        int getServiceTime() const{
            return serviceTime;
        }
        int getID() const{
            return id;
        }





    protected:

    private:
};

#endif // CUSTOMER_H
