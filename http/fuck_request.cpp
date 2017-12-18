//
// Created by Allen on 17-12-18.
//

#include <iostream>
#include "fuck_request.h"
#include "string"
FuckRequest::FuckRequest(char *rawRequest) {
    std::string *request = new std::string(rawRequest);
    std::cout<<request<<std::endl;
}