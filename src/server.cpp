#include "server.h"
#include "client.h"

Server::Server()
{
}

std::shared_ptr<Client> Server::add_client(std::string _id)
{
    

    if (get_client(_id) != nullptr) // chera khode ID error migire ?!
    {

        std::random_device rand;
        std::default_random_engine generator{rand()};
        std::uniform_real_distribution<double> mydist(1000, 9999);
        std::shared_ptr<Client> new_client{std::make_shared<Client>(_id + std::to_string(static_cast<size_t>(mydist(generator))), *this)};
        clients.insert({new_client, 5});
        return new_client ;
    }
    else
    {
        std::shared_ptr<Client> new_client{std::make_shared<Client>(_id, *this)};
        clients.insert({new_client , 5});
        return new_client;

    }

}

std::shared_ptr<Client> Server::get_client(std::string _id) const
{
    for (auto iter{clients.begin()}; iter != clients.end(); iter++)
        if (iter->first->get_id() == _id)
            return iter->first;

    return nullptr;
}


double Server::get_wallet( std::string _id ) const
{
    // return clients[get_client(_id)];

    for ( auto iter{clients.begin()}; iter != clients.end(); iter++ )
        if ( iter->first->get_id() == _id )
            return iter->second;

    return 0.0 ;
    /// return static_cast<double>(nullptr) ;   /////////////////// ????????????
}


bool Server::parse_trx(std::string trx, std::string& sender, std::string& receiver, double& value)
{
    
    size_t i{};
    int cnt{};
    size_t first_dash{trx.find('-',i)} ;
    size_t second_dash{trx.find('-',first_dash + 1)} ;
    sender = trx.substr(i,first_dash);
    ++cnt ;
    receiver = trx.substr(first_dash +1 , second_dash );
    ++cnt ;
    value = std::stod(trx.substr(second_dash + 1 )) ;
    ++cnt ;
     

    if(cnt != 3)
         throw std::runtime_error("runtime error occured !!!");

    return true ;
}


/*
bool Server::add_pending_trx(std::string trx, std::string signature)
{
    return true;
}
*/