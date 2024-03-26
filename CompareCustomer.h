#ifndef COMPARECUSTOMER_H
#define COMPARECUSTOMER_H

struct CompareCustomer
{
   bool operator()(const Customer& c1, const Customer& c2) const {
        return c1.getArrivalTime() > c2.getArrivalTime();
    }
};

#endif // COMPARECUSTOMER_H
