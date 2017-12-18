//
// Created by Allen on 17-12-14.
//

#include <stdlib.h>
#include <memory.h>
#include "f_word_request.h"

f_word_request_t* get_request(char *request){
    f_word_request_t *result = malloc(sizeof(f_word_request_t));
    char delim[] = "\\r\\n";
    char *res = NULL;

    result->location = res;
}