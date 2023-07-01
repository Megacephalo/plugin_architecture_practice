#ifndef _PLUGIN_2_H_
#define _PLUGIN_2_H_

#include <iostream>

#include "plugin_interface.h"

class Plugin2 : public PluginInterface {
  public:
    Plugin2() = default;
    void run() override;

};

extern "C" {
    std::unique_ptr<PluginInterface> createPlugin() {
        return std::make_unique<Plugin2>();
    }
}

#endif /* _PLUGIN_2_H_ */