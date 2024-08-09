#pragma once
#ifndef CCONTAINER_UTILS_H__
#define CCONTAINER_UTILS_H__

#include <stdio.h>

#define CCONTAINER_LOG(format, ...)                                      \
	do {                                                             \
		char buffer[256];                                        \
		snprintf(buffer, sizeof(buffer), format, ##__VA_ARGS__); \
		fprintf(stderr, "[CCONTAINER_H ERROR] - %s\n", buffer);  \
	} while (0)

#endif //CCONTAINER_UTILS_H__