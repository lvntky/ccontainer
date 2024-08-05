#include "ccontainer/ccontainer.h"

#include <string.h>

int main(int argc, char const* argv[])
{
  (void)argc;
  (void)argv;

  return strcmp(header_only_name(), "ccontainer") == 0 ? 0 : 1;
}
