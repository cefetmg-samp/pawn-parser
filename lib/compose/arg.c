#include "compose/arg.h"

#include <stdlib.h>
#include <string.h>

char * pp_compose_arg_to_c(const pp_arg_t * arg) {
    char *composed_arg;

	const unsigned arg_name_len = strlen(arg->name);

    const unsigned composed_arg_len =
		(1)
			+ (arg->is_const * 6)
            + (arg->primitive_type + 4)
            + (arg->is_ref * 2)
            + (arg_name_len)
			+ (arg->is_arr * 2);

	composed_arg = (char *) malloc(composed_arg_len * (sizeof (char)));
	
	unsigned composed_arg_filled_len = 0;
	
	if (arg->is_const) {
		strncpy(composed_arg + composed_arg_filled_len, "const ", 6);
		composed_arg_filled_len += 6;
	}

	if (arg->primitive_type == PP_TYPE_BOOL) {
		strncpy(composed_arg + composed_arg_filled_len, "bool ", 5);
		composed_arg_filled_len += 5;
	} else if (arg->primitive_type == PP_TYPE_FLOAT) {
		strncpy(composed_arg + composed_arg_filled_len, "float ", 6);
		composed_arg_filled_len += 6;
	} else {
		strncpy(composed_arg + composed_arg_filled_len, "int ", 4);
		composed_arg_filled_len += 4;
	}
	
	if (arg->is_ref) {
		strncpy(composed_arg + composed_arg_filled_len, "* ", 2);
		composed_arg_filled_len += 2;
	}

	strncpy(composed_arg + composed_arg_filled_len, arg->name, arg_name_len);
	composed_arg_filled_len += arg_name_len;
	
	if (arg->is_arr) {
		strncpy(composed_arg + composed_arg_filled_len, "[]", 2);
		composed_arg_filled_len += 2;
	}

	composed_arg[composed_arg_filled_len] = '\0';

    return composed_arg;
}
