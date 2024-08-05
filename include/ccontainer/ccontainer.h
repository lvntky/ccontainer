#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Reports the name of the library
 */
char const *header_only_name(void);

#ifdef CCONTAINER_IMPLEMENTATION

char const *header_only_name(void)
{
	return "ccontainer";
}

#endif

#ifdef __cplusplus
} // extern "C"
#endif
