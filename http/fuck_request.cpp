//
// Created by Allen on 17-12-18.
//

#include <iostream>
#include "fuck_request.h"
#include "string"
FuckRequest::FuckRequest(const char *rawRequest) {
    std::string  *request = new std::string(rawRequest,sizeof(char)*50);
    std::cout<<request[0]<<std::endl;
    int index = request[0].find("\\r\\n\\r\\n");
    std::cout<<index<<std::endl;

}