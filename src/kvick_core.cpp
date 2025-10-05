#include "kvick_core.h"
#include<iostream>

namespace kv {
    std::string get_version() {
        return "KVick v0.1";
    }
}

KVickCore::KVickCore() {
    // You can initialize data structures here if needed
}

bool KVickCore::set(const std::string& key, const std::string& value) {

    store_[key] = value;
    return true;
}

std::string KVickCore::get(const std::string& key) const {
    auto it = store_.find(key);
    if (it != store_.end())
        return it->second;
    return "Not found";
}

bool KVickCore::del(const std::string& key) {
    if (store_.find(key) == store_.end()) {
        std::cout<<"Key not found";
        return false;
    }

    store_.erase(key);
    return true;
}

size_t KVickCore::size() const {
    return store_.size();
}
