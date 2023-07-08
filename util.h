#include <jsonrpccpp/client.h>
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <json/json.h>
#include <iostream>
#include <jsonrpccpp/common/exception.h>

int getBlockNumber(jsonrpc::HttpClient client){

    std::string result;
    client.SendRPCMessage("{\"method\":\"eth_blockNumber\",\"params\":[],\"id\":1,\"jsonrpc\":\"2.0\"}", result);

    Json::Reader reader;
    Json::Value root;

    reader.parse(result, root);

    return std::stoi(root["result"].asString(), nullptr, 16);
}

uint64_t getBalance(jsonrpc::HttpClient client, std::string address){
    std::string result;

    std::string message = "{\"method\":\"eth_getBalance\",\"params\":[\""+ address + "\", \"latest\"],\"id\":1,\"jsonrpc\":\"2.0\"}";
    client.SendRPCMessage(message,result);

    Json::Reader reader;
    Json::Value root;

    reader.parse(result, root);

    uint64_t balance = std::strtoull(root["result"].asCString(), nullptr, 16);

    return balance;
}

int getBlockNumber(jsonrpc::Client client){
    Json::Value params;

    Json::Value response = client.CallMethod("eth_blockNumber", params);

    if (!response.isNull() && response.isString()) {
        return std::stoi(response.asString(), nullptr, 16);
    }

    return 0;

}

uint64_t getBalance(jsonrpc::Client client, std::string address){
    Json::Value params;
    params.append(address);
    params.append("latest");

    Json::Value response = client.CallMethod("eth_getBalance", params);

    if (!response.isNull() && response.isString()) {
            return std::strtoull(response.asCString(), nullptr, 16);
    }

    return 0;
}
