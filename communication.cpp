#include "communication.h"

Communication::Communication()
{
}

void Communication::data_manager()
{
    while (true)
    {
        std::string operation;
        std::cout << "Operation type (Insert, update, show information, delete or exit): ";
        // std::cin >> operation;
        std::getline(std::cin, operation);
        if (operation == "Insert")
        {
            int id;
            std::cout << "Enter ID: ";
            std::cin >> id;
            
            std::cout << "Enter product name: ";
            std::cin >> Product_name;

            std::cout << "Enter product type: ";
            std::cin >> Product_type;

            std::cout << "Enter quantity: ";
            std::cin >> Quantity;

            std::cout << "Information: ";

            db.insert_newdata(id, Product_name, Product_type, Quantity);
        }
        
        else if (operation == "update")
        {
            int id;
            std::cout << "Enter ID: ";
            std::cin >> id;
             
            std::string field;
            std::cout << "Enter field to update (product name, product type, quantity): ";
            std::cin >> field;

            if (field == "product name")
            {
                std::cout << "Enter new product name: ";
                std::cin >> Product_name;
                db.update_data(id, Product_name, "", 0);
            }
            
            else if (field == "product type")
            {
                std::cout << "Enter new product type: ";
                std::cin >> Product_type;
                db.update_data(id, Product_type, "", 0);
            }
            
            else if (field == "quantity")
            {
                std::cout << "Enter new quantity: ";
                std::cin >> Quantity;
                db.update_data(id, "", "", Quantity);
            }
            
            else
            {
                std::cout << "Invalid field, try again." << std::endl;
            }

        }

        else if (operation == "show information")
        {
            std::cout << "Information: ";
            db.show_information();
        }
        
        else if (operation == "delete")
        {
            int id;
            std::cout << "Enter ID; ";
            std::cin >> id;

            db.delete_data(id);
        }
        
        else if(operation == "exit")
        {
            break;
        }
        else
        {
            std::cout << "Invalid operation, try again." << std::endl;
        }
    }
}
