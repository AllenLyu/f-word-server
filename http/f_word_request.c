//
// Created by Allen on 17-12-14.
//

#include <stdlib.h>
#include "f_word_request.h"

f_word_request_t* get_request(const char *request){
    f_word_request_t *result = malloc(sizeof(f_word_request_t));
    char delim[] = "\\r\\n";
    char *res = NULL;
    result->location = "1.html";
    return result;
}