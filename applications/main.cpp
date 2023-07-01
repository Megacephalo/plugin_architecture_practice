#include <iostream>
#include <string>
#include <memory>
#include <filesystem>
#include <thread>
#include <vector>
#include <dlfcn.h>
#include <functional>

#include "plugin_interface.h"
#include "plugin_1/plugin_1.h"

std::unique_ptr<PluginInterface> loadPlugin(const std::string& pluginLib) {
    void* handle = dlopen(pluginLib.c_str(), RTLD_LAZY);
    if (handle == nullptr) {
        std::cerr << "Error loading plugin: " << dlerror() << std::endl;
        return nullptr;
    }

    dlerror();  // Clear any existing error

    createPlugin_t pluginFunc = (createPlugin_t) dlsym(handle, "createPlugin");

    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol createPlugin: " << dlsym_error << std::endl;
        dlclose(handle);
        return nullptr;
    }

    return pluginFunc();
}

int main(int argc, char** argv) {
    std::cout << "Launchin Plugin Architecture practice" << std::endl;

    // Read all .so files under the given directory and Load all plugins (run every one of them)
    std::string pluginDir = "/home/charly/Public/plugin_architecture_practice/lib";
    std::vector<std::thread> loadPluginThreads;
    for (const auto & entry : std::filesystem::directory_iterator(pluginDir)) {
        if (entry.path().extension() != ".so") continue;

        std::unique_ptr<PluginInterface> plugin = loadPlugin(entry.path().string());
        if (plugin == nullptr) {
            std::cerr << "Error loading plugin from " << entry.path().string() << std::endl;
            continue;
        }

        // Push the function object of to load the plugin
        std::cout << "Loading a plugin from " << entry.path().string() << std::endl;
        loadPluginThreads.emplace_back(std::thread([plugin = std::move(plugin)]() {
            plugin->run();
        }));
    }

    dlerror();  // Clear any existing error

    for (auto& thread : loadPluginThreads) {
        std::cout << "Joining thread" << std::endl;
        if (thread.joinable()) thread.join();
    }

    return EXIT_SUCCESS;
}