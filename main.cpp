//
// Created by Kemba Konteh on 3/5/20.
//


#include "Business.h"

int main()
{
    // Cretae the business with movies inventory and customers
    Business inventory("data4movies.txt", "data4customers.txt");

    // Process the list of transactions on the business
    inventory.processTransaction("data4commands.txt");

    return 0;
}
