#pragma once

#include <string>

#include "common.hpp"

#undef PROTOBUF_DEPRECATED
#define PROTOBUF_DEPRECATED __attribute__((deprecated))
#include "config.pb.h"
#undef PROTOBUF_DEPRECATED

class TConfig : public TNonCopyable {
    cfg::TCfg Cfg;

    const std::vector<std::string> ConfigFiles = { "/etc/portod.conf", "/etc/default/portod.conf" };

    void LoadDefaults();
    bool LoadFile(const std::string &path, bool silent);
public:
    TConfig() {}
    void Load(bool silent = false);
    int Test(const std::string &path);
    cfg::TCfg &operator()();
};

extern TConfig config;
