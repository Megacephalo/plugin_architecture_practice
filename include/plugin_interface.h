#ifndef _PLUGIN_INTERFACE_H_
#define _PLUGIN_INTERFACE_H_

#include <memory>
#include <functional>

class PluginInterface {
public:
    virtual ~PluginInterface() {}
    virtual void run() = 0;
};

extern "C" {
    // typedef std::unique_ptr<PluginInterface> (*createPlugin_t)();
    using createPlugin_t = std::unique_ptr<PluginInterface> (*)();
}

#endif /* _PLUGIN_INTERFACE_H_ */