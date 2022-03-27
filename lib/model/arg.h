#ifndef PP_MODEL_ARG_H
#define PP_MODEL_ARG_H

#include "model/type.h"

typedef struct {
    char *name;
    pp_type_t primitive_type;
    char is_const;
    char is_ref;
    char is_arr;
} pp_arg_t;

#endif
