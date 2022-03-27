#include "parse/arg.h"

#include <stdlib.h>
#include <string.h>

#include <stdio.h>

pp_arg_t * pp_parse_arg_from_pawn(const char * source) {
    pp_arg_t *arg = (pp_arg_t *) malloc(sizeof (pp_arg_t));

    const char is_const = strncmp(source, "const ", 6) == 0;
    const char *and_pos_ptr = strchr(source, '&');
    const char *colon_pos_ptr = strchr(source, ':');
	const char *bracket_pos_ptr = strchr(source, '[');
    const char *equals_pos_ptr = strchr(source, '=');

    if (colon_pos_ptr != NULL) {
        const unsigned pt_str_begin = (is_const * 6) + (and_pos_ptr != NULL);
        const unsigned pt_str_end = colon_pos_ptr - source;
        const unsigned pt_str_len = pt_str_end - pt_str_begin;

        char *primitive_type_str = (char *) malloc((pt_str_len + 1) * (sizeof (char)));
        strncpy(primitive_type_str, source + pt_str_begin, pt_str_len);
        primitive_type_str[pt_str_len] = '\0';

        if (strncmp(primitive_type_str, "bool", 4) == 0) {
            arg->primitive_type = PP_TYPE_BOOL;
        } else if (strncmp(primitive_type_str, "Float", 5) == 0) {
            arg->primitive_type = PP_TYPE_FLOAT;
        } else {
            arg->primitive_type = PP_TYPE_INT;
        }
    } else {
        arg->primitive_type = PP_TYPE_INT;
    }

    const unsigned name_str_begin =
        (colon_pos_ptr != NULL)
            ? (colon_pos_ptr - source + 1)
            : ((is_const * 6) + (and_pos_ptr != NULL));

    const unsigned name_str_end =
        (bracket_pos_ptr != NULL)
            ? (bracket_pos_ptr - source)
            : (equals_pos_ptr != NULL ? equals_pos_ptr - source : strlen(source));

    const unsigned name_len = name_str_end - name_str_begin;
    arg->name = (char *) malloc((name_len + 1) * (sizeof (char)));
    strncpy(arg->name, source + name_str_begin, name_len);
    arg->name[name_len] = '\0';

    arg->is_const = is_const;
    arg->is_ref = and_pos_ptr != NULL;
    arg->is_arr = bracket_pos_ptr != NULL;

    return arg;
}
