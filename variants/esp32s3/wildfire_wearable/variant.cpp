// Factory defaults from node_config/main_node_config.yaml in the parent repo.
// wildfire_node_config.h is generated at build time by gen_node_config.py.
// These hooks run only when the board has no saved settings (first boot after
// an erase, or a factory reset); saved settings are never overridden.

#include "configuration.h"
#include "wildfire_node_config.h"

void variantDefaultConfig()
{
    LOG_INFO("Install Wildfire defaults from %s", WILDFIRE_NODE_CONFIG_SOURCE);
    wildfireDefaultConfig();
}

void variantDefaultModuleConfig()
{
    wildfireDefaultModuleConfig();
}

void variantDefaultChannels()
{
    wildfireDefaultChannels();
}
