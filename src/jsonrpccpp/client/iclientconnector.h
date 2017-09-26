/*************************************************************************
 * libjson-rpc-cpp
 *************************************************************************
 * @file    iclientconnector.h
 * @date    02.01.2013
 * @author  Peter Spiess-Knafl <dev@spiessknafl.at>
 * @license See attached LICENSE.txt
 ************************************************************************/

#ifndef JSONRPC_CPP_ICLIENTCONNECTOR_H_
#define JSONRPC_CPP_ICLIENTCONNECTOR_H_

#include <string>
#include <jsonrpccpp/common/exception.h>

namespace jsonrpc
{
    class Client;
    typedef void (*asyncCallback)(std::string& uuid, Json::Value& result, void * data);

    class IClientConnector
    {
        public:
            virtual ~IClientConnector(){}

            virtual void SendRPCMessage(const std::string& message, std::string& result)  = 0;
            virtual void SendAsyncRPCMessage(const std::string& message, Client * client,
                                             asyncCallback callback, void * data) {
                throw JsonRpcException(Errors::ERROR_CLIENT_CONNECTOR,
                                       "Async not implemented.");
            }
    };
} /* namespace jsonrpc */
#endif /* JSONRPC_CPP_ICLIENTCONNECTOR_H_ */
