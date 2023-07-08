#include <iostream>
#include "util.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main(){
    jsonrpc::HttpClient httpClient("https://fabled-powerful-pool.ethereum-sepolia.discover.quiknode.pro/3cff8f783686f29bfd97b23cb88ff4792aab8077/");
       
    //std::cout << "Latest Block Number : " << getBlockNumber(httpClient) << std::endl;
    //uint64_t balance = getBalance(httpClient, "0x6a7aA9b882d50Bb7bc5Da1a244719C99f12F06a3");

    //std::cout << "Balance of Address 0x6a7aA9b882d50Bb7bc5Da1a244719C99f12F06a3: " << balance << std::endl; 

    jsonrpc::Client client(httpClient);

    std::cout << getBalance(client, "0x6a7aA9b882d50Bb7bc5Da1a244719C99f12F06a3") << std::endl;
    std:: cout << getBlockNumber(client) << std::endl;

    return 0;
    
}