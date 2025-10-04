#include "nredis_core.h"
#include<iostream>

namespace kv {
    std::string get_version() {
        return "NotRedis v0.1";
    }
}

NRedisCore::NRedisCore() {
    // You can initialize data structures here if needed
}

bool NRedisCore::set(const std::string& key, const std::string& value) {

    store_[key] = value;
    return true;
}

std::string NRedisCore::get(const std::string& key) const {
    auto it = store_.find(key);
    if (it != store_.end())
        return it->second;
    return "Not found";
}

bool NRedisCore::del(const std::string& key) {
    if (store_.find(key) == store_.end()) {
        std::cout<<"Key not found";
        return false;
    }

    store_.erase(key);
    return true;
}

size_t NRedisCore::size() const {
    return store_.size();
}
