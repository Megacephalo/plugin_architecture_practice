#ifndef _PLUGIN_1_H_
#define _PLUGIN_1_H_

#include <iostream>

#include "plugin_interface.h"

class Plugin1 : public PluginInterface {
  public:
    Plugin1() = default;
    void run() override;

};

extern "C" {
    std::unique_ptr<PluginInterface> createPlugin() {
        return std::make_unique<Plugin1>();
    }
}

#endif /* _PLUGIN_1_H_ */