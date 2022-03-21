
#include <iostream>
#include <gtest/gtest.h>
#include "client.h"
#include "server.h"


int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {

        // debug section
        ///////////////////// testing server's methods  /////////////////
        Server my_server;
        auto sajad{my_server.add_client("sajadgh")};
        std::cout << "client id is = " << sajad->get_id() << "and public key is: \n "<< sajad->get_publickey() << std::endl;
        
        std::cout << my_server.get_client("sajadgh")->get_id() << std::endl;

        //std::cout << my_server.get_wallet("sajadgh") + 1 << std::endl;

        ///////////////////// testing client's methods /////////////////
        std::string sender{};
        std::string receiver{};
        double money{};

        //std::cout << sajad ->get_wallet() << std::endl ;

        my_server.parse_trx("mmd-sajad-10" , sender , receiver , money);
        std::cout << "sender is :" << sender <<std::endl;
        std::cout << "receiver is :" << receiver <<std::endl;
        std::cout << "money transfered equal to =" << money <<std::endl;


        ////////////////////////////////////////////////////////////////
        
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}