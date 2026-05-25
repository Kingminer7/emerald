#pragma once

#include <Geode/utils/string.hpp>
#include <Geode/loader/Setting.hpp>
#include <Geode/loader/Mod.hpp>

template <geode::utils::string::ConstexprString S, typename T>
T const& getSettingFast() {
    static T value = (
        geode::listenForSettingChanges<T>(S.data(), [](T val) {
            value = std::move(val);
        }),
        geode::getMod()->getSettingValue<T>(S.data())
    );
    return value;
}