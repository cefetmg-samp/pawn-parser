#ifndef PP_MODEL_FUNCTION_H
#define PP_MODEL_FUNCTION_H

#include "model/arg.h"
#include "model/type.h"

typedef struct {
    char *name;
    pp_arg_t *args;
    pp_type_t type;
} pp_function_t;

#endif
