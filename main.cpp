#include"Bank.h"
#include <iostream>
#include <fstream>

using namespace std;



int main()
{

   fstream infoCustomerFile("infoCustomer.txt");
    Bank bank;
    int id;
    int arrivalTime;
    int serviceTime;
    while (infoCustomerFile >> id >> arrivalTime >> serviceTime) {
        bank.addCustomer(id, arrivalTime, serviceTime);
    }
    infoCustomerFile.close();

    bank.simulateBank();
    cout<<endl;

    cout << "Average waiting time: " << bank.getAvargeWaitingTime() << endl;
    cout << "Average service time: " << bank.getAvargeServiceTime() << endl<<endl;
    for(int i=0; i<3; i++){
        cout<< "Utilization rate for teller " << i+1<< ":" << bank.getUtilizationRate(i)<<"%" <<endl;
    }

    return 0;

}
