//
// Created by Allen on 17-12-11.
//

#ifndef F_WORD_SERVER_F_WORD_REQUEST_H
#define F_WORD_SERVER_F_WORD_REQUEST_H

struct f_word_request_s{
    char* location;
    char* method;
    double version;


};

typedef struct f_word_request_s f_word_request_t;


f_word_request_t* get_request( char *request);
#endif //F_WORD_SERVER_F_WORD_REQUEST_H
