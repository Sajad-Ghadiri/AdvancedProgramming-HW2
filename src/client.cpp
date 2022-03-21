#include "client.h"
#include "server.h"

std::string Client::get_id() const
{
    return id;
}
Client::Client(std::string _id, const Server &_server) : id {_id} ,  server{&_server}  

{
    std::cout << "client constructor called " << std::endl;
    crypto::generate_key(public_key, private_key);  
}

double Client::get_wallet() const
{
    return server->get_wallet(this->get_id());
}

std::string Client::sign(std::string txt) const
{
    return crypto::signMessage( private_key ,  txt) ;
}

bool transfer_money(std::string receiver, double value) const
{

}