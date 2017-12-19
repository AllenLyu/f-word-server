//
// Created by Allen on 17-12-18.
//

#ifndef F_WORD_SERVER_FUCK_REQUEST_H
#define F_WORD_SERVER_FUCK_REQUEST_H

#include "string"
class FuckRequest{
public:
    std::string method;
    std::string version;
    std::string location;
    FuckRequest(const char* rawRequest);

private:

};


#endif //F_WORD_SERVER_FUCK_REQUEST_H
